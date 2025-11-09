#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int a, b;
int maxop;
int ans;
int checkans(int num, int a, int b)
{
    int cnt = 0;
    for (int i = 1; i <= ans; i++)
    {
        int nowgcd = __gcd(a, b);
        a /= nowgcd;
        b /= nowgcd;
        if (a == 1 || b == 1)
        {
            cnt += 2;
            break;
        }
        if (num & 1)
        {
            a--;
        }
        else
        {
            b--;
        }
        num >>= 1;
        cnt++;
        if (a == 1 || b == 1)
        {
            cnt += 2;
            break;
        }
    }
    return cnt;
}

void dfs(int a, int b, int deep)
{
    if (deep >= ans - 2)
    {
        return;
    }

    int nowgcd = __gcd(a, b);
    a /= nowgcd;
    b /= nowgcd;
    if (a == 1 || b == 1)
    {
        ans = min(ans, deep + 2);
        return;
    }
    dfs(a - 1, b, deep + 1);
    dfs(a, b - 1, deep + 1);
}

void solve()
{
    cin >> a >> b;

    maxop = log2(a) * 2 + 2;
    ans = maxop;
    dfs(a, b, 0);
    cout << ans << endl;

    // int nowgcd = __gcd(a, b);
    // a /= nowgcd;
    // b /= nowgcd;
    // if (a == 1 || b == 1)
    // {
    //     cout << 2 << endl;
    //     return;
    // }
    // maxop = log2(a) * 2 + 1;
    // ans = maxop;
    // for (int i = 0; i < (1ll << maxop); i++)
    // {
    //     ans = min(ans, checkans(i, a, b));
    // }
    // cout << ans << endl;
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
