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
#define endl '\n'
const int INF = 1e18 + 3;


int gcd(int a,int b)
{

    if(a<b)
    {
        swap(a, b);
    }

    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}
int n,q;
vector<int> arr;

void solve()
{

    cin>>n>>q;
    set<pair<int,int>> st;

    int lastindex=1;
    map<int,map<int,int>> divi;
    
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i-1]>arr[i])
        {
            st.insert({lastindex,i-1});
            lastindex=i;
        }
    }
    st.insert({lastindex,n});
    int nowgcd=st.begin()->second - st.begin()->first + 1;
    for(auto it = st.begin();it->second!=n;it++)
    {

        int len=it->second - it->first + 1;
        int nowgcd=gcd(nowgcd , it->second - it->first + 1);
        int tmp=len;
        for(int i=2;i*i<=tmp;i++)
        {
            int divinum=0;
            while(tmp%i==0)
            {
                divinum++;
                tmp/=i;
            }
            if(divinum)
            {
                divi[i][divinum]++;
            }

        } 
    }

    for(int i=1;i<=q;i++)
    {
        int p,v;
        cin>>p>>v;
        auto it = st.lower_bound({p,0});
        if(v > arr[p])
        {
            if(p!=n && arr[p]>arr[p+1])
            {
                if(p==it->first)
                {
                    if(v >= arr[p-1] && p!=1)
                    {
                        pair<int,int> tmpp=*it;
                        tmpp.first++;
                        it--;
                        
                    }
                }
            }
        }
    }



   

}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;

    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
