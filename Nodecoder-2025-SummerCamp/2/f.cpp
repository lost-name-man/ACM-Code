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

int n, t;
string s;
void solve()
{
    cin >> n >> t;

    cin >> s;

    int index;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            s += '0';
        }
        else
        {
            s += '1';
            index = i;
            break;
        }
    }

    s.assign(s.begin() + index, s.end());

    int maxn = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            cnt++;
        }
        else
        {
            ans += max(0ll, cnt - t * 2);
            cnt = 0;
        }
        maxn = max(maxn, cnt);
    }
    cout << ans - max(0ll, maxn - t * 2) + max(0ll, maxn - 1 - t) << endl;
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
