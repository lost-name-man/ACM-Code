#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
#include <cmath>

using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e17 + 7;
const int MOD = 1e17 + 7;

struct Node
{
    int id;
    int x;
    int y;
    int v;

    bool operator<(const Node other) const
    {
        return this->y < other.y;
    }
};

vector<Node> node;

// segtree-------------------------------------------------------------

void makelzy(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int tot, int le, int ri);
struct SegNode
{
    int L;
    int R;
    int val;
    int lzy;
};
vector<SegNode> segtree;
vector<int> arrline;
int segtot;
void makelzy(int tot, int x)
{
    int len = segtree[tot].R - segtree[tot].L + 1;
    segtree[tot].lzy += x;
    segtree[tot].val += x;
    segtree[tot].lzy %= MOD;
    segtree[tot].val %= MOD;
}

void downlzy(int tot)
{
    int m = (segtree[tot].L + segtree[tot].R) / 2;
    makelzy(tot * 2, segtree[tot].lzy);
    makelzy(tot * 2 + 1, segtree[tot].lzy);
    segtree[tot].lzy = 0;
}

int query(int tot, int le, int ri)
{
    int LL = segtree[tot].L, RR = segtree[tot].R;
    if (le <= LL && ri >= RR)
    {
        return segtree[tot].val;
    }
    else if (!(le > RR || ri < LL))
    {
        int m = (RR + LL) / 2;
        downlzy(tot);
        int tmp;

        tmp = max(query(tot * 2, le, ri), query(tot * 2 + 1, le, ri));
        tmp %= MOD;
        return tmp;
    }
    else
        return -INF;
}
void update(int tot, int le, int ri, int x)
{
    int LL = segtree[tot].L, RR = segtree[tot].R;
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
        segtree[tot].val = max(segtree[tot * 2].val, segtree[tot * 2 + 1].val);
        segtree[tot].val %= MOD;
        return;
    }
}
void build(int tot, int LL, int RR)
{
    segtree[tot].L = LL;
    segtree[tot].R = RR;
    segtree[tot].lzy = 0;

    if (LL == RR)
    {
        segtree[tot].val = 0;
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    segtree[tot].val = max(segtree[tot * 2].val, segtree[tot * 2 + 1].val);
    segtree[tot].val %= MOD;
}

void INITSegTree(int arrsize)
{

    // return;
    segtree = vector<SegNode>(4 * arrsize + 10);
    segtot = 1;

    build(segtot, 1, arrsize);
}
// segtree----------------------------------------------------------------------

void solve()
{
    int n, k;
    cin >> n >> k;
    node = vector<Node>();

    int upx = -INF, downx = INF;

    for (int i = 1; i <= n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        upx = max(upx, x);
        downx = min(downx, x);
        node.push_back({i, x, y, v});
    }
    // cout<<"!"<<upx<<endl;

    sort(node.begin(), node.end());

    vector<pair<int, int>> w_h;
    {
        int kdivw = 0;
        for (int w = 1; w*w <= k; w++)
        {

            w_h.push_back({w, k / w});
            w_h.push_back({k/w, w});
            
        }
    }

    int ans = 0;

    for (int i = 0; i < w_h.size(); i++)
    {

        int w = w_h[i].first, h = w_h[i].second;
        // cout << "!turn: " << w << " " << h << " ---------------------------" << endl;

        INITSegTree(upx);

        int rnodeid = 0;
        for (int lnodeid = 0; lnodeid < node.size();)
        {

            // deal
            while ((node[rnodeid].y - node[lnodeid].y + 1) <= w && rnodeid < node.size())
            {
                update(1, node[rnodeid].x, min(node[rnodeid].x + (h - 1), upx), node[rnodeid].v);
                rnodeid++;
            }


            // cout<<"@"<<lnodeid<<" "<<rnodeid<<endl;

            // cul
            int nowmaxn = query(1, 1, upx);
            ans = max(ans, nowmaxn);

            // done
            update(1, node[lnodeid].x, min(node[lnodeid].x + (h - 1), upx), -node[lnodeid].v);
            lnodeid++;
            
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;


    // INITSegTree(5);
    // update(1, 1, 2, 3);
    // update(1, 2, 3, 2);
    // cout<<query(1,1, 5)<<endl;
    // for(int i=1; i<=5; i++)
    // {
    //     cout<<query(1, i, i)<<endl;
    // }

    
    // return 0;




    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
