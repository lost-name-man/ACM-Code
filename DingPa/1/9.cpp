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

int n, m;
void solve()
{

    cin >> n >> m;
    int M = pow(2, m);
    vector<int> arr(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> grr(M + 5);
    for (int i = 1; i <= M; i++)
    {
        cin >> grr[i - 1];
    }
    vector<int> dp(n + 5, 0);
    vector<vector<int>> index_of_j(22, vector<int>(n + 5, 1));

    vector<vector<int>> preein(22, vector<int>(n + 5, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            preein[i][j] = preein[i][j - 1] + ((arr[j] >> (i - 1)) & 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int maxn = 0;
        int nownum = arr[i];
        dp[i] = dp[i - 1];
        for (int j = 1; j <= m; j++)
        {
            int nowzwei = (nownum >> (j - 1)) & 1;
            int nowindex = index_of_j[j][nowzwei ^ 1];

            index_of_j[j][nowzwei] = i;
            if (nowindex == 0)
            {
                continue;
            }
            int len = i - nowindex + 1;
            int nowf = 0;

            nowf =

                for (int k = 1; k <= m; k++)
            {
                int onenum = (preein[k][i] - preein[k][nowindex - 1]);
                if (onenum != 0 && onenum != len)
                {
                    nowf |= (1 << (k - 1));
                }
            }
            maxn = max(maxn, grr[nowf] + dp[nowindex - 1]);
        }
        dp[i] = max(dp[i], maxn);
    }

    cout << dp[n] << endl;
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