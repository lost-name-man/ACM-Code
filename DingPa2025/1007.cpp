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
#define MOD 1000000000000000003

using namespace std;

int n, x;
vector<vector<int>> tree;

vector<int> val;
map<int, int> prinum;

int f[100005][150];

int stnum;
int ans = 0;
void dfs(int nownode, int fa)
{
    int nowval = val[nownode];
    for (int i = 0; i < tree[nownode].size(); i++)
    {
        int nextnode = tree[nownode][i];
        if (nextnode == fa || val[nextnode] == -1)
        {
            continue;
        }
        dfs(nextnode, nownode);
        for (int st = 0; st < stnum; st++)
        {
            int nowst = nowval | st;
            f[nownode][nowst] += f[nextnode][st];
        }
    }
    f[nownode][nowval]++;
    ans += f[nownode][stnum - 1];
}
void solve()
{

    cin >> n >> x;
    memset(f, 0, sizeof(f));
    ans = 0;
    tree = vector<vector<int>>(n + 5);
    val = vector<int>(n + 5);

    int cpx = x;
    for (int i = 2; i * i <= x; i++)
    {
        while (cpx % i == 0)
        {
            prinum[i]++;
            cpx /= i;
        }
    }

    stnum = (1 << prinum.size());
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        int cnt = 0;
        int nowval = 0;
        for (auto it = prinum.begin(); it != prinum.end(); it++)
        {
            int nownum = 0;

            while (tmp % it->first == 0)
            {
                tmp /= it->first;
                nownum++;
            }
            if (nownum == it->second)
            {
                nowval |= (1 << cnt);
            }
            else if (nownum > it->second)
            {
                nowval = -1;
                break;
            }
            cnt++;
        }
        if (tmp != 1)
        {
            nowval = -1;
        }
        val[i] = nowval;
    }

    dfs(1, 0);
    cout << ans << endl;
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