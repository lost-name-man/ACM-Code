#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;
void solve()
{
    int x, y;
    cin >> x >> y;

    int cx = x, cy = y;

    int cnt = 0;
    int ans = INF;
    for (int i = 0; i <= 10; i++)
    {
        cx = x - i;
        if (cx < 1)
        {
            break;
        }
        int ok = 1;
        while ((cy + cx) % 10 != (cy - cx) % 10)
        {
            cy--;
            if (cy < cx || abs(y - cy) > 10)
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            ans = min(ans, abs(y - cy) + abs(x - cx));
        }

        ok = 1;
        while ((y + x) % 10 != (y - x) % 10)
        {
            cy++;
            if (cy > 1e9 || abs(y - cy))
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            ans = min(ans, abs(y - cy) + abs(x - cx));
        }
    }

    for (int i = 0; i <= 10; i++)
    {
        cx = x + i;
        if (cx > 1e9)
        {
            break;
        }
        cy = max(y, cx);

        int ok = 1;
        while ((cy + cx) % 10 != (cy - cx) % 10)
        {
            cy--;
            if (cy < cx || abs(y - cy))
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            ans = min(ans, abs(y - cy) + abs(x - cx));
        }

        ok = 1;
        while ((cy + cx) % 10 != (cy - cx) % 10)
        {
            cy++;
            if (cy > 1e9 || abs(y - cy))
            {
                ok = 0;
                break;
            }
        }
        if (ok == 1)
        {
            ans = min(ans, abs(y - cy) + abs(x - cx));
        }
    }

    cout << ans << endl;
}
signed main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}