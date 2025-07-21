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
#define MOD 1000000000000000003

using namespace std;

int n, x, y;

int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    cin >> n >> x >> y;
    if (x == y)
    {
        cout << 0 << endl;
        return;
    }

    int lx = lowbit(x), ly = lowbit(y);

    int indexx, indexy;
    for (int i = 0; i < 63; i++)
    {
        if ((lx >> i) == 1)
        {
            indexx = i;
            break;
        }
    }
    for (int i = 0; i < 63; i++)
    {
        if ((ly >> i) == 1)
        {
            indexy = i;
            break;
        }
    }
    if (lx == ly)
    {
        cout << 1 << endl;
        return;
    }

    int numx = 0, numy = 0;
    {
        int tmpx = x, tmpy = y;
        while (tmpx)
        {
            if (tmpx & 1)
            {
                numx++;
            }
            tmpx >>= 1;
        }
        while (tmpy)
        {
            if (tmpy & 1)
            {
                numy++;
            }
            tmpy >>= 1;
        }
    }

    if (numx == numy)
    {
        cout << 1 << endl;
        return;
    }
    int j = abs(indexx - indexy);

    if (lx > ly) // x>>
    {
        cout << 2 << endl;
        return;
    }
    else
    {
        int cx = (x << j);
        if (cx > n)
        {
            cx = lx;
            if ((lx << j) == y)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
            }
            return;
        }
        else
        {

            cout << 2 << endl;

            return;
        }
    }
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