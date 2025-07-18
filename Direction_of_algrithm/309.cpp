#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;
const int N = 200000;

int f[22][22][2];

void init()
{
    f[1][1][0] = 1, f[1][1][1] = 1;
    for (int i = 2; i <= 20; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                if (k == 0)
                {
                    for (int jj = j; jj < i; jj++)
                    {
                        f[i][j][k] += f[i - 1][jj][k ^ 1];
                    }
                }
                else
                {
                    for (int jj = 1; jj < j; jj++)
                    {
                        f[i][j][k] += f[i - 1][jj][k ^ 1];
                    }
                }
            }
        }
    }
}
int ans[22];
int vis[22] = {0};
void solve()
{
    init();
    int q;
    cin >> q;
    int n, c;

    while (q--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> c;
        int lastlen, lastk;
        for (int j = 1; j <= n; j++)
        {
            int ok = 0;
            for (int k = 1; k >= 0; k--)
            {
                if (f[n][j][k] >= c)
                {
                    lastlen = j;
                    lastk = k;
                    ok = 1;
                    break;
                }
                else
                {
                    c -= f[n][j][k];
                }
            }
            if (ok == 1)
            {
                break;
            }
        }
        cout << lastlen << ' ';
        vis[lastlen] = 1;
        for (int i = 2; i <= n; i++)
        {
            int j = 0;
            for (int len = 1; len <= n; len++)
            {
                if (vis[len])
                {
                    continue;
                }
                j++;
                if (lastk == 0 && len > lastlen || lastk == 1 && len < lastlen)
                {
                    if (f[n - i + 1][j][lastk ^ 1] >= c)
                    {
                        lastlen = len;
                        lastk ^= 1;
                        cout << len << ' ';
                        break;
                    }
                    else
                    {
                        c -= f[n - i + 1][j][lastk ^ 1];
                    }
                }
            }
        }

        cout << endl;
    }
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