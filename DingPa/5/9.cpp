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
#define INF 1e9
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;

vector<int>win;

int qpow(int x, int p)
{
    int base = x,sum=1;
    while (p)
    {
        if (p & 1)
        {
            sum *= base;
            sum %= MOD;
        }
        base = base * base;
        base %= MOD;
        p = p >>1 ;
    }

    return sum % MOD;
}

int inv(int x)
{
    int ret = qpow(x, MOD - 2) % MOD;
    return ret;
}

int adivb(int a, int b)
{
    int ret = (a%MOD * inv(b))%MOD;
    return ret;
}



void solve()
{
    
    int n;
    cin>>n;
    if(n<=5)
    {
        cout<<win[n]<<endl;
    }
    else
    {
        if((n%5==0) || (n%5==2))
        {
            cout<<1<<endl;
        }
        else if(n%5==1)
        {
            int ret=adivb(1, 2);
            ret=qpow(ret, n/5);
            ret=1-ret;
            ret=ret+MOD;
            ret=ret%MOD;
            cout<<ret<<endl;
        }
        else if(n%5==3)
        {
            int ret=adivb(1, 2);
            ret=qpow(ret, n/5+2);
            ret=1-ret;
            ret=ret+MOD;
            ret=ret%MOD;

            cout<<ret<<endl;
        }
        else if(n%5==4)
        {
            int ret=adivb(1, 2);
            ret=qpow(ret, n/5+1);
            ret=1-ret;
            ret=ret+MOD;
            ret=ret%MOD;
            cout<<ret<<endl;
        }
    }
    
}

signed main()
{
    win = vector<int>(10004);
    win[0] = 1;
    win[1] = adivb(1, 2);
    win[2] = 1;
    win[3] = adivb(3, 4);
    win[4] = adivb(1, 2);
    win[5] = 1;
    win[6] = adivb(1, 2);
    win[7] = 1;
    win[8] = adivb(7, 8);



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