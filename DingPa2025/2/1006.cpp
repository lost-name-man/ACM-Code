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
int lowbit(int x)
{
    int ret=x&(-x);
    return ret;
}

int n;

vector<int>tree;

void adds(int x, int val)
{
    for(int i=x; i<=n; i+=lowbit(i))
    {
        tree[i]+=val;
    }
}

int querys(int l, int r)
{
    int ret=0;
    for(int i=r; i; i-=lowbit(i))
    {
        ret+=tree[i];
    }
    for(int i=l-1; i; i-=lowbit(i))
    {
        ret-=tree[i];
    }

    return ret;

}



void solve()
{
    cin>>n;
    tree=vector<int>(n+5, 0);
    vector<int>arr(n+5, 0);
    vector<int>brr(n+5, 0);
    vector<int>arr_index(n+5, 0);
    vector<int>baned(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr_index[arr[i]]=i;
        adds(i, 1);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>brr[i];
    }
    

    vector<int>totans(n+5, 0);

    for(int i=1; i<=n; i++)
    {
        int ans=0;
        ans+=i-1;
        int bwin=brr[i];
        int binaindex=arr_index[bwin];
        ans+=querys(1, binaindex-1);

        totans[bwin]=ans;

        baned[bwin]=1;
        adds(binaindex, -1);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<totans[i]<<" ";
    }
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