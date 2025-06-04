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

int lcm(int a, int b)
{
    return a*b/__gcd(a, b);
}

void solve()
{
    int a, b;
    cin>>a>>b;

    if(a==b)
    {
        cout<<0<<endl;
        return;
    }

    vector<int>factor;
    int minx=b;
    for(int i=2; i<=sqrt(b); i++)
    {
        if(b%i==0)
        {
            factor.push_back(i);
            minx=min(minx, i);
            if((b/i)!=i)
            {
                factor.push_back(b/i);
                minx=min(minx, b/i);
            }
        }
    }

    int miny=a;
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i==0)
        {
            factor.push_back(i);
            miny=min(miny, i);
            if((a/i)!=i)
            {
                factor.push_back(a/i);
                miny=min(miny, b/i);
            }
        }
    }

    factor.push_back(2);

    int ans=lcm(a, b);


    for(int i=0; i<factor.size(); i++)
    {
        int nowfactor=factor[i];
        // cout<<"@"<<nowfactor<<endl;
        ans=min(ans, lcm(a, nowfactor)+lcm(nowfactor, b));
    }


    ans=min(ans, lcm(a, miny)+lcm(miny, minx)+lcm(minx, b));

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