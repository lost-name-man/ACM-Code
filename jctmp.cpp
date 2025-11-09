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

// void dfs(int a, int b, int deep)
// {
//     if(deep >= ans)
//     {
//         return;
//     }
//     if(a==1 || b==1)
//     {
//         ans=min(ans,deep+2);
//         return;
//     }
// }

void solve()
{
    cin >> a >> b;

    int nowgcd = __gcd(a, b);
    a /= nowgcd;
    b /= nowgcd;
    if (a == 1 || b == 1)
    {
        cout << 2 << endl;
        return;
    }
    maxop = log2(a) * 2 + 1;
    ans = maxop;
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
