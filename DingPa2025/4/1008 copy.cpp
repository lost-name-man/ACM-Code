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
const int MOD = 998244353;

void solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> arr(n + 5, 0);
    map<int, int> val_num;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        val_num[arr[i]]++;
    }
    val_num[0]++;
    vector<int> brr;
    while (val_num.size() > 1)
    {
        for (auto iter = val_num.begin(); iter != val_num.end();)
        {

            brr.push_back(iter->first);
            iter->second--;

            if (iter->second == 0)
            {
                iter = val_num.erase(iter);
            }
            else
            {

                iter++;
            }
        }
    }

    int ans = 0;

    if (val_num.size() == 1)
    {
        ans += val_num.begin()->second * y;
    }

    for (int i = 1; i < brr.size(); i++)
    {

        // cout << "!" << brr[i] << endl;

        if (brr[i] > brr[i - 1])
        {
            ans += x;
        }
        else if (brr[i] == brr[i - 1])
        {
            ans += y;
        }
        else
        {
            ans += z;
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
