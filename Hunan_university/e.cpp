#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int n;
string str;

void solve()
{
    cin >> n;
    cin >> str;

    int ok = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i] != str[i - 1])
        {
            ok = 1;
        }
    }
    if (ok == 0)
    {
        cout << "-1" << endl;
        return;
    }

    int st;
    vector<int> bans(2 * n + 10, -1);
    vector<int> ans(n + 5);
    for (int i = 1; i < n; i++)
    {
        if (str[i] != str[i - 1])
        {
            st = i;
            break;
        }
    }
    string bstr = str + str;
    int maxn = n - 1, minn = 0;
    for (int i = st; i < st + n; i++)
    {
        if (bstr[i] == '0')
        {
            bans[i] = minn;
            minn++;
        }
        else
        {
            bans[i] = maxn;
            maxn--;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (bans[i] != -1)
        {
            ans[i % n] = bans[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << ' ';
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}