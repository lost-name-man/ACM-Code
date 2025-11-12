#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int n;
vector<int> arr, brr, crr;

bool p(int num)
{
    vector<int> pre(n + 5);
    // int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            if (brr[i] >= num)
            {
                pre[1]++;
                pre[n + 1]--;
            }
            continue;
        }
        double lx = (num - brr[i]) * 1.0 / arr[i];

        if (arr[i] > 0)
        {
            int lindex = (lower_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
            pre[lindex]++;
            pre[n + 1]--;
        }
        else
        {
            int rindex = upper_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin();
            pre[1]++;
            pre[rindex]--;
        }
    }
    int stdnum = n / 2 + (n & 1);
    int nownum = 0;
    for (int i = 1; i <= n; i++)
    {
        nownum += pre[i];
        if (nownum >= stdnum)
        {
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin >> n;
    arr = brr = crr = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> crr[i];
    }
    sort(crr.begin() + 1, crr.begin() + 1 + n);

    int l = -2 * (1e18), r = 2 * 1e18;
    int ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (p(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
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
