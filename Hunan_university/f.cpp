#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int arr[100005] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    int ok = 1;
    if (arr[1] % 2 == 0)
    {
        ok = 0;
    }
    if (arr[n] % 2 == 0)
    {
        ok = 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            ok = 0;
        }
    }
    if (ok == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
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