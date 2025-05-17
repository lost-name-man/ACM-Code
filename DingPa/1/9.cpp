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

struct LTREE
{
    int l, r;
    int sum;
    int maxn;
    int lazytag;
};

vector<LTREE> LTree;
vector<int> dp;
inline void LTbuild(int i, int l, int r)
{
    LTree[i].l = l;
    LTree[i].r = r;
    if (l == r)
    {
        LTree[i].sum = dp[l];
        LTree[i].maxn = dp[l];
        return;
    }

    int mid = (l + r) / 2;
    LTbuild(i * 2, l, mid);
    LTbuild(i * 2 + 1, mid + 1, r);
    LTree[i].sum = LTree[i * 2].sum + LTree[i * 2 + 1].sum;
    LTree[i].maxn = max(LTree[i * 2].maxn, LTree[i * 2 + 1].maxn);
}

inline void LTpd(int i) {
    int t = LTree[i].lazytag;
    if (t != 0) {
        // 左子节点
        int ls = i << 1, rs = ls + 1;
        // 更新子节点的懒标记
        LTree[ls].lazytag += t;
        LTree[rs].lazytag += t;
        // 计算左右子区间长度
        int llen = LTree[ls].r - LTree[ls].l + 1;
        int rlen = LTree[rs].r - LTree[rs].l + 1;
        // 更新 sum 和 maxn
        LTree[ls].sum += t * llen;
        LTree[rs].sum += t * rlen;
        LTree[ls].maxn += t;
        LTree[rs].maxn += t;
        // 清除当前节点懒标记
        LTree[i].lazytag = 0;
    }
}


int LTsearch(int i, int l, int r)
{
    if (LTree[i].l >= l && LTree[i].r <= r)
    {
        return LTree[i].maxn;
    }
    if (LTree[i].l > r || LTree[i].r < l)
    {
        return -INF;
    }

    LTpd(i);
    int ret = -INF;
    if (LTree[i * 2].r >= l)
    {
        ret = max(ret, LTsearch(i * 2, l, r));
    }
    if (LTree[i * 2 + 1].l <= r)
    {
        ret = max(ret, LTsearch(i * 2 + 1, l, r));
    }

    if (l == 0)
    {
        ret = max(ret, dp[0]);
    }

    return ret;
}

inline void LTadd(int i, int l, int r, int val)
{
    if (LTree[i].r <= r && LTree[i].l >= l)
    {
        LTree[i].sum = val * (LTree[i].r - LTree[i].l + 1);
        LTree[i].maxn = LTree[i].sum;
        LTree[i].lazytag += val;
        return;
    }
    LTpd(i);
    if (LTree[i * 2].r >= l)
    {
        LTadd(i * 2, l, r, val);
    }
    if (LTree[i * 2 + 1].l <= r)
    {
        LTadd(i * 2 + 1, l, r, val);
    }

    LTree[i].sum = LTree[i * 2].sum + LTree[i * 2 + 1].sum;
    LTree[i].maxn = max(LTree[i * 2].maxn, LTree[i * 2].maxn);
}

void solve()
{

    cin >> n >> m;
    int M = pow(2, m);
    vector<int> arr(n + 5, 0);
    LTree = vector<LTREE>(4 * n);
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
    LTbuild(1, 1, n);
    

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
            int invmax = LTsearch(1, l-1, r-1);

            nowf |= jinv[j].second;
            maxn = max(maxn, grr[nowf] + invmax);
        }
        {
            int index = jinv.size() - 1;
            int r = jinv[index].first;
            int l = 1;
            int invmax = LTsearch(1, l-1, r-1);

            nowf |= jinv[index].second;
            maxn = max(maxn, grr[nowf] + invmax);
        }

        dp[i] = maxn;
        LTadd(1, i, i, dp[i]);

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