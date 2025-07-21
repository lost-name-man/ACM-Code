#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000007

using namespace std;


void solve()
{
    int n;
    cin>>n;
    double ein=(double)(n*(n+1))/2.0/n;
    // printf("!%.4lf\n", ein);
    double ans=ein + (n+n-1)/2.0;
    printf("%.4lf\n", ans);
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