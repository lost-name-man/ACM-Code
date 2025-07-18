#include <climits>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define int long long
#define endl '\n'
const long long INF = 1e9 + 7;

struct Edge
{
    int id;
    int w;
    int from;
    int to;
    int next;
    int c;
};

int tot;
vector<int> head;
vector<Edge> edge;
int n, m;

void addedge(int x, int y, int w, int c)
{
    tot++;
    edge[tot].from = x;
    edge[tot].to = y;
    edge[tot].w = w;
    edge[tot].c = c;
    edge[tot].next = head[x];
    head[x] = tot;
}

struct Node
{
    int dis;
    int pos;
    bool operator<(const Node &x) const
    {
        return x.dis < dis;
    }
};

priority_queue<Node> pq;
int ans = INF;
vector<int> dis;
vector<int> vis;
int dji()
{
    dis[1] = 0;
    pq.push({0, 1});
    int re;
    while (pq.size())
    {
        Node tmp = pq.top();
        pq.pop();
        int nownode = tmp.pos;
        int nowdis = tmp.dis;

        if (nownode == n)
        {
            re = nowdis;
            return re;
        }
        if (vis[nownode] == 1)
        {
            continue;
        }
        else
        {
            vis[nownode] = 1;
        }
        for (int i = head[nownode]; i; i = edge[i].next)
        {
            int tonode = edge[i].to;
            int tow = edge[i].w;
            if (vis[tonode])
            {
                continue;
            }
            pq.push({nowdis + tow, tonode});
        }
    }
}

map<int, set<int>> p_aso;
map<int, int> visbfs;
int nodetot;
void bfs(int stnode, int c)
{

    queue<int> q;
    q.push(stnode);
    visbfs[stnode] = 1;
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();
        addedge(nownode, nodetot, 1, -1);
        addedge(nodetot, nownode, 0, -1);
        for (int i = head[nownode]; i; i = edge[i].next) // tle
        {
            int nextnode = edge[i].to;
            if (edge[i].c != c || visbfs[nextnode] == 1)
            {
                continue;
            }
            q.push(nextnode);
            visbfs[nextnode] = 1;
        }
    }
}
void solve()
{
    tot = 1;
    cin >> n >> m;
    head = vector<int>(n + m + 100, 0);
    edge = vector<Edge>(m * 6 + 100);

    nodetot = n + 10;

    p_aso = map<int, set<int>>();
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        addedge(u, v, INF, c);
        addedge(v, u, INF, c);
        p_aso[c].insert(u);
        p_aso[c].insert(v);
    }

    /////
    for (auto it = p_aso.begin(); it != p_aso.end(); it++)
    {

        visbfs = map<int, int>();
        for (auto nownode = it->second.begin(); nownode != it->second.end(); nownode++)
        {
            nodetot++;
            bfs(*nownode, it->first);
        }
    }

    pq = priority_queue<Node>();
    dis = vector<int>(nodetot + 5, INF);
    vis = vector<int>(nodetot + 5, 0);
    ans = dji();

    cout << ans << endl;
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