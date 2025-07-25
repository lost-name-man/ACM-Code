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

int n;

vector<int> arr;
vector<int> f[2];

int mypow(int n, int p)
{
    int base = n, re = 1;
    while (p)
    {
        if (p & 1)
        {
            re *= base;
            re %= MOD;
        }
        base *= base;
        base %= MOD;
        p >>= 1;
    }
    return re;
}
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);

    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] == -1)
        {
            num++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            if (arr[i - 1] == 0)
            {
                ans += mypow(2, num);
            }
            else if (arr[i - 1] == -1)
            {
                ans += mypow(2, num - 1);
            }
            ans %= MOD;
        }
        else if (arr[i] == -1)
        {
            if (arr[i - 1] == 0)
            {
                ans += mypow(2, num - 1);
            }
            else if (arr[i - 1] == -1)
            {
                ans += mypow(2, num - 2);
            }
            ans %= MOD;
        }
    }
    cout << ans << endl;
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
