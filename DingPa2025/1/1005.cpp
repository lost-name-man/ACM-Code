#include <climits>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
const long long INF = 1e18 + 7;

struct Edge
{
    int id;
    int w;
    int from;
    int to;
    int next;
};

int tot;
vector<int> head;
vector<Edge> edge;
int n, m;

void addedge(int x, int y, int w)
{
    tot++;
    edge[tot].from = x;
    edge[tot].to = y;
    edge[tot].w = w;

    edge[tot].next = head[x];
    head[x] = tot;
}

int nodetot;
vector<map<int, int>> node_aso;

vector<int> fa;

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = findfa(fa[x]);
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

priority_queue<Node> q;
int ans = INF;
vector<int> dis;
vector<int> vis;
void dji()
{
    dis[1] = 0;
    q.push((Node){0, 1});

    while (q.size())
    {
        Node tmp = q.top();
        q.pop();
        int nownode = tmp.pos;
        int nowdis = tmp.dis;
        if (vis[nownode] == 1)
        {
            continue;
        }
        vis[nownode] = 1;
        for (int i = head[nownode]; i; i = edge[i].next)
        {
            int tonode = edge[i].to;
            int tow = edge[i].w;
            int baned=edge[i].id;
            if(baned==1)
            {
                continue;
            }
            if (dis[tonode] > dis[nownode] + tow)
            {
                dis[tonode] = dis[nownode] + tow;
                if (vis[tonode] == 0)
                {
                    q.push((Node){dis[tonode], tonode});
                }
            }
        }
    }
}

void solve()
{
    tot = 1;
    cin >> n >> m;
    head = vector<int>(n + m + 15, 0);
    edge = vector<Edge>(m * 4 + 15);

    nodetot = n + 10;
    node_aso = vector<map<int, int>>(n + 15);
    fa = vector<int>(n + m + 15);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if (node_aso[u][c] == 0 && node_aso[v][c] == 0)
        {
            nodetot++;
            fa[nodetot] = nodetot;
            node_aso[u][c] = nodetot;
            node_aso[v][c] = nodetot;
            addedge(u, nodetot, 1);
            addedge(v, nodetot, 1);
            addedge(nodetot, u, 0);
            addedge(nodetot, v, 0);
        }
        else if (node_aso[u][c] == 0 && node_aso[v][c] != 0)
        {
            int upnode = node_aso[v][c];
            upnode = findfa(upnode);

            node_aso[u][c] = upnode;
            addedge(u, upnode, 1);
            addedge(upnode, u, 0);
        }
        else if (node_aso[u][c] != 0 && node_aso[v][c] == 0)
        {
            int upnode = node_aso[u][c];
            upnode = findfa(upnode);

            node_aso[v][c] = upnode;
            addedge(v, upnode, 1);
            addedge(upnode, v, 0);
        }
        else
        {
            int fau = findfa(node_aso[u][c]);
            int fav = findfa(node_aso[v][c]);
            if (fau < fav)
            {
                int upnode = fau;
                int sonnode = fav;
                fa[sonnode] = upnode;
            }
            else if (fau > fav)
            {
                int upnode = fav;
                int sonnode = fau;
                fa[sonnode] = upnode;
            }
        }
    }

    for (int i = n + 10 + 1; i <= nodetot; i++)
    {
        int nowfa = findfa(i);
        if (nowfa != i)
        {
            for (int j = head[i]; j != 0; j = edge[j].next)
            {
                int nowto = edge[j].to;
                int noww = edge[j].w;
                edge[j].id=1;
                if (noww == 1)
                {
                    addedge(nowfa, nowto, 0);
                    addedge(nowto, nowfa, 1);
                }
            }
        }
    }

    q = priority_queue<Node>();
    dis = vector<int>(nodetot + 5, INF);
    vis = vector<int>(nodetot + 5, 0);
    dji();

    cout << dis[n] << endl;
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