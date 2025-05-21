
#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

const int N = 200000;
const int M = N * 2;
using namespace std;

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
} tree[800005];
int arrline[200005];
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
        tree[tot].val = arrline[LL];
        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    tree[tot].val = max(tree[tot * 2].val, tree[tot * 2 + 1].val);
}
int n;
struct Rect
{
    int id;
    int x1;
    int y1;
    int x2;
    int y2;

    const bool operator<(const Rect & others ) const
    {
        return this->y1 < others.y1;
    }
};
vector<Rect> rect;
void solve()
{
    cin>>n;
    build(1,0,N);
    rect=vector<Rect>(n+5);
    for(int i=1;i<=n;i++)
    {
        cin>>rect[i].x1;
        cin>>rect[i].y1;
        cin>>rect[i].x2;
        cin>>rect[i].y2;
    }
    sort(rect.begin()+1,rect.begin()+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        Rect nowrect=rect[i];
        int nowmax=query(1,nowrect.x1,nowrect.x2);
        int nexmax=nowrect.y2-nowrect.y1+nowmax;
        ans+=(nowrect.y1-nowmax)*(nowrect.x2-nowrect.x1)*(nowrect.y2-nowrect.y1);
        upsame(1,nowrect.x1,nowrect.x2,nexmax);
    }
    cout<<ans<<endl;
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
