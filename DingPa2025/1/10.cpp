#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;

const int V = 2000;
struct Node
{
    int id;
    int l = 0;
    int r = 0;
    int sum = 0;
};
int n;
int root[V + 10];
Node node[30 * (V + 10)];
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
int arr[2003];
void solve()
{
    memset(root, 0, sizeof(root));
    memset(node, 0, sizeof(node));
    cin >> n;
    tot = 1;
    vtot = 0;
    root[0] = tot;

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
        root[i] = update(root[i - 1], 1, n, num);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j += 2)
        {
            int k = (j + 1) / 2;
            if (i + j - 1 > n)
            {
                continue;
            }
            ans += i * (i + j - 1) * query(root[i - 1], root[i + j - 1], 1, n, k);
        }
    }
    cout << ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}