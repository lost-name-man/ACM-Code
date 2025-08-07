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
vector<int> arr;
vector<vector<int>> vis;
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5, 0);
    vis = vector<vector<int>>(34, vector<int>(n + 5));
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 1; i <= 33; i++)
    {
        int oeven = 0, zeven = 0, oodd = 0, zodd = 0;
        for (int j = 1; j <= n; j++)
        {
            vis[i][j] = vis[i - 1][j];
            if ((arr[j] >> (i - 1)) & 1)
            {
                vis[i][j] = vis[i - 1][j] ^ 1;
                if (vis[i - 1][j] == 1)
                {
                    oodd++;
                }
                else
                {
                    oeven++;
                }
            }
            else
            {
                if (vis[i - 1][j] == 1)
                {
                    zodd++;
                }
                else
                {
                    zeven++;
                }
            }
        }
        ans += (oodd * zodd) * (1 << (i - 1)) + (oeven * zeven) * (1 << (i - 1));
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
