#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e16 + 7;
const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 5, 0);
    int l = 0, r = 1;
    int L = INF, R = -1 * INF;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (l == 0 && arr[i] != 0)
        {
            l = i;
        }
        if (arr[i] != 0)
        {
            r = i;
        }
    }
    
    for (int i = l; i <= r; i++)
    {

        L = min(arr[i], L);
        R = max(R, arr[i]);
    }

    if (l == 0)
    {
        int ans = n * (n + 1) / 2;
        ans %= MOD;
        ans *= ((n+1)*(n+1)) % MOD;
        ans%=MOD;
        cout << sum << " ";
        cout << ans << endl;
        return;
    }

    int ldv = l - 1 + 1;
    int rdv = n - r + 1;
    int Ldv = L - (-n) + 1;
    int Rdv = n - R + 1;

    // cout << l << " " << r << " " << L << " " << R << endl;

    int ans = ldv * rdv;
    ans %= MOD;
    ans *= Ldv;
    ans %= MOD;
    ans *= Rdv;
    ans %= MOD;

    cout << sum << " ";
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
