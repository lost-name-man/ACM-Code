#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

const int N = 1000000;
struct Node
{
    int l;
    int r;
    int minn;
};
struct Cow
{
    int l;
    int r;
    int w;
};

Node linetree[N * 4 + 10];
void update(int tot, int index, int x)
{
    if (linetree[tot].l == linetree[tot].r)
    {
        linetree[tot].minn = min(linetree[tot].minn, x);
        return;
    }

    int mid = (linetree[tot].l + linetree[tot].r) / 2;
    if (index <= mid)
    {
        update(tot * 2, index, x);
    }
    else
    {
        update(tot * 2 + 1, index, x);
    }
    linetree[tot].minn = min(linetree[tot * 2].minn, linetree[tot * 2 + 1].minn);
}

int query(int tot, int L, int R)
{
    int nowl = linetree[tot].l, nowr = linetree[tot].r;
    int mid = (nowl + nowr) / 2;
    if (nowl >= L && nowr <= R)
    {
        return linetree[tot].minn;
    }
    else if (!(nowl > R || nowr < L))
    {
        return min(query(tot * 2, L, R), query(tot * 2 + 1, L, R));
    }
    else
    {
        return INF;
    }
}

void build(int tot, int L, int R)
{
    linetree[tot].l = L;
    linetree[tot].r = R;
    linetree[tot].minn = INF;
    if (L == R)
    {
        return;
    }
    int mid = (L + R) / 2;
    build(tot * 2, L, mid);
    build(tot * 2 + 1, mid + 1, R);
}

bool cmp(Cow &a, Cow &b)
{
    return a.r < b.r;
}
int n, t, M, E;
vector<Cow> cows;
void solve()
{
    cin >> n >> M >> E;
    t = E - M + 1;
    build(1, 0, t);
    update(1, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        l = l - M + 1;
        r = r - M + 1;
        cows.push_back({
            l,
            r,
            w,
        });
    }
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < cows.size(); i++)
    {
        int nowl = cows[i].l, nowr = cows[i].r;
        int nowminn = query(1, nowl - 1, nowr - 1);
        update(1, nowr, nowminn + cows[i].w);
    }
    int ans = query(1, t, t);
    if (ans >= INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}