#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long

const int INF = 1e18 + 7;
const int MOD = 0;

struct Edge
{
    int w;
    int from;
    int to;
    int nex;
};
vector<Edge> edge;
vector<int> head;
int cfs;

void addedge(int u, int v, int w)
{
    cfs++;
    edge[cfs].from = u;
    edge[cfs].to = v;
    edge[cfs].w = w;
    edge[cfs].nex = head[u];
    head[u] = cfs;
}

void solve()
{
}
signed main()
{
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}