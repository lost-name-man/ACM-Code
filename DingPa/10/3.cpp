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
#define MOD (int)(1000000007)

using namespace std;

void test()
{
    vector<int>arr;
    for(int i=1; i<=25; i++)
    {
        arr.emplace_back(i);
        
    }
    for(int i=1; i<=20; i++)
    {
        cout<<"i="<<i<<"----------------"<<endl;
        for(int j=1; j<=i; j++)
        {
            if(__gcd(i, j)==i-j)
            {
                cout<<" j="<<j<<endl;
            }
        }
    }

}

void solve()
{
    
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        test();
        // solve();
    }
    return 0;
}