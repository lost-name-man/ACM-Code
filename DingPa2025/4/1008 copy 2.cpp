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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> arr(n + 5, 0);

    vector<int> num(n + 5, 0);
    int max1 = 0, max2 = 0;

    num[0]++;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        num[arr[i]]++;
    }

    vector<int> eq;
    for (int i = 0; i <= n; i++)
    {
        if (num[i] > 1)
        {
            eq.push_back(num[i] - 1);
        }
    }

    sort(eq.begin(), eq.end());
    sort(arr.begin() + 1, arr.begin() + 1 + n);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        // cout << "!" << brr[i] << endl;

        if (arr[i] > arr[i - 1])
        {
            ans += x;
        }
        else if (arr[i] == arr[i - 1])
        {
            ans += y;
        }
        else
        {
            ans += z;
        }
    }

    int tmpans = ans;
    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(eq.begin(), eq.end(), i);
        if (it == eq.end())
        {
            break;
        }

        int base = (eq.end() - it - 1);
        tmpans += x * base;
        tmpans += z;
        tmpans -= (base + 1) * y;
        ans = max(ans, tmpans);
    }

    cout << max(ans, tmpans) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
