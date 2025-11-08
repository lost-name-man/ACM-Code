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
const int MOD = 1e9+7;



int f[305][305][305][3]={0};
int ans[305][305][305]={0};

void solve()
{
    int n, q;
    cin>>n>>q;
    string str;
    cin>>str;
    str="@"+str;
    

    vector<int>prequo(n+5, 0);

    for(int i=1; i<=n; i++)
    {
        prequo[i]+=prequo[i-1];
        if(str[i]=='?')
        {
            prequo[i]++;
        }
    }

    //a==0 b==1 c==2

    if(str[1]=='?')
    {
        
        f[1][1][0][0]=1;
        f[1][0][1][1]=1;
        f[1][0][0][2]=1;
    }
    else
    {
        f[1][0][0][str[1]-'a']=1;
    }

    
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<=prequo[i]; j++)
        {
            for(int k=0; k<=prequo[i]-j; k++)
            {
                int l=prequo[i]-j-k;


                if(str[i]!='?')
                {
                    int nowch=str[i]-'a';

                    for(int rch=0; rch<=2; rch++)
                    {
                        if(rch==nowch)
                        {
                            continue;
                        }
                        f[i][j][k][nowch] += f[i-1][j][k][rch];
                    }
                }
                else
                {

                    // ------------------------------------
                    // A
                    if(j)
                    {
                        f[i][j][k][0] += f[i-1][j-1][k][1];
                        f[i][j][k][0] += f[i-1][j-1][k][2];
                        f[i][j][k][0] %=MOD;
                    }

                    // B
                    if(k)
                    {
                        f[i][j][k][1] += f[i-1][j][k-1][0];
                        f[i][j][k][1] += f[i-1][j][k-1][2];
                        f[i][j][k][1] %=MOD;
                    }

                    // C
                    if(l)
                    {
                        f[i][j][k][2] += f[i-1][j][k][0];
                        f[i][j][k][2] += f[i-1][j][k][1];
                        f[i][j][k][2] %=MOD;

                    }


                    // ------------------------------------
                }
                
            }
        }
    }


    

    int quonum=prequo[n];


    // for(int j=0; j<=quonum; j++)
    // {
    //     for(int k=0; k<=quonum; k++)
    //     {
    //         for(int l=0; l<=quonum; l++)
    //         {
    //             cout<<"! "<<j<<" "<<k<<" "<<l<<" ==";
    //             cout<<f[n][j][k][l]<<endl;
    //         }

    //     }
    // }





    for(int j=1; j<=quonum; j++)
    {
        for(int k=0; k<=quonum; k++)
        {
            for(int l=0; l<=quonum; l++)
            {
                ans[j][k][l]+=ans[j-1][k][l] + f[n][j][k][l];
            }
        }
    }
    for(int j=0; j<=quonum; j++)
    {
        for(int k=1; k<=quonum; k++)
        {
            for(int l=0; l<=quonum; l++)
            {
                ans[j][k][l]+=ans[j][k-1][l] + f[n][j][k][l];
            }
        }
    }
    for(int j=0; j<=quonum; j++)
    {
        for(int k=0; k<=quonum; k++)
        {
            for(int l=1; l<=quonum; l++)
            {
                ans[j][k][l]+=ans[j][k][l-1] + f[n][j][k][l];
            }
        }
    }

    for(int i=1; i<=q; i++)
    {
        int x, y, z;

        cin>>x>>y>>z;
        x=min(x, quonum);
        y=min(y, quonum);
        z=min(z, quonum);



        cout<<ans[x][y][z]<<endl;

    }




}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    //  cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
