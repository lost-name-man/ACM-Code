#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

void solve()
{
    int a, b;
    char ch;
    string inps;
    cin >> inps;
    a = inps[0] - '0';
    b = inps[2] - '0';
    ch = inps[1];

    double r = 50;
    double rlen = 3.1415926535 * r * 2;
    if (ch == '-')
    {
        int dis = abs(a - b);
        if (dis > 4)
        {
            dis = 8 - dis;
        }
        if (dis == 4)
        {
            cout << 100 << endl;
            return;
        }
        double rad = dis * 45 / 360.0 * 3.1415926535 * 2;
        cout << fixed << setprecision(10) << sin(rad / 2) * 50 * 2 << endl;
    }
    else if (ch == '>')
    {
        if (a > b)
        {
            b += 8;
        }
        cout << fixed << setprecision(10) << rlen * (b - a) / 8.0 << endl;
    }
    else if (ch == '<')
    {
        if (a < b)
        {
            a += 8;
        }
        cout << fixed << setprecision(10) << rlen * (a - b) / 8.0 << endl;
    }
    else
    {
        cout << 100 << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}