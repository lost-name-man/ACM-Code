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
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    vector<int>arr(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    vector<int>copy_arr;
    copy_arr=arr;
    sort(arr.begin()+1, arr.begin()+1+n);


    int ans=0;

    map<int, int>ping_num;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]>arr[i-1])
        {
            ans+=x;
        }
        else if(arr[i]==arr[i-1])
        {
            ans+=y;
            ping_num[arr[i]]++;
        }
        else
        {
            ans+=z;
        }
    }

    int neuans=0;
    int sum=0;
    int maxn=0;
    for(auto iter=ping_num.begin(); iter!=ping_num.end(); iter++)
    {
        sum+=iter->second;
        maxn=max(maxn, iter->second);


        cout<<"#"<<iter->second<<endl;
    }

    if(maxn>=(sum-maxn))
    {
        int ups=(sum-maxn);
        neuans=ans-(ups*(y+z))+ups*(x+x);


        cout<<"!"<<ups<<endl;
    }
    else
    {
        int leav=sum%2;
        int ups=(sum-leav)/2;
        neuans=ans-(ups*(y+z))+ups*(x+x);

        cout<<"@"<<ups<<endl;
    }

    ans=max(ans, neuans);


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
