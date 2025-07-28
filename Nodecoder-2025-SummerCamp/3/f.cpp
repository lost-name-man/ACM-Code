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
#define MOD 998244353

using namespace std;

int n, a, b;
void solve()
{
    cin >> n >> a >> b;
    int less = n % (a + b);
    if (n <= a)
    {
        cout << "Sayonara" << endl;
    }
    else if (less > a)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << less << endl;
    }
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
