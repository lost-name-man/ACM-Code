#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {

        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                swap(arr[i], arr[i / j]);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
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