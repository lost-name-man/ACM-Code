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
const int INF = 1e18;

int n, m, k;
string s;

vector<int> pre;
int f[200005][6][2];

bool p(int x)
{
    memset(f, 0x7f, sizeof(f));
    for (int i = 0; i <= n; i++)
    {
        f[i][0][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int lastindex = i - x;

        for (int j = 1; j <= k; j++)
        {
            f[i][j][0] = min(f[i - 1][j][1], f[i - 1][j][0]);
        }
        if (lastindex < 0)
        {
            continue;
        }
        for (int j = 1; j <= k; j++)
        {
            f[i][j][1] = f[lastindex][j - 1][0] + (pre[i] - pre[lastindex]);
            f[i][j][0] = min(f[i - 1][j][1], f[i - 1][j][0]);
        }

        if (pre[i] - pre[lastindex] == 0)
        {
            f[i][0][0] = INF;
        }
    }

    if (f[n][k][0] <= m || f[n][k][1] <= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n >> m >> k;
    cin >> s;
    s = '0' + s;
    pre = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        if (s[i] == '0')
        {
            pre[i]++;
        }
    }

    int l = 1, r = n;

    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (p(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << endl;
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
