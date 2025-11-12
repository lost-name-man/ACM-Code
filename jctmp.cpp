#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int tot = 1;

int n, m;
vector<int> p;
vector<map<int, int>> g;
int pindex;

vector<int> du, vis, visnum;
vector<pair<int, int>> eans;
int ans = 0;

void dfs(int nownode, int fa)
{

    vis[nownode] = 1;

    for (auto it = g[nownode].begin(); it != g[nownode].end(); it++)
    {
        visnum[it->first]++;
    }
    while (visnum[nownode] < du[nownode] && pindex <= n)
    {
        int neednode = p[pindex];
        if (g[nownode][neednode])
        {
            pindex++;
            dfs(neednode, nownode);
        }
        else
        {
            du[nownode]++;
            du[neednode]++;
            visnum[neednode]++;
            g[neednode][nownode] = 1;
            g[nownode][neednode] = 1;

            pindex++;
            ans++;
            eans.push_back({nownode, neednode});
            dfs(neednode, nownode);
        }
    }
}

void solve()
{
    ans = 0;
    cin >> n >> m;
    p = du = vis = visnum = vector<int>(n + 5);
    g = vector<map<int, int>>(n + 5, map<int, int>());
    pindex = 1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        du[x]++;
        du[y]++;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    while (pindex <= n)
    {
        int neednode = p[pindex];
        pindex++;
        dfs(neednode, 0);
    }
    cout << ans << endl;
    for (int i = 0; i < eans.size(); i++)
    {
        cout << eans[i].first << ' ' << eans[i].second << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
