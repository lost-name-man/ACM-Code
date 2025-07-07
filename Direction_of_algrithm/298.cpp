#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

struct Node
{
    int l;
    int pri;
    int ms;
    const bool operator<(Node &a) const
    {
        return this->ms < a.ms;
    }
};
int n, m;
Node can[20000];
int dp[20000][102];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> can[i].l >> can[i].pri >> can[i].ms;
    }
    sort(can + 1, can + m + 1);
    vector<vector<int>> maxarr(m + 5, vector<int>(n + 5, -1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int nowl = can[j].l, nows = can[j].ms, nowp = can[j].pri;
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (nows > i || (i - nows + 1) > nowl)
            {
                continue;
            }

            if (nows == i)
            {
                for (int k = 1; k <= nowl; k++)
                {
                    int lindex = i - k;
                    lindex = max((int)0, lindex);
                    maxarr[j][lindex] = max(maxarr[j][lindex + 1], dp[lindex][j - 1] + (can[j].pri) * (nows - lindex));
                }
            }
            int lindex = i - nowl;
            lindex = max((int)0, lindex);
            dp[i][j] = max(dp[i][j], maxarr[j][lindex] + can[j].pri * (i - nows));
        }
    }
    cout << dp[n][m] << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}