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
#define INF 1e9
#define endl '\n'
#define MOD (int)(1000000007)

const int N = 1000005;
const int M = N * 2;
using namespace std;

struct Edge
{
    int w;
    int nex;
    int to;
};
int n;
int head[N];
vector<Edge> edge;
int tot = 1;

void add(int x, int y, int z)
{
    edge[++tot].to = y, edge[tot].w = (z & 1);
    edge[tot].nex = head[x], head[x] = tot;
}
int even = 0, odd = 0;

vector<int> vis;
void dfs1(int nownode, int dis)
{
    if (dis & 1)
    {
        odd++;
    }
    else
    {
        even++;
    }
    vis[nownode] = 1;
    for (int i = head[nownode]; i; i = edge[i].nex)
    {
        int nextnode = edge[i].to;
        if (vis[nextnode])
        {
            continue;
        }
        dfs1(nextnode, dis ^ edge[i].w);
    }
}

void solve()
{
    even = 0, odd = 0;
    edge = vector<Edge>(M);
    memset(head, 0, sizeof(head));
    tot = 1;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    vis = vector<int>(n + 5, 0);
    dfs1(1, 0);

    cout << even * even * even + odd * odd * odd << endl;
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