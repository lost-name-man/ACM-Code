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
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 998244353;

int n, m;
int f[1003][1003];
void solve()
{
    string sa, sb;
    cin >> n >> m;
    cin >> sa >> sb;
    sa = '@' + sa;
    sb = '@' + sb;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (sa[i] == sb[j])
            {
                f[i][j] = max({f[i - 1][j - 1] + 1, f[i - 1][j], f[i][j - 1]});
            }
            else
            {
                f[i][j] = max({f[i - 1][j], f[i][j - 1]});
            }
        }
    }
    cout << f[n][m] << endl;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    // cin >> T;

    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
