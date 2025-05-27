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

// #define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;
const int N = 100000;
const int V = N * 20;
struct Node
{
    int id;
    int l = 0;
    int r = 0;
    int sum = 0;
};
int n, q;
int root[V];
Node node[30 * V];
int tot = 1;
int vtot = 0;

int update(int lastid, int l, int r, int x)
{
    tot++;
    int nowid = tot;
    node[nowid].l = node[lastid].l, node[nowid].r = node[lastid].r;
    node[nowid].sum = node[lastid].sum + 1;
    if (l < r)
    {
        int mid = (l + r) / 2;
        if (x <= mid)
        {
            node[nowid].l = update(node[nowid].l, l, mid, x);
        }
        else
        {
            node[nowid].r = update(node[nowid].r, mid + 1, r, x);
        }
    }
    return nowid;
}

int query(int lastid, int nowid, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int rsum = node[node[nowid].r].sum - node[node[lastid].r].sum;
    int mid = (l + r) / 2;
    if (rsum >= k)
    {
        return query(node[lastid].r, node[nowid].r, mid + 1, r, k);
    }
    else
    {
        return query(node[lastid].l, node[nowid].l, l, mid, k - rsum);
    }
}
void solve()
{
    cin >> n >> q;
    root[0] = tot;
    int delta = 19;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= 19; j++)
        {
            root[i * delta + j] = update(root[i * delta + j - 1], 0, N, x);
            x /= 2;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        int ans = query(root[l * delta], root[(r + 1) * delta], 0, N, k + 1);
        cout << ans << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}