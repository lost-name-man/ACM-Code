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

int n, m;
vector<Edge> edge;
vector<int> head;
int tot = 1;

void add(int x, int y, int z)
{
    edge[++tot].tonode = y, edge[tot].val = z, edge[tot].nextedge = head[x];
    head[x] = tot;
}

vector<vector<int>>euclid;
vector<vector<int>>dis;


int wasd[4][2] = { {0, 1}, {0,-1}, {1, 0}, {-1, 0} };

struct Node
{
    int id;
    int x;
    int y;

};

int bfs()
{
    dis = vector<vector<int>>(n + 5, vector<int>(m + 5, INF));


    queue<pair<int, int>>qu;
    for (int i = 1; i <= n; i++)
    {
        if (euclid[i][1] != 1)
        {
            qu.push({ i, 1 });
            dis[i][1] = 1;
        }

    }

    while (qu.size())
    {
        pair<int, int>pr = qu.front();
        int nowx = pr.first, nowy = pr.second;
        qu.pop();

        for (int i = 0; i <= 3; i++)
        {
            int nex = nowx + wasd[i][0], ney = nowy + wasd[i][1];
            if (nex<1 || nex>n || ney<1 || ney>m || euclid[nex][ney] == 1)
            {
                continue;
            }
            if (dis[nex][ney] > dis[nowx][nowy] + 1)
            {
                dis[nex][ney] = dis[nowx][nowy] + 1;
                qu.push({ nex, ney });
            }
        }
    }

    return 0;
}

void solve()
{


    cin >> n >> m;


    euclid = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));

    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        for (int j = 1; j <= r; j++)
        {
            int index;
            cin >> index;
            euclid[i][index] = 1;
        }
    }



    bfs();
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dis[i][m]);
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