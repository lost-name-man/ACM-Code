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

int qpow(int n, int p)
{
    int base = n, sum = 1;
    while (p)
    {
        if (p & 1)
        {
            sum *= base;
            sum %= MOD;
        }
        base *= base;
        base %= MOD;
        p >>= 1;
    }
    return sum;
}

int inv(int x)
{
    return qpow(x, MOD - 2);
}
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
        cnt *= i;
        cnt %= MOD;
        cnt *= i - 1;
        cnt %= MOD;
        cnt = cnt * inv(2) % MOD;
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