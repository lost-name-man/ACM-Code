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
const int INF = 1e16 + 7;
const int MOD = 998244353;

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n+5, 0);
    vector<int>brr(n+5, 0);
    vector<int>val_id(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>brr[i];
        val_id[brr[i]]=i;
    }

    
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        ans++;
        int j=val_id[arr[i]];
        while(arr[i+1]==brr[j+1] && (i+1)<=n && (j+1)<=n)
        {
            i++;
            j++;
        }

        // cout<<i<<endl;

    }


    cout<<ans<<endl;


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
