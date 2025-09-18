#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

void solve()
{
    
    int n, k;
    cin>>n>>k;
    if(n%2==1)
    {
        cout<<"Alice"<<endl;
        return;
    }
    else if (k>=n)
    {
        cout<<"Alice"<<endl;
        return;
    }
    else
    {
        int zweiplus=0;
        {
            int tmpn=n;
            while(tmpn%2==0)
            {
                tmpn/=2;
                zweiplus+=1;
            }
        }

        if(k>=pow(2, zweiplus))
        {
            cout<<"Alice"<<endl;
            return;
        }
        else
        {
            cout<<"Bob"<<endl;
            return;
        }
        
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
