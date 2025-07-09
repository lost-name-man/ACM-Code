#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

const int N = 100000;

int n, m, p;
int d[N + 10];
int arr[N + 10];
int prearr[N + 10];
int dq[N + 10];
int ll = 0, rr = -1;

int f[102][N + 10];

int y(int i, int k)
{
    return f[i - 1][k] + prearr[k];
}
void solve()
{
    memset(f, 0x7f, sizeof(f));
    cin >> n >> m >> p;
    for (int i = 2; i <= n; i++)
    {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int h, t;
        cin >> h >> t;
        arr[i] = t - d[h];
        prearr[i] = prearr[i - 1] + arr[i];
    }

    sort(arr + 1, arr + 1 + m);
    for (int i = 0; i <= p; i++)
    {
        f[i][0] = 0;
    }
    for (int i = 1; i <= p; i++)
    {
        ll = 0, rr = 0;
        dq[0] = 0;
        for (int j = 1; j <= m; j++)
        {
            int nowtan = arr[j];
            while (ll < rr && nowtan >= (double)(y(i, dq[ll + 1]) - y(i, dq[ll])) / (double)(dq[ll + 1] - dq[ll]))
            {
                ll++;
            }
            int k = dq[ll];
            f[i][j] = f[i - 1][k] + arr[j] * (j - k) - (prearr[j] - prearr[k]);
            while (ll < rr && (double)(y(i, j) - y(i, dq[rr])) / (double)(j - dq[rr]) <=
                                  (double)(y(i, dq[rr]) - y(i, dq[rr - 1])) / (double)(dq[rr] - dq[rr - 1]))
            {
                rr--;
            }
            dq[++rr] = j;
        }
    }
    cout << f[p][m] << endl;
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