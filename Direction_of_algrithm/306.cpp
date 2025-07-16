#include <bits/stdc++.h>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1e9 + 7)

using namespace std;

int n, m, num;
pair<int, int> chess[200005];

int factorial[200005];
int f[200005];
int inv[200005];
int mypow(int n, int p)
{
    int re = 1, base = n;
    while (p)
    {
        if (p & 1)
        {
            re = (re * base) % MOD;
        }
        base *= base;
        base %= MOD;
        p >>= 1;
    }
    return re;
}

int finv(int x)
{
    return mypow(x, MOD - 2);
}
int comb(int n, int m)
{
    return (factorial[n] * inv[n - m] % MOD) * inv[m] % MOD;
}
void solve()
{
    cin >> n >> m >> num;
    for (int i = 1; i <= num; i++)
    {
        cin >> chess[i].first >> chess[i].second;
    }
    chess[num + 1] = {n, m};
    sort(chess + 1, chess + 1 + num);

    for (int i = 1; i <= num + 1; i++)
    {
        int nowx = chess[i].first, nowy = chess[i].second;
        int nowsum = comb(nowx + nowy - 2, nowx - 1);
        int lastsum = 0;

        for (int j = 1; j < i; j++)
        {
            int lastx = chess[j].first, lasty = chess[j].second;
            lastsum = (lastsum + f[j] * comb(nowx - lastx + nowy - lasty, nowx - lastx) % MOD) % MOD;
        }
        f[i] = ((nowsum - lastsum) % MOD + MOD) % MOD;
    }
    cout << f[num + 1] << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;
    int base = 1;
    factorial[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        base = (base * i) % MOD;
        factorial[i] = base;
        inv[i] = finv(factorial[i]);
    }
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}