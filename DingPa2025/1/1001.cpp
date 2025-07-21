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

int n;

int factorial[1000006];
int inv[1000006];
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

int com(int n, int m)
{
    return factorial[n] * inv[n - m] % MOD * inv[m] % MOD;
}
void init()
{
    factorial[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= MOD;
        inv[i] = mypow(factorial[i], MOD - 2);
    }
}
void solve()
{
    cin >> n;
    int all1odd = 0, all1even = 0, xor1 = 0, xor0 = 0;
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int xorsum = 0;

        int all1 = 1;
        for (int j = 1; j <= k; j++)
        {
            int stone;
            cin >> stone;
            if (stone != 1)
            {
                all1 = 0;
            }
            xorsum ^= stone;
        }
        if (all1 == 1 && k % 2 == 1)
        {
            all1odd++;
        }
        else if (all1 == 1 && k % 2 == 0)
        {
            all1even++;
        }
        else if (xorsum != 0)
        {
            xor1++;
        }
        else
        {
            xor0++;
        }
    }

    int ans = 0;
    for (int i = 0; i <= all1odd; i++)
    {
        int tmpans = 0;
        if (i % 2 == 0)
        {
            tmpans = com(all1odd, i) * factorial[i] % MOD * (xor1) % MOD * factorial[n - i - all1even - 1] % MOD;
            // cout << com(all1odd, i) << ' ' << factorial[all1odd] << ' ' << factorial[n - i - 1] << endl;
        }
        else
        {

            tmpans = com(all1odd, i) * factorial[i] % MOD * (xor0) % MOD * factorial[n - i - all1even - 1] % MOD;
        }
        ans += tmpans;
        ans %= MOD;
    }
    if (all1odd + all1even == n)
    {
        if (all1odd & 1)
        {
            cout << factorial[n] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return;
    }

    ans *= com(n, all1even);
    ans %= MOD;
    ans *= factorial[all1even];
    ans %= MOD;
    cout << ans << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;
    init();
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}