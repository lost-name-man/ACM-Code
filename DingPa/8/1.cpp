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

vector<vector<int>>colors;
vector<vector<int>>dis;


int wasd[4][2] = { {0, 1}, {0,-1}, {1, 0}, {-1, 0} };


void solve()
{

    int n, m, k;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>colors[i][j];
        }
    }

    vector<vector<int>>colors_col

    for(int row=1; row<=n; row++)
    {

    }
    

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