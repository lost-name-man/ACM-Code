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

int n, r;
vector<int> arr;

int fun(int h, int) void solve()
{
    cin >> n >> r;
    arr = vector<int>(n + 5);
    vector<int> arr_id(n + 5, 0);
    map<int, int> allrr;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        allrr[arr[i]] = 1;
        arr_id[arr[i]] = i;
    }

    int lasstmax = r;
    int lastl = 0;
    vector<int> minlim(n + 5, 0);
    for (auto iter = allrr.rbegin(); iter != allrr.rend(); iter++)
    {
        int nowmax = iter->first;
        int nowr = arr_id[nowmax];
        for (int i = lastl + 1; i <= nowr; i++)
        {
            minlim[i] = nowmax;
        }
        lastl = max(lastl, nowr);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << minlim[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        if (minlim[i] != minlim[i + 1])
        {
            for (int j = 1; j <= i; j++)
            {
            }
        }
    }
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