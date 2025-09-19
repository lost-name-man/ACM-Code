#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;




void solve()
{
    int a, b;
    cin>>a>>b;

    if(a==1)
    {
        cout<<1<<" "<<1<<endl;
        return;
    }
    else if(b==1)
    {
        cout<<1<<" "<<0<<endl;
        return;
    }

    if(a%2==1)
    {
        cout<<1<<" "<<1<<endl;
        return;
    }
    else if(b%2==1)
    {
        cout<<1<<" "<<0<<endl;
        return;
    }

    if(a>b)
    {   
        int zweipow=0;
        {
            int tmpb=b;
            while(tmpb%2==0)
            {
                zweipow++;
                tmpb/=2;
            }
        }

        cout<<zweipow+1<<" "<<1<<endl;

    }
    else
    {
        int zweipow=0;
        {
            int tmpb=a;
            while(tmpb%2==0)
            {
                zweipow++;
                tmpb/=2;
            }
        }

        cout<<zweipow<<" "<<1<<endl;
    }
    
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
