#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 1e9 + 7;
int n, m;
vector<vector<int>> g;
vector<int> vis;
vector<pair<int, int>> twop;
int excir = 0;
int nochain = 0;
void findc(int nownode, int fa)
{
    if (excir == 1)
    {
        return;
    }
    if (vis[nownode] == 1)
    {
        excir = 1;
        return;
    }
    vis[nownode] = 1;

    for (int i = 0; i < g[nownode].size(); i++)
    {
        int nextnode = g[nownode][i];
        if (twop[nextnode].first == 1)
        {
            twop[nownode].second++;
        }
        if (nextnode == fa)
        {
            continue;
        }

        findc(nextnode, nownode);
    }
    if (twop[nownode].second > 2)
    {
        nochain = 1;
    }
}

int mul[200005];
void init()
{
    int base = 1;
    mul[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        mul[i] = mul[i - 1] * i % MOD;
    }
}
void solve()
{

    cin >> n >> m;
    nochain = 0;
    excir = 0;
    g = vector<vector<int>>(n + 5, vector<int>());
    vis = vector<int>(n + 5);
    twop = vector<pair<int, int>>(n + 5);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int twocnt = 0;

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() >= 2)
        {
            twocnt++;
            twop[i].first = 1;
        }
        else
        {
            twop[i].first = 0;
        }
    }
    findc(1, 0);
    if (excir == 1 || nochain == 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 2 && m == 1)
    {
        cout << 2 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {

        if (twop[i].first == 0)
        {
            continue;
        }
        if (twop[i].second == 0)
        {
            cout << mul[g[i].size()] * 2 % MOD << endl;
            return;
        }
        else if (twop[i].second == 1)
        {
            ans *= mul[g[i].size() - 1];
            ans %= MOD;
        }
        else
        {
            ans *= mul[g[i].size() - 2];
            ans %= MOD;
        }
    }
    ans = ans * 4 % MOD;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
