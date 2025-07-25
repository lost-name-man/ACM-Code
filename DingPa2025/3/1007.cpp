#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;

struct Inval
{
    int l;
    int r;

    bool operator<(const Inval &other) const
    {
        if (this->r == other.r)
        {
            return this->l < other.l;
        }
        return this->r < other.r;
    }
};

set<int> allnum;
map<int, int> id_num;
map<int, int> num_id;

// segtree-------------------------------------------------------------
void makelzy(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int le, int ri, int tot);
struct SegNode
{
    int L;
    int R;
    int val;
    int lzy;
};
vector<SegNode> segtree;

void makelzy(int tot, int x)
{
    int len = segtree[tot].R - segtree[tot].L + 1;
    segtree[tot].lzy ^= x;
}

void downlzy(int tot)
{
    int m = (segtree[tot].L + segtree[tot].R) / 2;
    makelzy(tot * 2, segtree[tot].lzy);
    makelzy(tot * 2 + 1, segtree[tot].lzy);
    segtree[tot].lzy = 0;
}

int query(int index, int tot = 1)
{
    int LL = segtree[tot].L, RR = segtree[tot].R;
    int mid = (LL + RR) / 2;
    if (LL == RR)
    {
        return segtree[tot].lzy;
    }
    else if (index <= mid)
    {
        downlzy(tot * 2);
        query(index, tot * 2);
    }
    else
    {
        downlzy(tot * 2 + 1);
        query(index, tot * 2 + 1);
    }
}
void update(int tot, int le, int ri, int x)
{
    int LL = segtree[tot].L, RR = segtree[tot].R;
    if (le <= LL && ri >= RR)
    {
        makelzy(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        downlzy(tot);
        update(tot * 2, le, ri, x);
        update(tot * 2 + 1, le, ri, x);
        return;
    }
}
void build(int tot, int LL, int RR)
{
    segtree[tot].L = LL;
    segtree[tot].R = RR;
    segtree[tot].lzy = 0;

    if (LL == RR)
    {
        segtree[tot].val = 0;
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
}

void INITSegTree(int arrsize)
{
    segtree = vector<SegNode>(4 * arrsize + 10);
    build(1, 1, arrsize);
}
// segtree----------------------------------------------------------------------

void solve()
{
    int n;
    cin >> n;
    vector<Inval> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].l >> arr[i].r;
        allnum.insert(arr[i].l);
        allnum.insert(arr[i].r);
    }

    int cnt = 0;
    for (auto it = allnum.begin(); it != allnum.end(); it++)
    {
        cnt++;
        id_num[cnt] = *it;
        num_id[*it] = cnt;
    }

    map<int, int> mp;
    set<int> st;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int nowl = arr[i].l, nowr = arr[i].r;
        if (nowl == arr[i - 1].l && nowr == arr[i - 1].r)
        {
            continue;
        }
        int okl = 0;
        if (mp[nowr] == 0)
        {
            okl = 1;
            ans++;
        }
        auto it = st.lower_bound(nowl);
        int nextl;
        if (it == st.end())
        {
            mp[nowl] = 1;
            if (mp[nowr] != 1)
            {
                mp[nowr] = 2;
            }
            st.insert(nowl);
            st.insert(nowr);

            continue;
        }
        else
        {
            nextl = *it;
            if (okl == 0)
            {
                ans++;
            }
            else if (mp[nextl] == 2)
            {
                ans++;
            }
        }
        mp[nowl] = 1;
        if (mp[nowr] != 1)
        {
            mp[nowr] = 2;
        }
        st.insert(nowl);
        st.insert(nowr);
    }
    ans++;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
