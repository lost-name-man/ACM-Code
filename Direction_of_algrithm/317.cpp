#include <cstddef>
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
#include <random>
#include <chrono>
using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e18;
const int MOD = 11380;

int l1, l2, l3, d;

int f[33][11][11][11];
void solve()
{
    cin >> l1 >> l2 >> l3 >> d;
    for (int i = 0; i <= d; i++)
    {
        f[i][0][0][0] = 1;
    }
    for (int deep = 1; deep <= d; deep++)
    {
        for (int i = 0; i <= l1; i++)
        {
            for (int j = 0; j <= l2; j++)
            {
                for (int k = 0; k <= l3; k++)
                {
                    // f[deep][i][j][k] = f[deep - 1][i][j][k];
                    if (i > 0)
                    {
                        for (int ai = 1; ai <= i; ai++)
                        {
                            for (int aj = 0; aj <= j; aj++)
                            {
                                for (int ak = 0; ak <= k; ak++)
                                {
                                    f[deep][i][j][k] += f[deep - 1][ai - 1][aj][ak] * f[deep][i - ai][j - aj][k - ak];
                                }
                            }
                        }
                    }
                    if (j > 0)
                    {
                        for (int aj = 1; aj <= j; aj++)
                        {
                            for (int ak = 0; ak <= k; ak++)
                            {
                                f[deep][i][j][k] += f[deep - 1][0][aj - 1][ak] * f[deep][i][j - aj][k - ak];
                            }
                        }
                    }
                    if (k > 0)
                    {
                        for (int ak = 1; ak <= k; ak++)
                        {
                            f[deep][i][j][k] += f[deep - 1][0][0][ak - 1] * f[deep][i][j][k - ak];
                        }
                    }
                    f[deep][i][j][k] %= MOD;
                }
            }
        }
    }
    if (d > l1 + l2 + l3 || (l1 + l2 + l3) != 0 && d == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (d == 0)
    {
        cout << 1 << endl;
        return;
    }
    cout << ((f[d][l1][l2][l3] - f[d - 1][l1][l2][l3]) % MOD + MOD) % MOD << endl;
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
