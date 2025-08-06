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
const int MOD = 11380;

int num[7];

void solve()
{
    while (1)
    {
        int ok = 0;
        int sum = 0;
        for (int i = 1; i <= 6; i++)
        {
            cin >> num[i];
            sum += num[i] * i;
            if (num[i])
            {
                ok = 1;
            }
        }
        if (ok == 0)
        {
            break;
        }

        if (sum % 2 == 1)
        {
            cout << "Can't" << endl;
            continue;
        }
        /////

        int m = sum / 2;
        vector<int> item, f(m + 5, 0);
        for (int i = 1; i <= 6; i++)
        {
            int k = 1;
            int nownum = num[i];
            while (k <= nownum)
            {
                item.push_back(i * k);
                nownum -= k;
                k *= 2;
            }
            if (nownum)
            {
                item.push_back(i * nownum);
            }
        }
        f[0] = 1;
        for (int i = 0; i < item.size(); i++)
        {
            int nowval = item[i];
            for (int j = m; j >= 0; j--)
            {
                if (j - nowval < 0)
                {
                    break;
                }
                f[j] |= f[j - nowval];
            }
        }
        if (f[m])
        {
            cout << "Can" << endl;
        }
        else
        {
            cout << "Can't" << endl;
        }
    }
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
