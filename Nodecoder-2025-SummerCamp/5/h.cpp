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
// #define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;

struct Node
{
    int index;
    int l;
    int r;
};

int n, k;
vector<int> tree[1000006];
vector<Node> pur;

int fa[1000006][21];
int times[1000006];
void initst(int nownode)
{
    for (int i = 1; i <= 20; i++)
    {
        fa[nownode][i] = fa[fa[nownode][i - 1]][i - 1];
    }
    for (int i = 0; i < tree[nownode].size(); i++)
    {
        int nextnode = tree[nownode][i];
        fa[nextnode][0] = nownode;
        initst(nextnode);
    }
}
int findnode(int nownode)
{
    if (times[nownode] != 0)
    {
        return nownode;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (times[fa[nownode][i]] == 0)
        {
            nownode = fa[nownode][i];
        }
    }
    return nownode;
}
void solve()
{

    cin >> n >> k;
    pur = vector<Node>(k + 5);
    for (int i = 2; i <= n; i++)
    {
        int fa;
        cin >> fa;
        tree[fa].push_back(i);
    }
    initst(1);
    for (int i = 1; i <= k; i++)
    {
        cin >> pur[i].index >> pur[i].l >> pur[i].r;
    }
    times[1] = 1;
    times[0] = INF;
    int ans = -1;
    for (int i = 1; i <= k; i++)
    {
        int l = pur[i].l, r = pur[i].r;
        int purnode = pur[i].index;

        for (int j = l; j <= r; j++)
        {
            int nownode = findnode(purnode);
            if (nownode == purnode)
            {
                ans = j;
                break;
            }
            times[nownode] = j;
        }
        if (ans != -1)
        {
            break;
        }
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
