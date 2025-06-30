

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
#define MOD (int)(998244353)

using namespace std;

int n;
int arr[5003];
int dp[5003][10004] = {0};
int pre[5003] = {0};

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
        dp[i][0] = arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (i + j <= n)
            {
                dp[i][j] = max(dp[i][j], pre[i + j] - pre[i - 1]);
            }
            dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i][j]);
            if (i - j >= 1)
            {
                dp[i][j] = max(dp[i][j], pre[i] - pre[i - j - 1]);
            }
            dp[i][j] = max(dp[i + 1][j - 1], dp[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int tmpans = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            tmpans ^= j * dp[i][j];
        }
        tmpans += i;
        ans ^= tmpans;
    }
    cout << ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}