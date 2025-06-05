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
    int ans=val[n];
    if(ans==1)
    {
        cout<<"Fluttershy"<<endl;
    }
    else
    {
        cout<<"Pinkie Pie"<<endl;
    }

}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);


    val[1]=1;
    int nowval=1;
    for(int i=2; i<=1000000; i++)
    {
        if(i%2==0)
        {
            nowval=1-nowval;
            
        }
        val[i]=nowval;
    }




    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}