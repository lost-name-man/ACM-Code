#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 998244353;

int n;
string s;

map<char, int> mp;

int f[100005][64][8];

void solve()
{
    cin >> n;
    cin >> s;
    s = '0' + s;
    for (int i = 0; i < 9; i++)
    {
        mp['0' + i] = i;
    }
    for (int i = 0; i < 26; i++)
    {
        mp['a' + i] = i + 10;
    }
    for (int i = 0; i < 26; i++)
    {
        mp['A' + i] = i + 36;
    }

    if (s[1] >= 'A' && s[1] <= 'Z')
    {
        int nowc = mp[s[1]];
        f[1][nowc][1] = 1;
    }
    if (s[1] >= '0' && s[1] <= '9')
    {
        int nowc = mp[s[1]];
        f[1][nowc][(1 << 2)] = 1;
    }
    if (s[1] >= 'a' && s[1] <= 'z')
    {
        int nowc = mp[s[1]];
        f[1][nowc][(1 << 1)] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        int nowc = mp[s[i]];
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            for (int st = 0; st < 8; st++)
            {
                int sum0 = 0, sum1 = 0;

                if ((st & 1) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {
                    if (nowc == j)
                    {
                        continue;
                    }
                    sum1 += f[i - 1][j][st];
                    sum0 += f[i - 1][j][st ^ 1];
                }
                f[i][nowc][st] += sum0 + sum1;
            }
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            for (int st = 0; st < 8; st++)
            {
                int sum0 = 0, sum1 = 0;

                if ((st & (1 << 2)) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {
                    if (nowc == j)
                    {
                        continue;
                    }
                    sum1 += f[i - 1][j][st];
                    sum0 += f[i - 1][j][st ^ (1 << 2)];
                }
                f[i][nowc][st] += sum0 + sum1;
            }
        }

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int tmpc = nowc + 26;
            for (int st = 0; st < 8; st++)
            {
                int sum0 = 0, sum1 = 0;

                if ((st & 1) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {
                    if (tmpc == j)
                    {
                        continue;
                    }
                    sum1 += f[i - 1][j][st];
                    sum0 += f[i - 1][j][st ^ 1];
                }
                f[i][tmpc][st] += sum0 + sum1;
            }

            for (int st = 0; st < 8; st++)
            {
                int sum0 = 0, sum1 = 0;

                if ((st & (1 << 1)) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {
                    if (nowc == j)
                    {
                        continue;
                    }
                    sum1 += f[i - 1][j][st];
                    sum0 += f[i - 1][j][st ^ (1 << 1)];
                }
                f[i][nowc][st] += sum0 + sum1;
            }
        }

        if (s[i] == '?')
        {
            for (int st = 0; st < 8; st++) // shuzi
            {
                int all0 = 0, all1 = 0;

                if ((st & (1 << 2)) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {
                    all1 += f[i - 1][j][st];
                    all0 += f[i - 1][j][st ^ (1 << 2)];
                }
                for (int tmpc = 0; tmpc <= 9; tmpc++)
                {
                    f[i][tmpc][st] = all1 - f[i - 1][tmpc][st] + all0;
                }
            }
            for (int st = 0; st < 8; st++) // xiao xie
            {
                int all0 = 0, all1 = 0;

                if ((st & (1 << 1)) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {

                    all1 += f[i - 1][j][st];
                    all0 += f[i - 1][j][st ^ (1 << 1)];
                }
                for (int tmpc = 10; tmpc <= 35; tmpc++)
                {
                    f[i][tmpc][st] = all1 - f[i - 1][tmpc][st] + all0;
                }
            }

            for (int st = 0; st < 8; st++) // daxie
            {
                int all0 = 0, all1 = 0;

                if ((st & 1) == 0)
                {
                    continue;
                }
                for (int j = 0; j < 62; j++)
                {

                    all1 += f[i - 1][j][st];
                    all0 += f[i - 1][j][st ^ 1];
                }
                for (int tmpc = 36; tmpc <= 61; tmpc++)
                {
                    f[i][tmpc][st] = all1 - f[i - 1][tmpc][st] + all0;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 62; i++)
    {
        ans += f[n][i][7];
    }
    cout << ans << endl;
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
