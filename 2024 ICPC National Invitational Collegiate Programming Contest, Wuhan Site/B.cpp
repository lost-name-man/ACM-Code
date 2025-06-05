#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
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
#include <iomanip>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;


vector<int>val(1000006, 0);

void solve()
{
    int n;
    cin>>n;
    int sum=0;
    vector<int>arr(n+5, 0);
    for(int i=1;i <=n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }

    int cnt=0;
    int ans=0;
    while(sum>0)
    {
        ans|=(1<<cnt);
        sum-=(1<<cnt)*n;
        cout<<"@"<<(1<<cnt)<<endl;
        cnt++;
        
    }
    cout<<ans<<endl;


}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);



    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}