

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

double ans[100005] = {0};
double preans[100005] = {0};
void solve()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(10) << ans[n] << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        ans[i] = (preans[i - 1] + i) / i;
        preans[i] = preans[i - 1] + ans[i];
    }
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}