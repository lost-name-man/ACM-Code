#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 998244353;

int f[103][103][103];
void solve()
{

    string s, t;
    cin >> s >> t;
    int lens = s.size(), lent = t.size();
    s = '0' + s;
    t = '0' + t;

    for (int i = 0; i <= lens; i++)
    {
        for (int j = 1; j <= lent + 1; j++)
        {
            f[i][j][j - 1] = 1;
        }
    }

    for (int i = 1; i <= lens; i++)
    {
        for (int l = 1; l <= lent; l++)
        {
            for (int r = l; r <= lent; r++)
            {
                for (int x = l - 1; x <= r; x++)
                {
                    f[i][l][r] += f[i - 1][l][x] * f[i - 1][x + 1][r];
                    f[i][l][r] %= MOD;
                }
                for (int x = l; x <= r; x++)
                {
                    if (t[x] == s[i])
                    {
                        f[i][l][r] += f[i - 1][l][x - 1] * f[i - 1][x + 1][r];
                        f[i][l][r] %= MOD;
                    }
                }
            }
        }
    }

    cout << f[lens][1][lent] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
