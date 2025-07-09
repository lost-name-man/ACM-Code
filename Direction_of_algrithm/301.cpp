#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

const int N = 300000;
int n, s;
int t[N + 10], c[N + 10];
int f[N + 10];
int pret[N + 10], prec[N + 10];
int dq[N + 10];
int ll = 0, rr = 0;
void solve()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        pret[i] = pret[i - 1] + t[i];
        prec[i] = prec[i - 1] + c[i];
    }
    dq[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        double nowtan = s + pret[i];
        while (ll < rr && (f[dq[ll + 1]] - f[dq[ll]]) * 1.0 / (prec[dq[ll + 1]] - prec[dq[ll]]) * 1.0 <= nowtan)
        {
            ll++;
        }
        int j = dq[ll];
        f[i] = f[j] - (s + pret[i]) * prec[j] + pret[i] * prec[i] + s * prec[n];

        while (ll < rr && (f[i] - f[dq[rr]]) * 1.0 / (prec[i] - prec[dq[rr]]) * 1.0 <= (f[dq[rr]] - f[dq[rr - 1]]) * 1.0 / (prec[dq[rr]] - prec[dq[rr - 1]]) * 1.0)
        {
            rr--;
        }
        dq[++rr] = i;
    }
    cout << f[n] << endl;
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