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
        int nowtan = s + pret[i];
        int l = ll, r = rr;
        int mid;
        int j;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nowtan * (prec[dq[mid + 1]] - prec[dq[mid]]) >= (f[dq[mid + 1]] - f[dq[mid]]))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        j = dq[r];

        f[i] = f[j] - (s + pret[i]) * prec[j] + pret[i] * prec[i] + s * prec[n];

        while (rr && (double)(f[i] - f[dq[rr]]) * (prec[dq[rr]] - prec[dq[rr - 1]]) <= (double)(f[dq[rr]] - f[dq[rr - 1]]) * (prec[i] - prec[dq[rr]]))
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