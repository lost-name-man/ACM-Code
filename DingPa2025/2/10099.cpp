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
#define MOD 1000000007

using namespace std;

struct Node
{
    int to;
    int nex;
};
struct Seg
{
    int L;
    int R;
    int max;
} tree[400005];

vector<Node> edge;
vector<int> head;
int tot = 1;

//
vector<int> val;
vector<int> idval;

vector<int> deep;
vector<int> fa;
vector<int> sizes;
vector<int> heavyson;
void dfs1(int nownode, int nowfa, int nowdeep)
{                            // x当前节点，f父亲，deep深度
    deep[nownode] = nowdeep; // 标记每个点的深度
    fa[nownode] = nowfa;     // 标记每个点的父亲
    sizes[nownode] = 1;      // 标记每个非叶子节点的子树大小
    int maxson = -1;         // 记录重儿子的儿子数
    for (int i = head[nownode]; i; i = edge[i].nex)
    {
        int nextnode = edge[i].to;
        if (nextnode == nowfa)
            continue;                         // 若为父亲则continue
        dfs1(nextnode, nownode, nowdeep + 1); // dfs其儿子
        sizes[nownode] += sizes[nextnode];    // 把它的儿子数加到它身上
        if (sizes[nextnode] > maxson)
            heavyson[nownode] = nextnode, maxson = sizes[nextnode]; // 标记每个非叶子节点的重儿子编号
    }
} // 变量解释见最下面

int cnt = 0;
vector<int> id;
vector<int> top;
void dfs2(int x, int topf)
{                        // x当前节点，topf当前链的最顶端的节点
    id[x] = ++cnt;       // 标记每个点的新编号
    idval[cnt] = val[x]; // 把每个点的初始值赋到新编号上来
    top[x] = topf;       // 这个点所在链的顶端
    if (heavyson[x] == 0)
        return;              // 如果没有儿子则返回
    dfs2(heavyson[x], topf); // 按先处理重儿子，再处理轻儿子的顺序递归处理
    for (int i = head[x]; i; i = edge[i].nex)
    {
        int y = edge[i].to;
        if (y == fa[x] || y == heavyson[x])
            continue;
        dfs2(y, y); // 对于每一个轻儿子都有一条从它自己开始的链
    }
} // 变量解释见最下面

void add(int x, int y)
{
    tot++;
    edge[tot].to = y;
    edge[tot].nex = head[x];
    head[x] = tot;
}

// segtree
void build(int tot, int LL, int RR)
{
    tree[tot].L = LL;
    tree[tot].R = RR;
    if (LL == RR)
    {
        tree[tot].max = idval[LL];
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    tree[tot].max = max(tree[tot * 2].max, tree[tot * 2 + 1].max);
}

void update(int tot, int index, int x)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    int mid = (LL + RR) / 2;
    if (LL == RR)
    {
        tree[tot].max += x;
        return;
    }
    if (index <= mid)
    {
        update(tot * 2, index, x);
    }
    else
    {
        update(tot * 2 + 1, index, x);
    }
    tree[tot].max = max(tree[tot * 2].max, tree[tot * 2 + 1].max);
}

int query(int tot, int le, int ri)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        return tree[tot].max;
    }
    else if (!(le > RR || ri < LL))
    {
        int tmp;
        tmp = max(query(tot * 2, le, ri), query(tot * 2 + 1, le, ri));
        return tmp;
    }
    else
        return -INF;
}

// heavy chain
vector<int> tag;
int max_x_y(int x, int y)
{
    int maxn = 0;

    while (top[x] != top[y])
    { // 当两个点不在同一条链上
        if (deep[top[x]] < deep[top[y]])
            swap(x, y); // 把x点改为所在链顶端的深度更深的那个点
        int tmpmax;
        tmpmax = query(1, id[top[x]], id[x]); // ans加上x点到x所在链顶端 这一段区间的点权和
        maxn = max(tmpmax, maxn);
        maxn = max(tag[fa[top[x]]] + val[top[x]], maxn);
        x = fa[top[x]]; // 把x跳到x所在链顶端的那个点的上面一个点 //
    }

    // 直到两个点处于一条链上
    if (deep[x] > deep[y])
        swap(x, y); // 把x点深度更深的那个点
    int tmpmax = 0;
    tmpmax = query(1, id[x], id[y]); // 这时再加上此时两个点的区间和即可
    maxn = max(maxn, tmpmax);
    if (top[y] == y && fa[y] != 0)
    {
        maxn = max(maxn, tag[fa[y]] + val[y]);
    }
    return maxn;
} // 变量解释见最下面

int change(int x, int z)
{
    if (fa[x] != 0)
    {
        update(1, id[fa[x]], z);
    }

    if (heavyson[x] != 0)
    {
        update(1, id[heavyson[x]], z);
    }

    tag[x] += z;
}
int n, m;
void init()
{
    deep = vector<int>(n + 5, 0);
    fa = vector<int>(n + 5, 0);
    sizes = vector<int>(n + 5, 0);
    heavyson = vector<int>(n + 5, 0);
    cnt = 0;

    tot = 1;
    head = vector<int>(n + 5, 0);
    edge = vector<Node>(n * 2 + 5);

    val = vector<int>(n + 5, 0);
    id = vector<int>(n + 5, 0);
    idval = vector<int>(n + 5, 0);
    top = vector<int>(n + 5, 0);

    tag = vector<int>(n + 5, 0);
}
void solve()
{

    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0, 1);
    dfs2(1, 1);

    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int type, x, y, z;
        cin >> type;
        if (type == 1)
        {
            cin >> x >> y;
            cout << max_x_y(x, y) << endl;
        }
        else
        {
            cin >> x >> z;
            change(x, z);
        }
    }
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