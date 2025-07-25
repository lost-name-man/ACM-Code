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
#define MOD 1000000007

using namespace std;

int n, m;

vector<int> up, down;
void solve()
{
    cin >> n >> m;

    up = vector<int>(n + 5);
    down = vector<int>(n + 5);

    for (int i = 1; i <= n; i++)
    {
        cin >> down[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> up[i];
    }

    int sumup = 0, sumd = 0;
    int nowup = INF, nowdown = 0;

    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        nowdown = max(nowdown, down[i]);
        if (nowdown > up[i])
        {
            ok = 0;
            break;
        }
        sumd += nowdown;
    }

    for (int i = n; i >= 1; i--)
    {
        nowup = min(nowup, up[i]);
        if (nowup < down[i])
        {
            ok = 0;
            break;
        }
        sumup += nowup;
    }
    if (ok == 0)
    {
        cout << "NO" << endl;
    }
    else if (m >= sumd && m <= sumup)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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
