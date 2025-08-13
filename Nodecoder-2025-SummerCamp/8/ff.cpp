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
const int MOD = 998244353;

void solve()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int ans;
    if (y1 == y2 && y3 == y4)
    {
        int sx = min(x1, x2);
        int tx = min(x3, x4);

        ans = max(abs(sx - tx), abs(y1 - y3));
        cout << ans * 2 << endl;
    }
    else if (x1 == x2 && x3 == x4)
    {
        int sy = min(y1, y2);
        int ty = min(y3, y4);

        ans = max(abs(sy - ty), abs(x1 - x3));
        cout << ans * 2 << endl;
    }
    else if (y1 == y2)
    {
        int tx = x3;
        int dx = min(abs(tx - x1), abs(tx - x2));
        int dy = min(abs(y3 - y1), abs(y4 - y1));
        ans = max(dy, dx);
        cout << ans * 2 + 1 << endl;
    }
    else
    {
        int tx = x1;
        int dx = min(abs(tx - x3), abs(tx - x4));
        int dy = min(abs(y1 - y3), abs(y2 - y3));
        ans = max(dy, dx);
        cout << ans * 2 + 1 << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
