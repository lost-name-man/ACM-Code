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

int n;
vector<int> arr;
vector<int> vis;

int dfs(int x)
{

    if (vis[x])
    {
        return 0;
    }
    vis[x] = 1;
    return dfs(arr[x]) + 1;
}

void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    vis = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int ans = 1;
    int oddc = 0;

    int sumeven = 0;

    int evenccnt = 1;
    vector<int> evenc;
    for (int i = 1; i <= n; i++)
    {
        int cirsize = 0;
        if (vis[i])
        {
            continue;
        }
        cirsize = dfs(i);
        if (cirsize % 2 == 1)
        {
            oddc++;
            if (oddc > 2)
            {
                cout << 0 << endl;
                return;
            }

            ans *= cirsize;
            ans %= MOD;
        }
        else
        {
            if (cirsize > 2)
            {
                evenccnt *= 2;
                evenccnt %= MOD;
            }
            evenc.push_back(cirsize);
            sumeven += cirsize;
        }
    }

    if (oddc == 0)
    {
        int ans = 0;
        for (int i = 0; i < evenc.size(); i++)
        {
            int nows = evenc[i];
            if (nows == 2)
            {
                ans += ((nows * nows / 4) % MOD * evenccnt) % MOD;
            }
            else
            {
                ans += ((nows * nows / 4) % MOD * (evenccnt / 2)) % MOD;
            }

            ans %= MOD;
        }
        cout << ans << endl;
    }
    else
    {
        ans *= evenccnt;
        ans %= MOD;
        cout << ans << endl;
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
