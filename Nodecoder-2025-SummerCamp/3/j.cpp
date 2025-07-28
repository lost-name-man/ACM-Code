#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 998244353

using namespace std;

int x, y;
void solve()
{

    cin >> x >> y;

    //
    int cnt = 0;
    int ok = 1;
    while (x != 0 && y != 0)
    {
        if (x > y)
        {
            swap(x, y);
        }
        y -= x;
        x *= 2;
        cnt++;
        if (cnt > 1000)
        {
            ok = 0;
            break;
        }
    }
    if (ok == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << cnt << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
