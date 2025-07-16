#include <bits/stdc++.h>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;

string str;
int n, q;
void solve()
{
    cin >> n >> q;
    cin >> str;
    str = "0" + str;
    string s;
    for (int i = 1; i <= q; i++)
    {
        int indexl;
        cin >> s;
        cin >> indexl;
        s = s;
        int len = s.size();
        int ans = 0;
        int cnt = 0;
        for (int j = 0; j < len; j++)
        {
            if (s[j] != str[indexl + j])
            {
                ans += (cnt * (cnt + 1) / 2);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        ans += (cnt * (cnt + 1) / 2);
        cnt = 0;
        cout << ans << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}