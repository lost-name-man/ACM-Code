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

struct Edge
{
    int w;
    int nex;
    int tover;
};
int tot = 1;
vector<Edge> edge;
vector<int> head;

int n, m, x;
vector<int> askroom;
vector<vector<int>> p_inroom;

void add(int x, int y, int z)
{
    edge[++tot].tover = y, edge[tot].w = z, edge[tot].nex = head[x], head[x] = tot;
}

struct Node
{
    int id;
    int val;
    int step;

    const bool operator<(const Node &other) const
    {
        return this->val > other.val;
    }
};

vector<int> vis;
int dijsk()
{
    priority_queue<Node> pq;
    pq.push({1, 0, 0});
    while (!pq.empty())
    {

        int nownode = pq.top().id;
        int nowstep = pq.top().step;
        int nowval = pq.top().val;
        pq.pop();
        vis[nownode] = 1;

        if (nownode == n)
        {
            return nowval;
        }

        // int nowroom = askroom[nownode];
        for (int i = head[nownode]; i; i = edge[i].nex)
        {
            int nextnode = edge[i].tover;
            if (vis[nextnode] == 1)
            {
                continue;
            }
            else
            {
                pq.push({nextnode, nowval + edge[i].w, nowstep + 1});
            }
        }
    }
    return -1;
}

void solve()
{
    cin >> n >> m >> x;
    tot = 1;
    vis = vector<int>(6 * n + 5, 0);
    // visjump = vector<int>(n + 5, 0);
    edge = vector<Edge>(3 * m + 5 + 6 * n + 5);
    head = vector<int>(6 * n + 5, 0);
    // p_inroom = vector<vector<int>>(n + 5, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        int type;
        cin >> type;
        add(i, type + 4 * n, x);
        add(type + 4 * n, i + n, 0);
        add(i + n, type + 5 * n, x);
        add(type + 5 * n, i + 2 * n, 0);
        add(i + 2 * n, type + 3 * n, x);
        add(type + 3 * n, i, 0);
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y + n, z);
        add(x + n, y + 2 * n, z);
        add(x + 2 * n, y, z);
    }
    int ans = dijsk();
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