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


void solve(int T)
{
    int sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;

    vector<pair<int, int>>xy(4);

    cin>>sx1>>sy1>>sx2>>sy2>>tx1>>ty1>>tx2>>ty2;


    int ans=0;

    ans=max(ans, abs(sx1-tx1)+ abs(sy1-ty1))



}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;


    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
}
