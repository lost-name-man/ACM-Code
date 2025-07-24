#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;
int MOD;

int n, m, r;

struct Edge
{
    int id;
    int w;
    int from;
    int to;
    int next;
};
vector<Edge> edge;
vector<int> head;
int ctot;
void addedge(int x, int y, int w)
{
    ctot++;
    edge[ctot].from = x;
    edge[ctot].to = y;
    edge[ctot].w = w;
    edge[ctot].next = head[x];
    head[x] = ctot;
}

vector<int> dfn_val;

// segtree-------------------------------------------------------------
void makelzy(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int le, int ri, int tot);
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

int query(int le, int ri, int tot = 1)
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

        tmp = query(ri, le, tot * 2) + query(ri, le, tot * 2 + 1);
        tmp%=MOD;
        return tmp;
    }
    else
        return 0;
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
        segtree[tot].val = segtree[tot * 2].val + segtree[tot * 2 + 1].val;
        segtree[tot].val%=MOD;
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
        segtree[tot].val = arrline[LL];
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    segtree[tot].val = segtree[tot * 2].val + segtree[tot * 2 + 1].val;
    segtree[tot].val%=MOD;
}

void INITSegTree(int arrsize)
{
    arrline = vector<int>(arrsize + 10, 0);
    for (int i = 1; i <= arrsize; i++)
    {
        arrline[i] = dfn_val[i]%MOD;
    }
    segtree = vector<SegNode>(4 * arrsize + 10);
    segtot = 1;
    build(segtot, 1, arrsize);
}
// segtree----------------------------------------------------------------------

int hctot;
struct Node
{
    int dfn;
    int val;
    int deep;
    int fa;
    int sonsize;
    int weightyson;
    int top;
};

vector<Node> node;

inline void dfs1(int nownode, int fa, int deep)
{
    node[nownode].deep = deep;
    node[nownode].fa = fa;
    node[nownode].sonsize = 1;
    int maxwson = -1;
    for (int i = head[nownode]; i; i = edge[i].next)
    {
        int nextnode = edge[i].to;
        if (nextnode == fa)
        {
            continue;
        }
        dfs1(nextnode, nownode, deep + 1);
        node[nownode].sonsize += node[nextnode].sonsize;
        if (node[nextnode].sonsize > maxwson)
        {
            node[nownode].weightyson = nextnode;
            maxwson = node[nextnode].sonsize;
        }
    }
}

inline void dfs2(int nownode, int topf)
{
    hctot++;
    node[nownode].dfn = hctot;
    dfn_val[node[nownode].dfn] = node[nownode].val;
    
    node[nownode].top = topf;
    if (node[nownode].sonsize <= 1)
    {
        return;
    }

    dfs2(node[nownode].weightyson, topf);
    for (int i = head[nownode]; i; i = edge[i].next)
    {
        int nextnode = edge[i].to;
        if (nextnode == node[nownode].fa || nextnode == node[nownode].weightyson)
        {
            continue;
        }
        dfs2(nextnode, nextnode);
    }
}

int res;

inline int HcQuerySum(int x, int y)
{
    int ans = 0;
    while (node[x].top != node[y].top)
    {
        if (node[x].deep < node[y].deep)
        {
            swap(x, y);
        }

        res = query(node[node[x].top].dfn, node[x].dfn);
        ans += res;
        ans %= MOD;
        x = node[node[x].top].fa;
    }
    if (node[x].deep < node[y].deep)
    {
        swap(x, y);
    }
    res = query(node[y].dfn, node[x].dfn);
    ans += res;

    ans %= MOD;
    return ans;
}

inline int HcQuerySon(int x)
{
    int ans = 0;
    res = query(node[x].dfn, node[x].dfn + node[x].sonsize - 1);
    ans += res;

    ans %= MOD;
    return ans;
}

inline void HcWriteItv(int x, int y, int k)
{
    k %= MOD;
    while (node[x].top != node[y].top)
    {
        if (node[x].deep < node[y].deep)
        {
            swap(x, y);
        }
        update(1, node[node[x].top].dfn, node[x].dfn, k);

        x = node[node[x].top].fa;
    }
    if (node[x].deep < node[y].deep)
    {
        swap(x, y);
    }
    update(1, node[y].dfn, node[x].dfn, k);
}

inline void HcWriteSon(int x, int k)
{
    update(1, node[x].dfn, node[x].dfn + node[x].sonsize - 1, k);
}

void solve()
{
    cin >> n >> m >> r >> MOD;
    // init
    edge = vector<Edge>(n*2 + 5);
    ctot = 0;
    hctot = 0;

    head = vector<int>(n + 5, 0);
    node = vector<Node>(n + 5);
    dfn_val = vector<int>(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> node[i].val;
        node[i].val%=MOD;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        addedge(x, y, 1);
        addedge(y, x, 1);
    }

    dfs1(r, 0, 1);
    dfs2(r, r);

    INITSegTree(n);

    for (int q = 1; q <= m; q++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            HcWriteItv(x, y, z);
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            int ots = HcQuerySum(x, y);
            cout << ots << endl;
        }
        else if (op == 3)
        {
            int x, y;
            cin >> x >> y;
            HcWriteSon(x, y);
        }
        else
        {
            int x;
            cin >> x;
            int ots = HcQuerySon(x);
            cout << ots << endl;
        }

        // cout << "----------------------" << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << "!" << query(i, i) << endl;
        // }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
