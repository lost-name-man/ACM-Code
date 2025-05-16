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
    vector<int> dp(n + 5, -INF);
    dp[0] = 0;
    vector<vector<int>> index_of_j(22, vector<int>(2, 0));

    int prex = 0, prey = 0, pre;
    for (int i = 1; i <= n; i++)
    {
        prex |= arr[i];
        prey &= arr[i];
        pre = prex - prey;
        int maxn = -INF;
        int nownum = arr[i];
        dp[i] = dp[i - 1] + grr[0];

        map<int, int> mp;
        for (int j = 1; j <= m; j++)
        {
            int nowzwei = (nownum >> (j - 1)) & 1;
            int nowindex = index_of_j[j][nowzwei ^ 1];
            index_of_j[j][nowzwei] = i;
            if (nowindex == 0)
            {
                continue;
            }
            else
            {
                mp[nowindex] |= (1 << (j - 1));
            }
        }
        int nowf = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            nowf |= it->second;
            maxn = max(maxn, grr[nowf] + dp[it->first - 1]);
        }

        dp[i] = max({dp[i], maxn, grr[pre]});
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