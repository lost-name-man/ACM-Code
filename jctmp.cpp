#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
#define int long long

const int INF = 1e18 + 7;
const int MOD = 0;

struct Edge
{
    int id;
    int from;
    int to;
    int w;

    int nex;
};

vector<Edge> edgeo;
int cfso;
vector<int> heado;

void addedgeo(int u, int v, int w)
{
    cfso++;
    edgeo[cfso].from = u;
    edgeo[cfso].to = v;
    edgeo[cfso].w = w;
    edgeo[cfso].nex = heado[u];
    heado[u] = cfso;
}

vector<Edge> edger;
int cfsr;
vector<int> headr;

void addedger(int u, int v, int w)
{
    cfsr++;
    edger[cfsr].from = u;
    edger[cfsr].to = v;
    edger[cfsr].w = w;
    edger[cfsr].nex = headr[u];
    headr[u] = cfsr;
}

int n;

struct Pg
{
    int id;

    int a;
    int t;

    int lr; // l==-1; r==1;
    int ed;
};

bool cmpdis(Pg &x, Pg &y)
{
    return x.a < y.a;
}

vector<Pg> pg;

vector<int> vis, checkc;

void bfs(int stnode)
{
    queue<int> q;
    q.push(stnode);
    vis[stnode] = 1;
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();
        for (int i = headr[nownode]; i; i = edger[i].nex)
        {
            int nexnode = edger[i].to;
            if (vis[nexnode] == 1)
            {
                continue;
            }
            else
            {
                vis[nexnode] = 1;
            }

            if (pg[nownode].lr == pg[nexnode].lr)
            {
                pg[nexnode].ed = pg[nownode].ed;
            }
            else
            {
                int tmpdis = max(abs(pg[nownode].ed - pg[nexnode].a), abs(pg[nownode].a - pg[nexnode].a) / 2);
                pg[nexnode].ed = pg[nexnode].a + pg[nexnode].lr * tmpdis;
            }

            q.push(nexnode);
        }
    }
}
void solve()
{
    cin >> n;
    pg = vector<Pg>(n + 5);

    cfso = cfsr = 1;
    edgeo = edger = vector<Edge>(n + 5);
    heado = headr = vector<int>(n + 5, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> pg[i].t;

        pg[i].id = i;
        addedgeo(i, pg[i].t, 1);
        addedger(pg[i].t, i, 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pg[i].a;
        pg[i].a *= 2;
    }

    for (int i = 1; i <= n; i++)
    {
        int toindex = pg[pg[i].t].a;
        if (pg[i].a - toindex > 0)
        {
            pg[i].lr = -1;
        }
        else
        {
            pg[i].lr = 1;
        }
    }

    // find

    vis = checkc = vector<int>(n + 5, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] != 0)
        {
            continue;
        }
        // get circle
        int ok = 1;
        int nownode = i;
        vector<Pg> tmpc;
        while (checkc[nownode] < 2)
        {
            int nextnode = pg[nownode].t;
            if (checkc[nownode] == 1)
            {
                tmpc.push_back(pg[nownode]);
            }
            checkc[nownode]++;
            nownode = nextnode;
        }

        if (ok == 0) // had op
        {
            continue;
        }

        int minn = INF, fpg, fed;
        for (int i = 0; i < tmpc.size(); i++)
        {
            int lover = (i + 1) % tmpc.size();
            if (tmpc[i].lr != tmpc[lover].lr)
            {
                int dis = abs(tmpc[i].a - tmpc[lover].a);
                if (dis < minn)
                {
                    fpg = tmpc[i].id;
                    fed = tmpc[i].a + tmpc[i].lr * dis / 2;
                    minn = dis;
                }
            }
        }
        pg[fpg].ed = fed;

        bfs(fpg);
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = abs(pg[i].a - pg[i].ed);

        cout << ans << " ";
    }

    cout << endl;
}
signed main()
{
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}