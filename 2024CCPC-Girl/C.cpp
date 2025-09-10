#include <cstddef>
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
#include <random>
#include <chrono>
using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 2e9 + 7;
const int MOD = 1e17 + 7;



void solve()
{
    
    string str;
    cin>>str;
    int ein=0;
    int len=0;
    double ans=0;
    str=str+"0";
    for(int i=0; i<str.size(); i++)
    {
        if(ein==0)
        {
            if(str[i]=='0')
            {

            }
            else
            {
                ein=1;
                len=1;
            }
        }
        else
        {
            if(str[i]=='0')
            {
                if(len<=2)
                {
                    ans+=pow(len, 0.5);
                }
                else
                {
                    if(len%2==1)
                    {
                        int leaves=len-(len-1)/2;
                        ans+=leaves;
                    }
                    else
                    {
                        int leaves=len-(len-1)/2-2;
                        ans+=leaves + pow(2, 0.5);
                    }
                }

                ein=0;
                len=0;
            }
            else
            {
                len+=1;
            }
        }

        // printf("@%.9lf\n", ans);

    }

    printf("%.9lf\n", ans);
    

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
