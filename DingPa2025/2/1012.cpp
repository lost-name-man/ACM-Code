#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000007

using namespace std;

int n;
int arr[55];
int ans = 0;
int dfs(int nowindex, int lastval)
{
    int nowval = lastval ^ arr[nowindex];
    ans = max(ans, nowval);
    for (int i = 2; i <= n; i++)
    {
        if (nowindex + i > n)
        {
            break;
        }
        dfs(nowindex + i, nowval);
    }
}
void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
    cout << ans << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}