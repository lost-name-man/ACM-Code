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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;

int n, m;

vector<int> dp;
void makelzy(int tot, int x);
void makesame(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int tot, int le, int ri);
void upsame(int tot, int le, int ri, int x);
struct node
{
    int L;
    int R;
    int val;
    int lzy;
    int same = INF;
} tree[400005];
void makelzy(int tot, int x)
{
    int len = tree[tot].R - tree[tot].L + 1;
    tree[tot].lzy += x;
    tree[tot].val += x;
}
void makesame(int tot, int x)
{
    tree[tot].val = x;
    tree[tot].same = x;
    tree[tot].lzy = 0;
}

void downlzy(int tot)
{
    if (tree[tot].same != INF)
    {
        makesame(tot * 2, tree[tot].same);
        makesame(tot * 2 + 1, tree[tot].same);
        tree[tot].same = INF;
    }
    int m = (tree[tot].L + tree[tot].R) / 2;
    makelzy(tot * 2, tree[tot].lzy);
    makelzy(tot * 2 + 1, tree[tot].lzy);
    tree[tot].lzy = 0;
}

int query(int tot, int le, int ri)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        return tree[tot].val;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        downlzy(tot);
        int tmp;

        tmp = max(query(tot * 2, le, ri), query(tot * 2 + 1, le, ri));
        return tmp;
    }
    else
        return -INF;
}
void update(int tot, int le, int ri, int x)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        makelzy(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        downlzy(tot);
        update(tot * 2, le, ri, x);
        update(tot * 2 + 1, le, ri, x);
        tree[tot].val = max(tree[tot * 2].val, tree[tot * 2 + 1].val);
        return;
    }
}
void upsame(int tot, int le, int ri, int x)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        makesame(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        downlzy(tot);
        upsame(tot * 2, le, ri, x);
        upsame(tot * 2 + 1, le, ri, x);
        tree[tot].val = max(tree[tot * 2].val, tree[tot * 2 + 1].val);
        return;
    }
}

void build(int tot, int LL, int RR)
{
    tree[tot].L = LL;
    tree[tot].R = RR;
    tree[tot].lzy = 0;
    tree[tot].same = INF;
    if (LL == RR)
    {
        tree[tot].val = dp[LL];
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    tree[tot].val = max(tree[tot * 2].val, tree[tot * 2 + 1].val);
}
void solve()
{

    cin >> n >> m;
    int M = pow(2, m);
    vector<int> arr(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> grr(M + 5);
    for (int i = 1; i <= M; i++)
    {
        cin >> grr[i - 1];
    }
    dp = vector<int>(n + 5, -INF);
    dp[0] = 0;
    dp[1] = grr[0];
    vector<vector<int>> index_of_j(22, vector<int>(2, 0));
    for (int j = 1; j <= m; j++)
    {
        int nowzwei = (arr[1] >> (j - 1)) & 1;
        index_of_j[j][nowzwei] = 1;
    }
    build(1, 0, n);

    int prex = 0, prey = 0x7f7f7f7f7f7f7f7f, pre;
    for (int i = 2; i <= n; i++)
    {
        prex |= arr[i];
        prey &= arr[i];
        pre = prex - prey;
        int maxn = -INF;
        int nownum = arr[i];

        map<int, int> mp;
        mp[i] = 0;
        for (int j = 1; j <= m; j++)
        {
            int nowzwei = (nownum >> (j - 1)) & 1;
            int nowindex = index_of_j[j][nowzwei ^ 1];
            index_of_j[j][nowzwei] = i;
            if (nowindex == 0)
            {
                continue;
            }
            else
            {
                mp[nowindex] |= (1 << (j - 1));
            }
        }
        int nowf = 0;
        vector<pair<int, int>> jinv;

        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            jinv.push_back(*it);
        }
        for (int j = 0; j < jinv.size() - 1; j++)
        {
            int r = jinv[j].first;
            int l = jinv[j + 1].first + 1;
            int invmax = query(1, l - 1, r - 1);
            nowf |= jinv[j].second;
            maxn = max(maxn, grr[nowf] + invmax);
        }
        {
            int index = jinv.size() - 1;
            int r = jinv[index].first;
            int l = 1;
            int invmax = query(1, l - 1, r - 1);

            nowf |= jinv[index].second;
            maxn = max(maxn, grr[nowf] + invmax);
        }

        dp[i] = maxn;
        upsame(1, i, i, dp[i]);
    }

    cout << dp[n] << endl;
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