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
const int MOD = 998244353;


map<string, int>val_exist;

int do3(int a, int b, map<int, int>&arr)
{
    arr[a|b]=1;
    arr[a&b]=1;
    arr[a^b]=1;

    return 0;
}

string do33(int a, int b)
{

    string einzwei;

    string astr, bstr;


    while(a)
    {
        int i=a%2;
        astr+=(char)(i+'0');
        a/=2;
    }
    while(astr.size()<32)
    {
        astr+='0';
    }

    while(b)
    {
        int i=b%2;
        bstr+=(char)(i+'0');
        b/=2;
    }
    while(bstr.size()<32)
    {
        bstr+='0';
    }

    // cout<<astr<<endl;


    for(int i=0; i<32; i++)
    {
        if(astr[i]=='1' || bstr[i]=='1')
        {
            einzwei[i]='1';
        }
    }
    
    

    return einzwei;

}

void solve()
{
    int n;
    cin>>n;

    int ori=0;

    vector<int>arr(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];

        if(i>1)
        {
            val_exist[do33(arr[i-1], arr[i])]=1;
        }
        
    }

    int ans=0;

    int nullnum=0;
    for(auto iter=val_exist.begin(); iter!=val_exist.end(); iter++)
    {
        int einnum=0;
        for(int i=0; i<32; i++)
        {
            if(iter->first[i]=='1')
            {
                einnum++;
            }
        }
        if(einnum!=0)
        {
            ans+=pow(2, einnum);
        }
        else
        {
            nullnum=1;
        }
        
    }


    cout<<ans+nullnum<<endl;

}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    //  cin >> T;

    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
