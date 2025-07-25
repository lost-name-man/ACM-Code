#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;


struct Inval
{
    int l;
    int r;
    
    bool operator <(const Inval &other) const
    {
        if(this->l < other.l)
        {
            return this->r > other.r;
        }
        return this->l < other.l;
    }


};

void solve()
{
    int n;
    cin>>n;
    vector<Inval>arr(n+5);
    for(int i=1; i<=n; i++)
    {   
        cin>>arr[i].l>>arr[i].r;
    }

    sort(arr.begin()+1, arr.begin()+1+n);


    arr[0].l=-1;
    arr[0].r=-1;
    int ans=1;
    int 
    for(int i=1; i<=n; i++)
    {
        int nowl=arr[i].l;
        int nowr=arr[i].r;
        int lastl=arr[i-1].l;
        int lastr=arr[i-1].r;
        

    }

    cout<<ans<<endl;



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
