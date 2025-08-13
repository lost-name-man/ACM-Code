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



void upupdate(int tot)
{
    int rsonlen = (stree[tot * 2 + 1].R - stree[tot * 2 + 1].L + 1);
    int lsonlen = (stree[tot * 2].R - stree[tot * 2].L + 1);

    for (int li = 0; li < 4; li++)
    {
        for (int lj = 0; lj < 4; lj++)
        {
            for (int ri = 0; ri < 4; ri++)
            {
                for (int rj = 0; rj < 4; rj++)
                {
                    int nowl=li,nowr=rj;
                    if(lsonlen==li)
                    {
                        nowl=li+ri;
                    }
                    if(rsonlen==ri)
                    {
                        nowr=lj+ri;
                    }
                    if(nowl>3 || nowr>3)
                    {
                        continue;
                    }

                    stree[tot].f[nowl][nowr]=max(stree[tot].f[nowl][nowr], stree[tot*2].f[li][lj] + stree[tot*2+1].f[ri][rj]);
                    
                }
            }
            
        }
    }
}


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

    upupdate(tot);
}


void update(int tot, int x, int upval)
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            stree[tot].f[i][j] = -INF;
        }
    }
    if (stree[tot].L == stree[tot].R)
    {

        stree[tot].f[0][0] = 0;
        stree[tot].f[1][1] =upval;

        return;
    }

    int mid=(stree[tot].L+stree[tot].R)/2;

    if(x<=mid)
    {
        update(tot*2, x, upval);
    }
    else
    {
        update(tot*2+1, x, upval);
    }

    upupdate(tot);

}



int query()
{
    int ret=0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i+j>3)
            {
                continue;
            }
            ret=max(ret, stree[1].f[i][j]);
        }
    }

    return ret;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    arr=vector<int>(n+5, 0);
    stree=vector<Segtree>(4*n+5);
    for (int i = 1; i <= n; i++)
    {

        cin >> arr[i];
    }

    build(1, 1, n);
    int ans=query();
    cout<<ans<<endl;
    for(int qq=1; qq<=q; qq++)
    {
        int x,v;
        cin>>x>>v;

        update(1, x, v);
        ans=query();
        cout<<ans<<endl;

    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
