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

    for (int i = 1; i <= n; i++)
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
                for (int j = 0; j < 62; j++)
                {
                    if (nowc == j)
                    {
                        continue;
                    }
                    sum0 += f[i - 1][j][st];
                    sum1 += f[i - 1][j][st ^ 1];
                }
                if ((st & 1) == 0)
                {
                    continue;
                }
                else
                {

                    f[i][nowc][st] += sum0 + sum1;
                }
            }
        }
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
