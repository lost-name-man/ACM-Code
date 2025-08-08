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

void solve()
{
    int n;
    cin >> n;

    vector<int> ccc;
    vector<int> mygo;
    for (int i = 1; i <= n; i++)
    {
        int num, is_path;
        cin >> num >> is_path;
        if (is_path)
        {
            ccc.push_back(num);
        }
        else
        {
            mygo.push_back(num);
        }
    }

    int ans = 0;

    for (int i = 0; i < ccc.size(); i++)
    {
        int ret = 0;
        int num = ccc[i];
        if(num==3)
        {
            ret=2;
        }
        else if (num % 4 == 0)
        {
            ret = 0;
        }
        else if (num % 4 == 1)
        {
            ret = 1;
        }
        else if (num % 4 == 2)
        {
            ret = 1;
        }
        else
        {
            ret = 3;
        }
        ans = ans ^ ret;
    }

    for (int i = 0; i < mygo.size(); i++)
    {
        int ret = 0;
        int num = mygo[i];

        if (num >= 3)
        {
            if (num % 4 == 3)
            {
                ret = 1;
            }
            else
            {
                ret = 0;
            }
        }
        else
        {
            ret=1;
        }

        ans = ans ^ ret;
    }

    if (ans == 0)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
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
