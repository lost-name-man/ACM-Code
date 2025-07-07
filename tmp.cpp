#include <bits/stdc++.h>

#define int long long
#define INF ((long long)1e18)
#define endl '\n'
#define MOD 998244353

using namespace std;

const int N = 1000000;

void solve()
{
    int st1;
    st1 = 5;

    for (int st2 = (st1 - 1) & st1; st2; st2 = (st2 - 1) & st1)
    {
        cout << st2 << endl;
    }
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}

/*

3 4
0 3
1 1
1 2
2 2


3 5
0 3
1 1
1 2
1 3
2 2

10 8
0 3
1 3
2 3
3 3
4 3
5 3
6 3
7 3

*/
