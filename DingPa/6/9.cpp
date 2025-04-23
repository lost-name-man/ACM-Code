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

int n, k;
vector<int> pre;

int qpow(int x, int p)
{
    int base = x, sum = 1;
    while (p)
    {
        if (p & 1)
        {
            sum *= base;
            sum %= MOD;
        }
        base = base * base;
        base %= MOD;
        p = p >> 1;
    }

    return sum % MOD;
}

int inv(int x)
{
    int ret = qpow(x, MOD - 2) % MOD;
    return ret;
}

vector<vector<int>> dp;

void solve()
{

    cin >> n >> k;
    pre = vector<int>(n + 5, 0);
    dp = vector<vector<int>>(n + 5, vector<int>(2, 0));
    dp[1][0] = 21;
    dp[1][1] = 5;
    pre[1] = 21;
    for (int i = 2; i <= n; i++)
    {
        int l = max(i - k + 1, (int)1) - 1;
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][1]) % MOD) * 21;
        pre[i] = pre[i - 1] + dp[i][0];
        int sq = (((pre[i - 1] - pre[l - 1]) + MOD) % MOD * (i - 1 - l + 1)) % MOD % MOD;

        sq = ((sq - ((pre[i - 1] - pre[l - 1]) + MOD) % MOD) + MOD) % MOD;
        sq = sq * inv(2) % MOD;
        sq = ((sq + (pre[i - 1] - pre[l - 1])) + MOD) % MOD;
        dp[i][1] = (dp[i][1] + sq * 5) % MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
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