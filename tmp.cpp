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
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 5);
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == maxn)
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}