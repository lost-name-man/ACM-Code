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
const int MOD = 1e9 + 7;

string s1, s2;
int f[88][88];
vector<pair<int, int>> g[88][88];
vector<string> ans;

string anstring;
void dfs(pair<int, int> nownode)
{
    if (nownode.first == 0)
    {
        string cs;
        cs.assign(anstring.rbegin(), anstring.rend());
        ans.push_back(cs);
        return;
    }
    anstring.push_back(s1[nownode.first]);
    for (int i = 0; i < g[nownode.first][nownode.second].size(); i++)
    {
        pair<int, int> nextnode = g[nownode.first][nownode.second][i];
        dfs(nextnode);
    }
    anstring.erase(anstring.end() - 1);
}
void solve()
{
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    s1 = '0' + s1;
    s2 = '0' + s2;

    int lcs = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i] != s2[j])
            {
                continue;
            }
            int maxn = 0;
            for (int li = 0; li < i; li++)
            {
                for (int lj = 0; lj < j; lj++)
                {
                    if (s1[li] != s2[lj])
                    {
                        continue;
                    }
                    maxn = max(maxn, f[li][lj]);
                }
            }
            f[i][j] = maxn + 1;
            lcs = max(lcs, f[i][j]);
            for (int li = 0; li < i; li++)
            {
                for (int lj = 0; lj < j; lj++)
                {
                    if (s1[li] != s2[lj])
                    {
                        continue;
                    }
                    if (f[li][lj] == maxn)
                    {
                        g[i][j].push_back({li, lj});
                    }
                }
            }
        }
    }

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (f[i][j] == lcs)
            {
                pair<int, int> node = {i, j};
                dfs(node);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0 && ans[i] == ans[i - 1])
        {
            continue;
        }
        else
        {
            cout << ans[i] << endl;
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
