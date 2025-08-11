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

int n, m;
string a, b;
void solve()
{
    cin >> n >> m;
    cin >> a >> b;
    a = '0' + a;
    b = '0' + b;

    int index = -1;

    for (int i = 0; i <= n; i++)
    {
        a[i] -= '0';
    }
    for (int i = 0; i <= m; i++)
    {
        b[i] -= '0';
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 1)
        {
            index = i;
            break;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (index == -1)
        {
            break;
        }
        if (a[i] == 1)
        {
            if (index > i || i + (m - index) > n)
            {
                break;
            }
            cnt++;
            for (int j = index; j <= m; j++)
            {
                if (b[j] == 1)
                {
                    a[i + j - index] ^= 1;
                }
            }
        }
    }

    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            ok = 0;
            break;
        }
    }
    if (ok == 1)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
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
