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

void solve()
{
    vector<Node>arr(14);
    for(int i=1; i<=13; i++)
    {
        cin>>arr[i].sum;
        arr[i].drei=arr[i].sum/3;
        arr[i].ein=arr[i].sum%3;

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
