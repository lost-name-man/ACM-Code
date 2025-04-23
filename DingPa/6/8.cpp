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
#define MOD (int)(1000000007)

const int N = 1000005;
const int M = N * 2;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int num;
    cin >> num;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int nexn;
        cin >> nexn;
        ans += num * nexn;
        ans %= MOD;
        num += nexn;
        num %= MOD;
    }
    int cnt = 1;
    for (int i = n; i >= 2; i--)
    {
        cnt *= i * (i - 1) / 2;
        cnt %= MOD;
    }

    cout << ans << ' ' << cnt << endl;
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