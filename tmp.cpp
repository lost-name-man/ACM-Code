#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 998244353;

int n;

struct Edge
{
    int from;
    int to;
    int nex;
};
vector<int> head;
vector<Edge> edge;

int tot = 1;
void add(int x, int y)
{
    tot++;
    edge[tot].from = x;
    edge[tot].to = y;
    edge[tot].nex = head[x];
    head[x] = tot;
}

vector<int> fa;
vector<int> nodenum;

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    fa[x] = findfa(fa[x]);
    return fa[x];
}
void connect(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    if (fax == fay)
    {
        return;
    }

    fa[fax] = fay;
    return;
}

int mypow(int n, int p)
{
    int base = n, re = 1;
    while (p)
    {
        if (p & 1)
        {
            re *= base;
            re %= MOD;
        }
        base *= base;
        base %= MOD;
        p >>= 1;
    }
    return re;
}

int inv(int x)
{
    return mypow(x, MOD - 2);
}

vector<vector<signed>> lfa;
vector<int> deep;
void initlca()
{
    vector<int> vis(n + 1, 0);
    deep = vector<int>(n + 5);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    deep[1] = 1;
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();

        for (int i = head[nownode]; i; i = edge[i].nex)
        {
            int nextnode = edge[i].to;
            if (vis[nextnode])
            {
                continue;
            }
            lfa[nextnode][0] = nownode;
            for (int i = 1; i <= 20; i++)
            {
                lfa[nextnode][i] = lfa[lfa[nextnode][i - 1]][i - 1];
            }
            q.push(nextnode);
            vis[nextnode] = 1;
            deep[nextnode] = deep[nownode] + 1;
        }
    }
}

int lca(int x, int y)
{
    if (deep[x] < deep[y])
    {
        swap(x, y);
    }

    while (deep[x] > deep[y])
    {
        for (int i = 20; i >= 0; i--)
        {
            int fax = lfa[x][i];
            if (deep[fax] >= deep[y])
            {
                x = fax;
            }
        }
    }

    if (x == y)
    {
        return y;
    }
    else
    {
        for (int i = 20; i >= 0; i--)
        {
            int fax = lfa[x][i];
            int fay = lfa[y][i];
            if (fax != fay)
            {
                x = fax;
                y = fay;
            }
        }
        return lfa[x][0];
    }
}
int checkin(int x, int y)
{
    int xylca = lca(x, y);
    int lcafa = findfa(xylca);
    if (lcafa == x)
    {
        return 1;
    }
    else if (lcafa == y)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

vector<Edge> err;
void solve()
{
    cin >> n;
    fa = nodenum = head = vector<int>(n + 5);
    edge = vector<Edge>(n * 2 + 5);
    err = vector<Edge>(n + 5);

    lfa = vector<vector<signed>>(n + 5, vector<signed>(24));
    tot = 1;

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        nodenum[i] = 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> err[i].from >> err[i].to;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }

    initlca();
    // cout << "!" << endl;

    int ans = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int x = err[i].from, y = err[i].to;
        int fax = findfa(x), fay = findfa(y);

        int checkout = checkin(fax, fay);
        if (checkout == 0)
        {
            ans = 0;
            break;
        }
        else if (checkout == 2)
        {
            int tmpnode = fax;
            for (int i = 20; i >= 0; i--)
            {
                int fatmp = lfa[tmpnode][i];
                if (findfa(fatmp) == fax)
                {
                    tmpnode = fatmp;
                }
            }
            if (findfa(lfa[tmpnode][0]) == fay)
            {
                ans *= inv(nodenum[fax] * nodenum[fay] % MOD);
                ans %= MOD;
            }
            else
            {
                ans = 0;
                break;
            }
        }
        else
        {
            int tmpnode = fay;
            for (int i = 20; i >= 0; i--)
            {
                int fatmp = lfa[tmpnode][i];
                if (findfa(fatmp) == fay)
                {
                    tmpnode = fatmp;
                }
            }
            if (findfa(lfa[tmpnode][0]) == fax)
            {
                ans *= inv(nodenum[fax] * nodenum[fay] % MOD);
                ans %= MOD;
            }
            else
            {
                ans = 0;
                break;
            }
        }

        nodenum[fa[y]] += nodenum[fa[x]];
        nodenum[fa[y]] %= MOD;
        connect(x, y);
    }
    cout << ans << endl;
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
