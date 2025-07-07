#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int arr[100005] = {0};
int prearr[200005];
int n;
void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        prearr[i] = prearr[i - 1] + arr[i];
    }

    int minpre = INF;
    for (int i = 2 * n; i >= n + 1; i--)
    {
        minpre = min(minpre, prearr[i]);
    }

    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        minpre = min(minpre, prearr[i]);
        int nowmin = minpre - prearr[i - 1];
        if (nowmin >= 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}