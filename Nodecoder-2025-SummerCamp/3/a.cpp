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

int n;
vector<int> f;
void solve()
{
    cin >> n;
    f = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    vector<vector<int>> ans(n + 5, vector<int>(n + 5));
    ans[1][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        deque<int> q;
        for (int j = 0; j < f[i]; j++)
        {
            q.push_back(j);
        }
        for (int j = 1; j < i; j++)
        {
            if (q.empty())
            {
                ans[i][j] = 0;
                ans[j][i] = 0;
                continue;
            }
            if (f[j] == q.front())
            {
                q.push_back(q.front());
                q.pop_front();
            }
            if (f[j] == q.front())
            {
                ans[i][j] = 0;
                ans[j][i] = 0;
                continue;
            }
            ans[i][j] = q.front();
            ans[j][i] = q.front();
            q.pop_front();
        }
        if (q.empty())
        {
            ans[i][i] = 0;
        }
        else
        {
            ans[i][i] = q.front();
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
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
