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
    int n;
    cin>>n;
    vector<int>val(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>val[i];
    }

    vector<int>arr;
    vector<int>abb;
    for(int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if(ch=='R')
        {
            arr.push_back(val[i]);
        }
        else
        {
            abb.push_back(val[i]);
        }
        
    }

    sort(arr.begin(), arr.end());
    sort(abb.begin(), abb.end());
    int rindex=arr.size()-1;
    int bindex=abb.size()-1;
    int nowcol=0;
    int ans=0;
    while(1)
    {
        nowcol=nowcol^1;
        if(nowcol==1)
        {
            //RED
            if(rindex>=0)
            {
                ans+=arr[rindex];
                rindex--;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(bindex>=0)
            {
                ans+=abb[bindex];
                bindex--;
            }
            else
            {
                break;
            }
        }
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