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

map<char, int> C, V;
void solve()
{
    string str1, str2;
    cin >> str1 >> str2;

    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (C[str1[i]] == 1)
        {
            if (str1[i + 1] == 'y')
            {
                i += 2;
                ans1++;
            }
            else if (V[str1[i + 1]] == 0)
            {
                if (str1[i + 1] == 'n')
                {
                    i++;
                    ans1++;
                }
                else
                {
                    ans1++;
                }
            }
            else
            {
                i++;
                ans1++;
            }
        }
        else
        {
            if (str1[i] == 'y')
            {
                i++;
                ans1++;
            }
            else
            {
                ans1++;
            }
        }
    }

    for (int i = 0; i < str2.size(); i++)
    {
        if (C[str2[i]] == 1)
        {
            if (str2[i + 1] == 'y')
            {
                i += 2;
                ans2++;
            }
            else if (V[str2[i + 1]] == 0)
            {
                if (str2[i + 1] == 'n')
                {
                    i++;
                    ans2++;
                }
                else
                {
                    ans2++;
                }
            }
            else
            {
                i++;
                ans2++;
            }
        }
        else
        {
            if (str2[i] == 'y')
            {
                i++;
                ans2++;
            }
            else
            {
                ans2++;
            }
        }
    }
    cout << ans1 << ' ' << ans2 << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    ////
    C['k'] = 1;
    C['g'] = 1;
    C['s'] = 1;
    C['z'] = 1;
    C['t'] = 1;
    C['d'] = 1;
    C['n'] = 1;
    C['h'] = 1;
    C['b'] = 1;
    C['p'] = 1;
    C['m'] = 1;
    C['r'] = 1;
    C['w'] = 1;

    V['a'] = 1;
    V['i'] = 1;
    V['u'] = 1;
    V['e'] = 1;
    V['o'] = 1;
    V['y'] = 1;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}