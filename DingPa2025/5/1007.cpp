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
const int INF = 1e16 + 7;
const int MOD = 1e9+7;


struct Node
{
    int son, mu;
};

int qpow(int base, int p)
{
    
}


Node cxx(int down, int up)
{
    int u=1;
    for(int i=down; i>down-up; i--)
    {
        u*=i;
        u%=MOD;
    }

    int d=1;
    for(int i=1; i<=up; i++)
    {
        d*=i;
        d%=MOD;
    }


    return {u, d};

}

void solve()
{

    

    int n, k;
    cin >> n >> k;
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
