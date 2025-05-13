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
#define MOD (int)(1000000007)

const int N = 1000005;
const int M = N * 2;
using namespace std;

void solve()
{
    int v, w;
    cin >> v >> w;
    // cout << v / (w / 2 + 1) + (v % (w / 2 + 1) != 0) << endl;

    int cost = (w / 2) + 1;
    int normcard = v / cost;
    int loss = v % cost;
    int ans = normcard;
    if (loss > (w - cost) || normcard == 0)
    {
        ans++;
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