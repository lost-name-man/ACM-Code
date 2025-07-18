#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;
const int X = 50000000;
const int N = 10000;

int f[3][10004];

void init()
{

    for (int i = 3; i <= N; i++)
    {
        int sum1 = pow(10, i - 3);

        int sum66no666 = sum1 - f[2][i - 1];
        f[0][i] = (f[0][i - 1] * 9 + f[1][i - 1] + f[2][i - 1]);
        f[1][i] = f[0][i - 1];
        f[2][i] = f[1][i - 1] + f[2][i - 1] + sum66no666;
        if (f[0][i] > X)
        {
            break;
        }
    }
}
void solve()
{

    vector<int> ans;
    int x;
    int cpx;
    cin >> x;
    int maxn;
    for (int i = 1; i <= N; i++)
    {
        int ok = 0;
        for (int j = 1; j <= 9; j++)
        {
            if (j != 6)
            {
                if (f[0][i] >= x)
                {
                    maxn = i;
                    ans.push_back(j);
                    ok = 1;
                    break;
                }
                else
                {
                    x -= f[0][i];
                }
            }
            else
            {
                if (f[1][i] + f[2][i] >= x)
                {
                    maxn = i;
                    ans.push_back(j);
                    ok = 1;
                    break;
                }
                else
                {
                    x -= f[1][i] + f[2][i];
                }
            }
        }
        if (ok == 1)
        {
            break;
        }
    }

    for (int i = 2; i <= maxn; i++)
    {
        int last = ans[i - 2];
        if (x == 1 && i == maxn)
        {
            ans.push_back(6);
            break;
        }
        for (int j = 0; j <= 9; j++)
        {
            int nowlen = maxn - i + 1;
            if (last != 6)
            {
                if (j != 6)
                {
                    if (f[0][nowlen] >= x)
                    {
                        ans.push_back(j);
                        break;
                    }
                    else
                    {
                        x -= f[0][nowlen];
                    }
                }
                else
                {

                    if (f[1][nowlen] + f[2][nowlen] >= x)
                    {
                        ans.push_back(j);
                        break;
                    }
                    else
                    {
                        x -= f[1][nowlen] + f[2][nowlen];
                    }
                }
            }
            else
            {
                if (j != 6)
                {
                    if (f[0][nowlen] >= x)
                    {
                        ans.push_back(j);
                        break;
                    }
                    else
                    {
                        x -= f[0][nowlen];
                    }
                }
                else
                {

                    if (f[2][nowlen + 1] >= x)
                    {
                        ans.push_back(j);
                        break;
                    }
                    else
                    {
                        x -= f[2][nowlen + 1];
                    }
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;
    init();
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}