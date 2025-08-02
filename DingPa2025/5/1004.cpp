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
const int INF = 1e16 + 7;
const int MOD = 1e9 + 7;

struct Node
{
    int numk;
    int less;
};
bool cmp(Node &a, Node &b)
{
    return a.less > b.less;
}

int n, m, k, p;

vector<int> arr;
vector<Node> node;

bool check(int x)
{
    vector<int> vis(n + 5);
    int top = x, sump = x * p;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        vis[i] = min({x, node[i].numk, sump});
        sump -= vis[i];
        ans += vis[i] * k;
        if (sump == 0)
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (sump == 0)
        {
            break;
        }
        if (x > node[i].numk)
        {
            ans += node[i].less;
            sump--;
        }
    }
    if (ans >= m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n >> m >> k >> p;
    arr = vector<int>(n + 5);
    node = vector<Node>(n + 5);
    int sum_k = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        node[i].numk = arr[i] / k;
        node[i].less = arr[i] % k;
    }

    sort(node.begin() + 1, node.begin() + 1 + n, cmp);
    int l = 1, r = m, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
