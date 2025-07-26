#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
void makelzy(int tot, size_t x);
void downlzy(int tot);
void update(int tot, int le, int ri, size_t x, int LL, int RR);
size_t query(int index, int tot, int LL, int RR);
struct SegNode
{
    int L;
    int R;
    int val;
    size_t lzy;
};
vector<SegNode> segtree;

void makelzy(int tot, size_t x)
{
    segtree[tot].lzy ^= x;
}

void downlzy(int tot)
{
    makelzy(tot * 2, segtree[tot].lzy);
    makelzy(tot * 2 + 1, segtree[tot].lzy);
    segtree[tot].lzy = 0;
}

size_t query(int index, int tot, int LL, int RR)
{
    int mid = (LL + RR) / 2;

    if (LL == RR)
    {
        return segtree[tot].lzy;
    }
    if (segtree[tot].lzy != 0)
    {
        downlzy(tot);
    }
    if (index <= mid)
    {
        return query(index, tot * 2, LL, mid);
    }
    else
    {
        return query(index, tot * 2 + 1, mid + 1, RR);
    }
}
void update(int tot, int le, int ri, size_t x, int LL, int RR)
{
    int mid = (LL + RR) / 2;
    if (le <= LL && ri >= RR)
    {
        makelzy(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        if (segtree[tot].lzy != 0)
        {
            downlzy(tot);
        }
        update(tot * 2, le, ri, x, LL, mid);
        update(tot * 2 + 1, le, ri, x, mid + 1, RR);
        return;
    }
}

void INITSegTree(int arrsize)
{
    segtree = vector<SegNode>(4 * arrsize + 10);
}
// segtree----------------------------------------------------------------------

void solve()
{
    int n;
    cin >> n;
    allnum = set<int>();
    id_num = map<int, int>();
    num_id = map<int, int>();
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
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

    INITSegTree(cnt + 1);
    for (int i = 1; i <= n; i++)
    {
        size_t nownum = rnd();
        int nowl = num_id[arr[i].l], nowr = num_id[arr[i].r];
        update(1, nowl, nowr, nownum, 0, cnt);
    }

    set<size_t> mp;
    int ans = 0;
    for (int i = 0; i <= cnt; i++)
    {
        size_t x = query(i, 1, 0, cnt);
        // cout << "!" << x << endl;
        mp.insert(x);
    }

    cout << mp.size() << endl;
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
