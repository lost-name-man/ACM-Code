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

int n, t;
int arr[102];
pair<int, int> brr[102];
int sym[102];
int inv[102];
int f[102][20004];
int g[102][20004];
void solve()
{

    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        brr[i].first = arr[i];
        brr[i].second = i;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return;
    }
    int base = 1e4;
    f[1][arr[1] + base] = 1;
    f[2][arr[1] - arr[2] + base] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = -10000 + base; j <= 10000 + base; j++)
        {
            if (f[i - 1][j] == 1)
            {
                f[i][j + arr[i]] = 1;
                f[i][j - arr[i]] = 1;
                g[i][j + arr[i]] = j;
                g[i][j - arr[i]] = j;
            }
        }
    }

    int index = t + base, deep = n;
    sym[1] = 1;
    sym[2] = -1;
    while (deep > 2)
    {
        if (g[deep][index] > index)
        {
            sym[deep] = -1;
        }
        else
        {
            sym[deep] = 1;
        }
        index = g[deep][index];
        deep--;
    }

    int nowsym = -1;
    inv[1] = 1;
    for (int i = 3; i <= n; i++)
    {
        if (sym[i] != nowsym)
        {
            inv[i - 1] = 1;
            nowsym = sym[i];
        }
    }

    int last = n - 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (inv[i] == 1)
        {
            for (int j = i; j <= last; j++)
            {
                cout << i << endl;
            }
            last = i - 1;
        }
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
