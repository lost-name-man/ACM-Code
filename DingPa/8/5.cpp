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

const int N = 1000005;
const int M = N * 2;
using namespace std;

struct Edge
{
};


int n, m;
string stra, strb;
void solve()
{
    cin>>n>>m;
    cin>>stra;
    cin>>strb;
    vector<int>a;
    vector<pair<int, int>>b; //{index, val}


    for(int i=0; i<stra.size(); i++)
    {
        a.push_back((int)(stra[i]-'0'));
    }
    vector<pair<int, int>>cpb;
    for(int i=0; i<strb.size(); i++)
    {
        b.push_back({i, (int)(strb[i]-'0')});
        cpb.push_back({i, (int)(strb[i]-'0')});
    }

    for(int i=0; i<a.size(); i++)
    {
        vector<pair<int, int>>newbsuit;
        vector<pair<int, int>>newbbad;
        for(int j=0; j<b.size(); j++)
        {
            int nowindex=b[j].first, nowval=b[j].second;
            int nextidnex=nowindex+1;
            if((strb.size()-nowindex)<=stra.size()-(i))
            {
                // cout<<"!";
                break;
            }

            if(a[i]==nowval)
            {
                newbbad.push_back({cpb[nextidnex].first, cpb[nextidnex].second});
            }
            else
            {
                newbsuit.push_back({cpb[nextidnex].first, cpb[nextidnex].second});
            }
            // cout<<"@"<<nowindex;
        }

        if(newbsuit.size()!=0)
        {
            b=newbsuit;

            // cout<<"suit:";
        }
        else if(newbbad.size()!=0)
        {
            b=newbbad;
            // cout<<"bad:";
        }
        else
        {
            // cout<<"end:";
        }
        

    }
    
    vector<int>realb;
    int bin=b[0].first-(a.size()-1) -1;
    // cout<<"bin"<<b[0].first<<endl;
    for(int i=0; i<a.size(); i++)
    {
        realb.push_back(cpb[bin].second);
        bin++;
    }
    int ans=0;
    for(int i=0; i<realb.size(); i++)
    {
        if(a[i]^realb[i]==1)
        {
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*
input:
2
3 3 3
1 1 1
2 2 2
3 3 3
3 3 2
1 2 1
2 1 2
1 2 1


output:
3
8

*/