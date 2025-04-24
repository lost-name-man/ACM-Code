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
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;


int cab(int a, int b)
{
    int ret=1;
    for(int i=b, check=0; check!=a; i--, check++)
    {
        ret*=i;
    }
    for(int i=1, check=0; check!=a; i++, check++)
    {
        ret/=i;
    }

    return ret;
}

void solve()
{

    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    int ans=a*b*c*cab(2, d);
    ans+=a*b*c*d*e;

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