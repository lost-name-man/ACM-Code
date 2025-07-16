#include <bits/stdc++.h>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int n;
int arr[5003];
int prearr[5003];
int f[5003][5003];
int p[5003][5003];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prearr[i] = prearr[i - 1] + arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        f[i][i + 1] = arr[i] + arr[i + 1];
        p[i][i + 1] = i;
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            int l = p[i][j - 1], r = p[i + 1][j];
            int minn = INF;
            int minp = l;
            for (int nowp = l; nowp <= r; nowp++)
            {
                if (f[i][nowp] + f[nowp + 1][j] + prearr[j] - prearr[i - 1] < minn)
                {
                    minn = f[i][nowp] + f[nowp + 1][j] + prearr[j] - prearr[i - 1];
                    minp = nowp;
                }
            }
            p[i][j] = minp;
            f[i][j] = minn;
        }
    }
    cout << f[1][n] << endl;
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