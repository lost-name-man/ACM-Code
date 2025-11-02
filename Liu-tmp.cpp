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


struct Nex
{
    int id;
    int nexL=-1;
    int nexR=-1;
    int nexLR=-1;
};

void solve()
{

    string s;
    cin>>s;

    s="@"+s + "@";


    vector<Nex>nex(s.size()+5);



    for(int i=s.size()-1; i>=0; i--)
    {
        if(i!=0)
        {
            nex[i-1].nexL=nex[i].nexL;
            nex[i-1].nexR=nex[i].nexR;
            nex[i-1].nexLR=nex[i].nexLR;
        }
        
        if(s[i]=='L')
        {
            nex[i-1].nexL=i;
            if(s[i+1]=='R')
            {
                nex[i-1].nexLR=i;
            }
        }
        else if(s[i]=='R')
        {
            nex[i-1].nexR=i;
        }
        
    }



    int q;
    cin>>q;
    for(int Q=1; Q<=q; Q++)
    {
        string t;
        cin>>t;

        t=t+"@";

        int si=0;
        for(int ti=0; ti<t.size()-1; ti++)
        {
            char tch=t[ti];

            if(tch=='L')
            {
                if(t[ti+1]=='R')
                {
                    int nexsi=nex[si].nexLR;
                    if(nexsi==-1)
                    {
                        goto WAAA;
                    }
                    else
                    {
                        si=nexsi+1;
                    }
                }
                else
                {
                    int nexsi=nex[si].nexL;
                    if(nexsi==-1)
                    {
                        goto WAAA;
                    }
                    else
                    {
                        si=nexsi;
                    }
                }
            }
            else
            {
                int nexsi=nex[si].nexR;
                if(nexsi==-1)
                {
                    goto WAAA;
                }
                else
                {
                    si=nexsi;
                }
            }

        }


        cout<<"YES"<<endl;


        if(0)
        {
            WAAA:;

            cout<<"NO"<<endl;

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
