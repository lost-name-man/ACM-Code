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

const int N = 1000005;
const int M = N * 2;
using namespace std;

void solve()
{

    int k, c, d, e, f;
    cin >> k >> c >> d >> e >> f;
    int ans = 0;

    map<int, int> posb_a;
    for (int bval = 0; bval <= 10006; bval++)
    {
        int aval = (bval * bval * bval) * c + (bval * bval) * d + bval * e + f;
        posb_a[aval] = bval;
    }

    if (c == 0 && d == 0 & e == 0)
    {
        int ok = 1;
        while (f)
        {
            if (f % 27 == 0)
            {
                ok = 0;
            }
            f /= 27;
        }
        if (ok == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return;
    }
    for (auto iter = posb_a.begin(); iter != posb_a.end(); iter++)
    {
        int nowa = iter->first;
        int nowb = iter->second;

        vector<int> as;
        int ok = 1;
        while (nowa)
        {
            if (nowa % 27 == 0)
            {
                ok = 0;
            }
            as.push_back(nowa % 27);
            nowa /= 27;
        }

        if (ok == 0 || as.size() == 0 || as.size() > k)
        {
            continue;
        }

        int bval = 0;
        int base = 1;
        for (int i = 0; i < as.size(); i++)
        {
            bval += as[i] * base;
            bval %= 10007;
            base *= 10;
        }
        if (bval == nowb)
        {
            ans++;
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