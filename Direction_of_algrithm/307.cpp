#include <bits/stdc++.h>

typedef long double ld;
#define int __int128_t
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;

signed n;
int f[55];
int factorial[55];
int inv[55];
int mypow(int n, int p)
{
    int re = 1, base = n;
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
    return ((factorial[n] * inv[n - m]) % MOD * inv[m]) % MOD;
}
void init()
{
    factorial[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 50; i++)
    {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= MOD;
        inv[i] = mypow(factorial[i], MOD - 2);
    }
}
void solve()
{
    init();
    f[1] = 1;
    for (int i = 2; i <= 50; i++)
    {
        int sumi = mypow(2, com(i, 2));
        int sumj = 0;
        for (int j = 1; j < i; j++)
        {
            sumj += (f[j] * com(i - 1, j - 1) % MOD) * mypow(2, com(i - j, 2));
            sumj %= MOD;
        }
        f[i] = ((sumi - sumj) % MOD + MOD) % MOD;
    }
    while (cin >> n && n != 0)
    {
        unsigned long long high = 0, low = 0;
        high = (f[n] >> 64);
        low = f[n];
        if (high != 0)
        {
            cout << high;
        }
        cout << low << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}