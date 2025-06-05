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



void solve()
{
    
    string str;
    cin>>str;
    int ans=0;
    int ok=0;
    int add=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='1' && ok==0)
        {
            ok=1;
        }
        else if(ok==1 && str[i]=='0')
        {
            ok=0;
            ans++;
        }


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