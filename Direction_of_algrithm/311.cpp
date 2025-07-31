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

int f[11][100][100][100];
void solve()
{
    for (int i = 1; i <= 90; i++)
    {
        f[0][0][i][0] = 1;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int nownum = 0; nownum <= 9; nownum++)
        {
            for (int lastsum = 0; lastsum <= (i - 1) * 9; lastsum++)
            {
                for (int lastmod = 1; lastmod <= 90; lastmod++)
                {
                    for (int lastless = 0; lastless <= 90; lastless++)
                    {
                        if (lastless == lastmod)
                        {
                            break;
                        }
                        f[i][lastsum + nownum][lastmod][(lastless + nownum) % lastmod] += f[i - 1][lastsum][lastmod][lastless];
                    }
                }
            }
        }
    }

    cout << "@@" << endl;
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
