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
#define INF 1e9
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;



void solve()
{
    
    int k, a, b, c;
    cin>>k>>a>>b>>c;
    int ans=0;
    vector<int>arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    for(int i=0; i<=pow(2, 3)-1; i++)
    {
        int nowzwei=i;
        int index=0;
        int tmpans=0;
        while(nowzwei)
        {
            int now=nowzwei&1;
            if(now)
            {
                tmpans+=arr[index];
            }
            index++;
            nowzwei=nowzwei>>1;
        }
        if(tmpans>k)
        {

        }
        else
        {
            ans=max(ans, tmpans);
        }
    }

    cout<<k-ans<<endl;
    
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