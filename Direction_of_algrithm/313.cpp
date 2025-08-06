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
const int MOD = 1e9 + 7;

int f, v;
int val[102][102];
int dp[102][102];
pair<int, int> g[102][102];
void solve()
{
    memset(dp, -0x3f, sizeof(dp));

    cin >> f >> v;

    for (int i = 0; i <= v; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cin >> val[i][j];
        }
    }

    for (int i = 1; i <= f; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (j < i)
            {
                continue;
            }
            for (int k = 0; k < j; k++)
            {
                if (dp[i - 1][k] + val[i][j] > dp[i][j])
                {
                    dp[i][j] = dp[i - 1][k] + val[i][j];
                    g[i][j] = {i - 1, k};
                }
            }
        }
    }

    int index = 0, maxn = -INF;
    for (int i = 1; i <= v; i++)
    {
        if (dp[f][i] > maxn)
        {
            index = i;
            maxn = dp[f][i];
        }
    }
    cout << dp[f][index] << endl;
    int deep = f;
    vector<int> ans;
    while (deep)
    {
        ans.push_back(index);
        index = g[deep][index].second;
        deep--;
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << ' ';
    }
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
