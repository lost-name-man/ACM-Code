#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int z0, h, xa, ya, xb, yb;

bool checkx(int x)
{
    if (xa > xb)
    {
        swap(xa, xb);
    }
    if (x >= xa && x <= xb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool checky(int y)
{
    if (ya > yb)
    {
        swap(ya, yb);
    }
    if (y >= ya && y <= yb)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> z0 >> h >> xa >> ya >> xb >> yb;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z < z0 || z > z0 + h)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (checkx(x) && checky(y))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
signed main()
{
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}