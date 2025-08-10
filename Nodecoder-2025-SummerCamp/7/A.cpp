#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
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
#include <cmath>

using namespace std;
#define int size_t
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e17 + 7;
const int MOD = 1e17 + 7;


void tozehn(int x, vector<int> &zehn)
{
    int format=1;
    if(x<0)
    {
        format=-1;
    }
    x=abs(x);


}

void solve()
{
    int x;
    cin>>x;

    vector<int>zehn;
    
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
