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
const int INF = 1e18 + 7;
const int MOD = 1e17 + 7;

vector<int> arr;

struct Segtree
{
    int L, R;
    int maxn;
    int f[4][4];
};
vector<Segtree> stree;

void build(int tot, int L, int R)
{

    stree[tot].L = L, stree[tot].R = R;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            stree[tot].f[i][j] = -INF;
        }
    }
    if (L == R)
    {

        stree[tot].f[0][0] = 0;
        stree[tot].f[1][1] = arr[L];

        return;
    }

    int mid = (L + R) / 2;
    build(tot * 2, L, mid);
    build(tot * 2 + 1, mid + 1, R);

    int rsonlen = (stree[tot * 2 + 1].R - stree[tot * 2 + 1].L + 1);
    int lsonlen = (stree[tot * 2].R - stree[tot * 2].L + 1);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if (lsonlen == i && rsonlen == j)
            {
                if (i + j <= 3)
                {
                    stree[tot].f[i + j][i + j] = max(stree[tot].f[i + j][i + j], stree[tot * 2].f[i][i] + stree[tot * 2 + 1].f[j][j]);
                }
            }
            else if (lsonlen == i)
            {
                for (int rinl = 0; rinl < 4; rinl++)
                {
                    if (i + rinl <= 3)
                    {
                        stree[tot].f[i + rinl][j] = max(stree[tot].f[i + rinl][j], stree[tot * 2].f[i][i] + stree[tot * 2 + 1].f[rinl][j]);
                    }
                }
            }
            else if(rsonlen==j)
            {
                for (int linr = 0; linr < 4; linr++)
                {
                    if (i + rinl <= 3)
                    {
                        stree[tot].f[i + rinl][j] = max(stree[tot].f[i + rinl][j], stree[tot * 2].f[i][i] + stree[tot * 2 + 1].f[rinl][j]);
                    }
                }
            }

            for (int ineri = 0; ineri < 4; ineri++)
            {
                for (int inerj = 0; inerj < 4; inerj++)
                {
                    stree[tot].f[i][j] = max(stree[tot].f[i][j], )
                }
            }
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {

        cin >> arr[i];
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
