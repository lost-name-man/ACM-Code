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

int t, n, m;
int dp[61][21][102];
int arr[21];

void solve()
{
    memset(dp, 0x3f, sizeof(dp));
    cin >> t >> n >> m;
    arr[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> arr[i];
    }
    arr[n] = n * t;
    dp[0][0][0] = 0;
    for (int nowindex = 0; nowindex <= n * t; nowindex++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                int dis = abs(arr[j] - nowindex);

                if (j == n && (nowindex != n * t))
                {
                    continue;
                }
                if (k - dis < 0)
                {
                    continue;
                }
                for (int lastindex = 0; lastindex <= nowindex; lastindex++)
                {
                    dp[nowindex][j][k] = min(dp[nowindex][j][k], dp[lastindex][j - 1][k - dis] + (nowindex - lastindex) * (nowindex - lastindex));
                }
            }
        }
    }
    int ans = INF;
    for (int k = 0; k <= m; k++)
    {
        ans = min(ans, dp[n * t][n][k]);
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