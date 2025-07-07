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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;
const int N = 200000;
int deep[N + 10] = {0};
int exdeep[N + 10] = {0};
int f[N + 10][20] = {0};
int len[2 * N + 10];
vector<int> tree[N + 10];

int n;
int r, t0;
int maxt;
void init()
{
    queue<int> q;
    q.push(r);
    deep[r] = 1;
    exdeep[1] = 1;
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();

        for (int i = 0; i < tree[nownode].size(); i++)
        {
            int nextnode = tree[nownode][i];
            if (deep[nextnode])
            {
                continue;
            }
            deep[nextnode] = deep[nownode] + 1;
            exdeep[deep[nextnode]] = 1;
            f[nextnode][0] = nownode;
            for (int j = 1; j <= 19; j++)
            {
                f[nextnode][j] = f[f[nextnode][j - 1]][j - 1];
            }
            q.push(nextnode);
        }
    }
}

int lca(int x, int y)
{

    if (deep[x] > deep[y])
    {
        swap(x, y);
    }
    for (int i = 19; i >= 0; i--)
    {
        if (deep[f[y][i]] >= deep[x])
        {
            y = f[y][i];
        }
    }
    if (x == y)
    {
        return x;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

///
int vis[N + 10] = {0};
void l_of_tree()
{
    queue<int> q;
    q.push(r);
    vis[r] = 1;
    int u = r, v = r;
    int maxlen = 0;
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();

        for (int i = 0; i < tree[nownode].size(); i++)
        {
            int nextnode = tree[nownode][i];
            if (vis[nextnode])
            {
                continue;
            }
            vis[nextnode] = 1;
            int fa;
            fa = lca(u, nextnode);
            if (deep[u] + deep[nextnode] - deep[fa] * 2 > maxlen)
            {
                maxlen = deep[u] + deep[nextnode] - deep[fa] * 2;
                v = nextnode;
            }
            fa = lca(v, nextnode);
            if (deep[v] + deep[nextnode] - deep[fa] * 2 > maxlen)
            {
                maxlen = deep[v] + deep[nextnode] - deep[fa] * 2;
                u = nextnode;
            }
            len[deep[nextnode] - 1] = max(len[deep[nextnode] - 1], maxlen);
            q.push(nextnode);
        }
    }
}

int p(int t, int k)
{
    if (ceil(len[t] * 1.0 / 2.0) <= k * (t - t0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n;
    maxt = 2 * n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cin >> r >> t0;
    init();
    l_of_tree();
    for (int i = 1; i <= 2 * n; i++)
    {
        if (len[i] == 0)
        {
            len[i] = len[i - 1];
        }
    }
    int nowans = maxt;
    for (int k = 1; k <= n; k++)
    {
        while (p(nowans, k) == 1)
        {
            nowans--;
        }
        nowans++;
        cout << nowans << endl;
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