#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 998244353

using namespace std;

int n, m;
vector<int> val, card;
int f[44][44][44][44];

void solve()
{
    cin >> n >> m;

    val = vector<int>(n + 5);
    card = vector<int>(5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int num;
        cin >> num;
        card[num]++;
    }
    f[0][0][0][0] = val[1];
    int ans = 0;
    for (int i = 0; i <= card[1]; i++)
    {
        for (int j = 0; j <= card[2]; j++)
        {
            for (int k = 0; k <= card[3]; k++)
            {
                for (int h = 0; h <= card[4]; h++)
                {
                    int nownode = i * 1 + j * 2 + k * 3 + h * 4 + 1;
                    if (i)
                    {
                        f[i][j][k][h] = max(f[i][j][k][h], f[i - 1][j][k][h] + val[nownode]);
                    }
                    if (j)
                    {
                        f[i][j][k][h] = max(f[i][j][k][h], f[i][j - 1][k][h] + val[nownode]);
                    }
                    if (k)
                    {
                        f[i][j][k][h] = max(f[i][j][k][h], f[i][j][k - 1][h] + val[nownode]);
                    }

                    if (h)
                    {
                        f[i][j][k][h] = max(f[i][j][k][h], f[i][j][k][h - 1] + val[nownode]);
                    }
                    if (nownode == n)
                    {
                        ans = max(ans, f[i][j][k][h]);
                    }
                }
            }
        }
    }
    cout << ans << endl;
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
