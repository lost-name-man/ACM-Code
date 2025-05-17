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




void solve()
{
    int n, m;
    cin>>n>>m;

    vector<map<int, int>>sub_fk(n+5);
    int max_gain=0;
    for(int i=1; i<=n; i++)
    {
        int maxn=0;
        for(int j=1; j<=m; j++)
        {
            cin>>sub_fk[i][j];
            maxn=max(maxn, sub_fk[i][j]);
        }
        sub_fk[i][0]=maxn;
        max_gain+=maxn;
    }


    int ans=0;

    for(int halfood=1; halfood<=m; halfood++)
    {
        vector<int>loss(n+5, 0);
        
        for(int i=1; i<=n; i++)
        {
            loss[i]=sub_fk[i][0]-sub_fk[i][halfood];
        }
        sort(loss.begin()+1, loss.begin()+1+n);
        int cost_loss=0;
        for(int i=1; i<=n/2+1; i++)
        {
            cost_loss+=loss[i];
        }
        ans=max(ans, max_gain-cost_loss);

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