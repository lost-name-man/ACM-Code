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

using namespace std;

int n;
int arr[500005];
int num[1000006];
vector<int> yue[500005];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        num[arr[i]]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int nownum = arr[i];
        for (int j = 0; j < yue[nownum].size(); j++)
        {
            ans += num[yue[nownum][j]];
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

    for (int i = 1; i <= 500000; i++)
    {
        for (int j = i; j <= 500000; j += i)
        {
            yue[j].push_back(i);
        }
    }
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}