

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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

long long qpower(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exp)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int inv(int x)
{
    return qpower(x, MOD - 2, MOD) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    // map<int, int>
    vector<int> arr(n + 5);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        ans += arr[i];
    }

    // for(int i=1; i<=n; i++)
    // {
    //     ans+=arr[i];
    //     if(i!=1)
    //     {
    //         ans=ans*inv(2)%MOD;
    //     }
    // }

    ans = ans * inv(n) % MOD;

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