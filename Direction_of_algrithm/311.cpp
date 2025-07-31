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

int f[11][100][100][100];

int getmod(int x, int mod)
{
    return (x % mod + mod) % mod;
}

int mypow10[11];
void solve()
{

    for (int i = 0; i <= 10; i++)
    {
        mypow10[i] = pow(10, i);
    }
    for (int i = 1; i <= 90; i++)
    {
        f[0][0][i][0] = 1;
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int nownum = 0; nownum <= 9; nownum++)
        {
            for (int lastsum = 0; lastsum <= (i - 1) * 9; lastsum++)
            {
                for (int lastmod = 1; lastmod <= 90; lastmod++)
                {
                    for (int lastless = 0; lastless <= 90; lastless++)
                    {
                        if (lastless == lastmod)
                        {
                            break;
                        }
                        f[i][lastsum + nownum][lastmod][(lastless + nownum * mypow10[i - 1]) % lastmod] += f[i - 1][lastsum][lastmod][lastless];
                    }
                }
            }
        }
    }

    // cout << "@@" << endl;

    int l, r;
    cin >> l >> r;
    l--;
    int cl = l, cr = r;
    int hl = 0, hr = 0;
    while (cr)
    {
        cr /= 10;
        hr++;
    }
    int sumr = 0;
    int premod = 0;
    int presum = 0;
    for (int i = hr; i >= 1; i--)
    {
        int nowh = (r / (int)pow(10, i - 1)) % 10;
        int len = i - 1;
        for (int j = 0; j < nowh; j++)
        {
            int nownum = j;
            for (int sum = 0; sum <= len * 9; sum++)
            {
                if (sum + nownum + premod == 0)
                {
                    continue;
                }
                sumr += f[len][sum][sum + nownum + premod][getmod(-nownum * mypow10[len] - presum, sum + nownum + premod)];
            }
        }
        premod += nowh;
        presum += nowh * mypow10[len];
    }

    cr = r;
    int tmpsum = 0;
    while (cr)
    {
        tmpsum += cr % 10;
        cr /= 10;
    }
    if (tmpsum != 0 && r % tmpsum == 0)
    {
        sumr++;
    }

    while (cl)
    {
        cl /= 10;
        hl++;
    }
    int suml = 0;
    premod = 0;
    presum = 0;
    for (int i = hl; i >= 1; i--)
    {
        int nowh = (l / (int)pow(10, i - 1)) % 10;
        int len = i - 1;
        for (int j = 0; j < nowh; j++)
        {
            int nownum = j;
            for (int sum = 0; sum <= len * 9; sum++)
            {
                if (sum + nownum + premod == 0)
                {
                    continue;
                }
                suml += f[len][sum][sum + nownum + premod][getmod(-nownum * mypow10[len] - presum, sum + nownum + premod)];
            }
        }
        premod += nowh;
        presum += nowh * pow(10, len);
    }
    cl = l;
    tmpsum = 0;
    while (cl)
    {
        tmpsum += cl % 10;
        cl /= 10;
    }
    if (tmpsum != 0 && l % tmpsum == 0)
    {
        suml++;
    }
    cout << sumr - suml << endl;
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
