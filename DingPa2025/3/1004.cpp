#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;

struct Node
{
    int sum;
    int ein;
    int drei;
    
};

int total;

int check(int d)
{
    
}



void solve()
{
    vector<Node>arr(14);
    total=0;
    for(int i=1; i<=13; i++)
    {
        cin>>arr[i].sum;
        arr[i].drei=arr[i].sum/3;
        arr[i].ein=arr[i].sum%3;
        total+=arr[i].sum;
    }

    int l=0, r=total/4;

    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(mid))
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }

    }




}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin>>T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
