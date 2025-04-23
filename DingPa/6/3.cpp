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
#define INF 1e9
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        arr[i].first = a;
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        arr[i].second = a;
    }
    int r = 1;
    int sum = 0;
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        while (arr[r].first + arr[r].second == arr[l].first + arr[l].second)
        {

            sum += arr[r].first;

            r++;
        }
        ans = max(ans, sum * (r - l));
        sum -= arr[l].first;
    }
    cout << ans << endl;
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