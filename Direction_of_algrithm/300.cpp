#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int n, s;
int t[5003], c[5003];
int dp[5003];
int pret[5003], prec[5003];
void solve()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        pret[i] = pret[i - 1] + t[i];
        prec[i] = prec[i - 1] + c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int minn = INF;
        for (int j = 0; j < i; j++)
        {
            minn = min(minn, dp[j] + s * (prec[n] - prec[j]) + (pret[i] * (prec[i] - prec[j])));
        }
        dp[i] = minn;
    }
    cout << dp[n] << endl;
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