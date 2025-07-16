#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define int long long
#define INF ((long long)1e18)
#define endl '\n'
#define MOD 998244353

using namespace std;

const int N = 1000000;


void test()
{
    map<int, int>bridge;
    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=1000; j++)
        {
            bridge[abs(i*i-j*j)]=1;
        }
    }
    for(auto iter=bridge.begin(); iter!=bridge.end(); iter++)
    {
        // if(iter->first%2==0)
        cout<<iter->first<<" ";
    }
}

void solve()
{
    int a, b;
    cin>>a>>b;
    int delta=abs(a*a - b*b);

    int ans=0;
    ans=max((int)0, delta/4-1)+(delta+1)/2-1;
    cout<< ans<<endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}

/*

3 4
0 3
1 1
1 2
2 2


3 5
0 3
1 1
1 2
1 3
2 2

10 8
0 3
1 3
2 3
3 3
4 3
5 3
6 3
7 3

*/
