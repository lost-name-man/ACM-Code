#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int a, b;
int maxop;
int checkans(int num, int a, int b)
{
    int cnt = 0;
    for (int i = 1; i <= maxop; i++)
    {
        if (num & 1)
        {
            a -= __gcd(a, b);
        }
        else
        {
            b -= __gcd(a, b);
        }
        num >>= 1;
        cnt++;
        if (a == 0 || b == 0)
        {
            cnt++;
            break;
        }
    }
    return cnt;
}

void dfs(int a, int b, int deep)
{
}

void solve()
{
    cin >> a >> b;
    int ans = 30;

    maxop = log2(a) * 2 + 2;
    for (int i = 0; i < (1ll << maxop); i++)
    {
        ans = min(ans, checkans(i, a, b));
    }
    cout << ans << endl;
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
