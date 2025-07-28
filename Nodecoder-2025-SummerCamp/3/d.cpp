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
#define MOD 998244353

using namespace std;

int n, a;
string s;
void solve()
{
    cin >> n >> a;
    cin >> s;

    int ison = 0;
    int cnt0 = 0, cnt1 = 0;
    int max0 = 0, max1 = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            ison++;
            cnt1++;
            cnt0 = 0;
        }
        else
        {
            cnt1 = 0;
            cnt0++;
        }
        max0 = max(max0, cnt0);
        max1 = max(max1, cnt1);
    }

    if (max0 > a)
    {
        cout << n << endl;
    }
    else if (max1 >= a)
    {
        cout << n << endl;
    }
    else
    {
        cout << ison << endl;
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
