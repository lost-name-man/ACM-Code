#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
#define int long long

const int INF = 1e18 + 7;
const int MOD = 0;
const double ESP = 1e-18;
int n;
vector<int> arr, brr, ans, num0, sum;

vector<map<int, int>> mp;
vector<vector<int>> tree;

void dfs(int nownode, int fa)
{
    num0[nownode] += (arr[nownode] == 0) + (brr[nownode] == 0);

    int cnt = 0;
    if (arr[nownode] != 0)
    {
        mp[nownode][arr[nownode]]++;
    }
    if (brr[nownode] != 0)
    {
        mp[nownode][brr[nownode]]--;
    }

    sum[nownode] += abs(mp[nownode][arr[nownode]]);
    sum[nownode] += abs(mp[nownode][brr[nownode]]);
    int znum = 0;

    for (int i = 0; i < tree[nownode].size(); i++)
    {
        int nextnode = tree[nownode][i];
        if (nextnode == fa)
        {
            continue;
        }
        dfs(nextnode, nownode);

        num0[nownode] += num0[nextnode];
        sum[nownode] += sum[nextnode];
        if (mp[nownode].size() <= mp[nextnode].size())
        {
            swap(mp[nownode], mp[nextnode]);
        }

        for (auto it = mp[nextnode].begin(); it != mp[nextnode].end(); it++)
        {
            int nownum = it->first;
            int tmp = mp[nownode][nownum];
            mp[nownode][nownum] += it->second;
            sum[nownode] -= abs(tmp) + abs(it->second) - abs(mp[nownode][nownum]);
        }
    }

    if (num0[nownode] >= sum[nownode])
    {
        ans[nownode] = 1;
    }
    else
    {
        ans[nownode] = 0;
    }
}
void solve()
{
    cin >> n;
    arr = brr = ans = num0 = sum = vector<int>(n + 5);
    mp = vector<map<int, int>>(n + 5);
    tree = vector<vector<int>>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i];
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}