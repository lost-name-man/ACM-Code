#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 998244353;

int n;

vector<int> arr;
int mul[1000006];
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    if (n == 1)
    {
        cout << 0 << ' ' << 1 << endl;
        return;
    }
    sort(arr.begin() + 1, arr.begin() + 1 + n);

    int ans1 = 0, ans2 = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            ans1 += (arr[j] - arr[i]);
        }
    }

    if (mp.size() > 1)
    {
        ans2 *= 2;
        ans2 %= MOD;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans2 *= mul[it->second];
        ans2 %= MOD;
    }
    cout << ans1 << ' ' << ans2 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    mul[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        mul[i] = mul[i - 1] * i;
        mul[i] %= MOD;
    }
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
