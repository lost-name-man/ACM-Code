#include <cstddef>
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
#define int size_t
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 2e9 + 7;
const int MOD = 1e17 + 7;
struct Inval
{
    int l;
    int r;

    bool operator<(const Inval& other) const
    {
        if (this->r == other.r)
        {
            return this->l < other.l;
        }
        return this->r < other.r;
    }
};

set<pair<int, size_t>> allnum;

// segtree-------------------------------------------------------------
void makelzy(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int tot, int le, int ri);
struct SegNode
{
    int L;
    int R;
    int val;
    int lzy;
};
vector<SegNode> segtree;
vector<int> arrline;
int segtot;
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

int query(int tot, int le, int ri)
{
    int LL = segtree[tot].L, RR = segtree[tot].R;
    if (le <= LL && ri >= RR)
    {
        return segtree[tot].lzy;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        downlzy(tot);
        int tmp;

        if (le <= m)
        {
            return query(tot * 2, le, ri);
        }
        else
        {
            return query(tot * 2 + 1, le, ri);
        }
    }
    else
        return 0;
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
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
}

void INITSegTree(int arrsize)
{

    segtree = vector<SegNode>(4 * arrsize + 10);
    segtot = 1;
    build(segtot, 1, arrsize);
}
// segtree----------------------------------------------------------------------

void solve()
{
    int n;
    cin >> n;
    allnum = set<pair<int, size_t>>();

    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    vector<Inval> arr(n + 5);
    INITSegTree(n*2);
    unordered_map<int, int> arr_ds;


    for (int i = 1; i <= n; i++)
    {

        cin >> arr[i].l >> arr[i].r;
        arr_ds[arr[i].l] = 1;
        arr_ds[arr[i].r] = 1;
    }

    map<int, int>ds_arr;
    int cnt = 0;
    {

        for (auto iter = arr_ds.begin(); iter != arr_ds.end(); iter++)
        {
            cnt++;
            ds_arr[cnt] = iter->first;
            iter->second = cnt;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        size_t tmp = rnd();
        cout << "@" << tmp << endl;
        int ds_l = arr_ds[arr[i].l], ds_r = arr_ds[arr[i].r];
        update(1, ds_l, ds_r, tmp);

    }

    set<size_t>s;
    s.insert(-1);
    for (int i = 1; i <= cnt; i++)
    {
        size_t tmp = query(1, i, i);

        cout << "!" << tmp << endl;

        s.insert(tmp);
    }




    cout << s.size() << endl;
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
