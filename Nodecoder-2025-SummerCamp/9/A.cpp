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
const int INF = 1e17 + 7;
const int MOD = 1e17 + 7;

struct Node
{
    int fa;
    int l, r;
    int lh, rh;
    int size;
};

vector<Node> node;

int del_deep(int nownode)
{

    if (node[nownode].l == 0 && node[nownode].r == 0)
    {
        node[nownode].lh = 0;
        node[nownode].rh = 0;
        node[nownode].size = 1;
        return 1;
    }

    int maxn = 0;

    if (node[nownode].l)
    {

        int tmp = del_deep(node[nownode].l);
        node[nownode].lh = tmp;
        maxn = max(maxn, tmp);
    }

    if (node[nownode].r)
    {
        int tmp = del_deep(node[nownode].r);
        node[nownode].rh = tmp;
        maxn = max(maxn, tmp);
    }

    node[nownode].size = node[node[nownode].l].size + node[node[nownode].r].size + 1;

    return maxn + 1;
}

vector<vector<int>> f;
vector<int> Gcup(29, 0);
int dfs(int nownode)
{

    if (nownode == 0)
    {

        return 114;
    }

    int lnode = node[nownode].l;
    int rnode = node[nownode].r;
    dfs(lnode);
    dfs(rnode);

    for (int i = 0; i <= 26; i++)
    {
        if (i - 1 < 0)
        {
            f[nownode][i] = node[nownode].size;
        }
        else if (i - 2 < 0)
        {
            f[nownode][i] = f[lnode][i - 1] + f[rnode][i - 1];
        }
        else
        {
            f[nownode][i] = min({f[lnode][i - 1] + f[rnode][i - 1], f[lnode][i - 2] + f[rnode][i - 1], f[lnode][i - 1] + f[rnode][i - 2]});
        }
    }


    return 514;
}

void solve()
{
    int n;
    cin >> n;

    node = vector<Node>(n + 5);

    f = vector<vector<int>>(n + 5, vector<int>(29, INF));

    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].l >> node[i].r;
        node[node[i].l].fa = i;
        node[node[i].r].fa = i;
    }

    del_deep(1);

    dfs(1);

    int ans=INF;
    for(int i=0; i<=26; i++)
    {
        ans=min(ans, f[1][i]);
    }

    cout<<ans<<endl;

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    Gcup[0] = 0;
    Gcup[1] = 1;
    Gcup[2] = 2;
    for (int i = 3; i <= 26; i++)
    {
        Gcup[i] = Gcup[i - 1] + Gcup[i - 2] + 1;
    }
    for (int i = 0; i <= 26; i++)
    {
        f[0][i] = Gcup[i];
    }

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
