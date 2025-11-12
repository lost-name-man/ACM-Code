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

using namespace std;
#define int long long
// #define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 998244353;
void solve()
{
    int n, k;
    cin>>n>>k;


    priority_queue<int>pq;

    int last=0;
    for(int i=1; i<=n; i++)
    {

        int x;
        cin>>x;
        pq.push(x);
        last=max(last, x);
    }

    last%=MOD;
    
    pq.pop();
    

    while(pq.size()>=(k-1))
    {
        int nowval=last;
        int nullnum=0;
        for(int i=2; i<=k; i++)
        {

            if(pq.top()==0)
            {
                nullnum++;
                break;
            }

            nowval*=(pq.top())%MOD;
            nowval%=MOD;
            pq.pop();
            
        }

        if(nullnum)
        {
            break;
        }
        else
        {
            last=nowval;
            last%=MOD;
        }
    }


    cout<<last%MOD<<endl;

}

signed main()
{

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
