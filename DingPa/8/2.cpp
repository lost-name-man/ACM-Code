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

int wasd[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int add_interval(int l, int r, int val)
{
}

vector<vector<int>> ques_grop_cost;
vector<vector<int>> ques_grop_val;
void solve()
{

    int n, m, x;
    cin >> n >> m >> x;
    ques_grop_cost = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
    ques_grop_val = vector<vector<int>>(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ques_grop_cost[i][j];
            ques_grop_cost[i][j] += ques_grop_cost[i][j - 1];
            cin >> ques_grop_val[i][j];
            ques_grop_val[i][j] += ques_grop_val[i][j - 1];
        }
    }

    // vector<vector<int>> dp(n + 5, vector<int>(x + 5, 0));
    vector<int>dp(x + 5, 0);
    for (int subject = 1; subject <= n; subject++)
    {
        for (int j = x; j >= 0; j--)
        {
            for (int group = 1; group <= m; group++)
            {
                
                int nowcost = ques_grop_cost[subject][group];
                int nowval = ques_grop_val[subject][group];
                if(j>=nowcost)
                {
                    {
                        dp[j]=max(dp[j], dp[j-nowcost]+nowval);
                    }
                }
            }
        }
    }

    int sum=0;
    for(int i=1; i<=n; i++)
    {
        sum+=ques_grop_val[i][m];
    }
    cout<<sum-dp[x]<<endl;
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