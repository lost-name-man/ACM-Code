#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;
const int N = 200000;

int n;

struct Edge
{
    int id;
    int from;
    int to;
    int next;
};

struct CF
{

    vector<Edge> edge;
    vector<int> head;
    int tot = 1;
};

void addedge(CF &cf, int x, int y, int id)
{

    cf.tot++;
    cf.edge[cf.tot].from = x;
    cf.edge[cf.tot].to = y;
    cf.edge[cf.tot].id = id;
    cf.edge[cf.tot].next = cf.head[x];
    cf.head[x] = cf.tot;
}

CF cfori;
CF cfdrei;
int totid=0;
int delta;
void solve()
{

    cin >> n;
    delta=n+5;
    cfori.head = vector<int>(n + 5, 0);
    cfori.edge = vector<Edge>(3*n+5);
    cfdrei.head = vector<int>(3*n + 5, 0);
    cfdrei.edge = vector<Edge>(9*n+5);

    

    for(int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        int nowdelta=0;

        for(int j=1; j<=num; j++)
        {
            totid++;
            int toroom;
            cin>>toroom;
            addedge(cfdrei, i+nowdelta, toroom, totid);
            nowdelta+=delta;
        }
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}