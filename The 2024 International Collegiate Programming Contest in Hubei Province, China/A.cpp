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

#define int long long
#define INF 1e9
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;

double asklen(pair<int, int> a, pair<int, int> b)
{
    return sqrt(abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second));
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    double ans = INF;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if ((p[i].first - p[j].first) * (p[i].second - p[k].second) == (p[i].first - p[k].first) * (p[i].second - p[j].second))
                {
                    continue;
                }
                double a = asklen(p[i], p[j]), b = asklen(p[i], p[k]), c = asklen(p[j], p[k]);
                double s = (a + b + c) / 2;
                ans = min(ans, sqrt(s * (s - a) * (s - b) * (s - c)));
            }
        }
    }
    if (ans == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << fixed << setprecision(12) << ans << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}