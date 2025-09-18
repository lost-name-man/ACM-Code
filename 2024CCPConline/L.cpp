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

vector<string> croods;

int check(int x, int y)
{
    if(croods[x][y]=='c' && croods[x+1][y]=='p' && croods[x][y+1]=='c' && croods[x+1][y+1]=='c' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    int n, m;
    cin >>n>>m;
    croods=vector<string> (n+5);
    for(int i=1; i<=n; i++)
    {
        cin>>croods[i];
        croods[i]="!"+croods[i];
    }
    int ans=0;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=1; j<=m-1; j++)
        {
            if(check(i, j))
            {
                ans++;
            }
        }
    }

    cout<<ans<<endl;


}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
