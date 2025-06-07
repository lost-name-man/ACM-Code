#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
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
#include <iomanip>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;

vector<int> val(1000006, 0);

void solve()
{
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (sum >= (1ll << i) * n)
        {
            ans |= (1ll << i);
            sum -= (1ll << i) * n;
        }
        else if (((1ll << i) - 1) * n >= sum)
        {
        }
        else
        {
            sum -= (sum / (1ll << i)) * (1ll << i);
            ans |= (1ll << i);
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