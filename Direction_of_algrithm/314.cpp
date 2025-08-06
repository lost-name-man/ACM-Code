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
const int INF = 1e18;
const int MOD = 1e9 + 7;

struct Node
{
    int num;
    int maxlen;
};

int n;
vector<int> arr;
vector<Node> f;

void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    f = vector<Node>(n + 5);
    int maxn = 0;
    f[0].num = 1;
    arr[0] = INF;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                f[i].maxlen = max(f[i].maxlen, f[j].maxlen + 1);
            }
            if (arr[j] == arr[i])
            {
                f[j].num = 0;
            }
        }
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j] && f[j].maxlen == f[i].maxlen - 1)
            {
                f[i].num += f[j].num;
            }
        }
        maxn = max(maxn, f[i].maxlen);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i].maxlen == maxn)
        {
            ans += f[i].num;
        }
    }
    cout << maxn << ' ' << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    // cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
