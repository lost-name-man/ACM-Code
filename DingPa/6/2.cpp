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

const int N = 1000005;
const int M = N * 2;
using namespace std;

int n, x;
int arr[100005];
vector<int> pre;

bool p(int len)
{
    if (len == 0)
    {
        return pre[n] <= x;
    }
    int minn = INF;
    deque<int> dq;
    for (int i = 1; i <= len - 1; i++)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        int r = i + len - 1;
        if (r > n)
        {
            break;
        }

        while (!dq.empty() && arr[dq.back()] <= arr[r])
        {
            dq.pop_back();
        }
        while (!dq.empty() && dq.front() < l)
        {
            dq.pop_front();
        }
        dq.push_back(r);
        int nowmax = arr[dq.front()];

        int suml = pre[l - 1];
        int sumr = pre[n] - pre[r + 1];
        minn = min(minn, suml + sumr + abs(nowmax - arr[l - 1]) * (l - 1 >= 1) + abs(nowmax - arr[r + 1]) * (r + 1 <= n));
    }
    return minn <= x;
}
void solve()
{

    cin >> n >> x;
    pre = vector<int>(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 2; i <= n; i++)
    {
        pre[i] += pre[i - 1] + abs(arr[i] - arr[i - 1]);
    }
    pre[n + 1] = pre[n];
    int l = 0, r = n;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (p(mid))
        {
            r = mid - 1;
            ans = mid;
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