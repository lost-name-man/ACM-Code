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
int pick[55] = {0};

vector<int> linebase;

void base_insert(int x)
{
    for (int i = 63; i >= 0; i--)
    {
        if (x & (1ll << i))
        {
            if (linebase[i])
            {
                x ^= linebase[i];
            }
            else
            {
                linebase[i] = x;
                break;
            }
        }
    }
}
void getmax()
{
    linebase = vector<int>(65);
    for (int i = 1; i <= n; i++)
    {
        if (pick[i])
        {
            base_insert(arr[i]);
        }
    }
    int maxn = 0;
    for (int i = 63; i >= 0; i--)
    {
        maxn = max(maxn, maxn ^ linebase[i]);
    }
    ans = max(ans, maxn);
}
void dfs(int nowindex)
{
    pick[nowindex] = 1;
    if (nowindex + 2 > n)
    {
        getmax();
    }
    if (nowindex + 2 <= n)
    {
        dfs(nowindex + 2);
    }
    if (nowindex + 3 <= n)
    {
        dfs(nowindex + 3);
    }
    pick[nowindex] = 0;
}
void solve()
{
    ans = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    dfs(1);
    if (n > 1)
    {
        dfs(2);
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

/*

1
50
999999999999999998 1 999999999999999997
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999997
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999997
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999997
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999997
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998
999999999999999998


*/