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
const int INF = 1e16 + 7;
const int MOD = 1e9 + 7;

int n;
vector<double> p, f;

void solve()
{
    cin >> n;
    p = f = vector<double>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        int pp;
        cin >> pp;
        p[i] = pp * 1.0 / 1000;
    }

    f[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        f[i] = min(f[i + 1], (1 - p[i]) * i + p[i] * (f[i + 1] + 20));
    }
    cout << fixed << setprecision(12) << f[1] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
