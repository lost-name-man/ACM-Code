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
const int INF = 1e9;
const int MOD = 11380;

int n;
vector<pair<int, int>> arr;

int f[202][202];
void solve()
{
    cin >> n;
    arr = vector<pair<int, int>>(n * 2 + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first;
        arr[i + n].first = arr[i].first;
    }
    for (int i = 1; i < 2 * n; i++)
    {
        arr[i].second = arr[i + 1].first;
    }

    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 < 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + arr[l].first * arr[k].second * arr[r].second);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i][i + n - 1]);
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
