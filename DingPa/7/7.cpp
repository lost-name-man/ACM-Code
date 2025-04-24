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

const int N = 1000005;
const int M = N * 2;
using namespace std;

struct Edge
{
    int nextedge;
    int tonode;
    int val;
};

int n;
vector<Edge> edge;
vector<int> head;
int tot = 1;

void add(int x, int y, int z)
{
    edge[++tot].tonode = y, edge[tot].val = z, edge[tot].nextedge = head[x];
    head[x] = tot;
}

vector<int> isroad;
vector<int> road;
int starts, final;
int ok = 0;
int ans = 0;
void findend(int nownode, int fa)
{
    if (nownode == final)
    {
        ok = 1;
        isroad[nownode] = 1;
        road.push_back(nownode);
        return;
    }
    for (int i = head[nownode]; i; i = edge[i].nextedge)
    {
        int nextnode = edge[i].tonode;
        if (nextnode == fa)
        {
            continue;
        }
        findend(nextnode, nownode);
        if (ok == 1)
        {
            ans += edge[i].val;
            isroad[nownode] = 1;
            road.push_back(nownode);
            return;
        }
    }
}

int dfs(int nownode, int faedge)
{
    int nowval = edge[faedge].val + edge[faedge ^ 1].val;
    for (int i = head[nownode]; i; i = edge[i].nextedge)
    {
        int nextnode = edge[i].tonode;
        if (isroad[nextnode] == 1 || (i ^ 1) == faedge)
        {
            continue;
        }
        nowval += max(dfs(nextnode, i), (int)0);
    }
    return nowval;
}
void solve()
{

    cin >> n;
    tot = 1;
    road = vector<int>();
    edge = vector<Edge>(n * 2 + 10);
    isroad = vector<int>(n + 10, 0);
    head = vector<int>(n + 10, 0);
    for (int i = 1; i < n; i++)
    {
        int x, y, val1, val2;
        cin >> x >> y >> val1 >> val2;
        add(x, y, val1);
        add(y, x, val2);
    }

    ans = 0;
    ok = 0;
    cin >> starts >> final;

    findend(starts, -1);
    for (int i = 0; i < road.size(); i++)
    {
        ans += dfs(road[i], 0);
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