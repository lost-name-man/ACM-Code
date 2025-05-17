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

int n, m;

struct Edge
{
    int id;
    int w;
    int fver;
    int tver;
    int next;
};
vector<Edge>edge;
int cfstot = 1;
vector<int>head;


void addedge(int u, int v, int w)
{
    cfstot++;
    edge[cfstot].fver = u;
    edge[cfstot].tver = v;
    edge[cfstot].w = w;
    edge[cfstot].next = head[u];
    head[u] = cfstot;
}

vector<int>vis, dis;

int dfs(int innode)
{
    if (innode == 0 || dis[innode] == 1)
    {
        return 1;
    }
    vis[innode] = 1;
    int ret = 0;
    for (int i = head[innode]; i != 0; i = edge[i].next)
    {
        int nextnode = edge[i].tver;
        if (dis[nextnode] ==1 && nextnode<innode)
        {
            ret = ret | 1;
        }
        if (!vis[nextnode] && nextnode<innode)
        {
            ret = ret | dfs(nextnode);
        }
    }
    dis[innode] = dis[innode] | ret;


    return dis[innode];
}








void solve()
{

    cin >> n >> m;

    cfstot = 1;
    edge = vector<Edge>(2 * m + 5);
    head = vector<int>(n + 5, 0);
    dis = vector<int>(n + 5, 0);
    vis = vector<int>(n + 5, 0);

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        addedge(u, v, 1);
        addedge(v, u, 1);
    }

    vis = vector<int>(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        
        if (dis[i] != 1 || vis[i] != 1)
        {
            dfs(i);
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] != 1)
        {
            ans = 0;
            break;
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