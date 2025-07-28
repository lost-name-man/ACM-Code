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
#define int size_t
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 2e9 + 7;
const int MOD = 1e17 + 7;

void solve()
{

    int n;
    cin >> n;
    vector<int> p(n + 5, 0);
    int null = 0;
    int ein = 0;
    int maxn = 0;
    int oufsum=0;
    int check=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == 0)
        {
            null = 1;
        }
        else if (p[i] == 1)
        {
            ein++;
        }
        else
        {
            if(check<2)
            {
                oufsum+=p[i]-1;
                check++;
            }
            else
            {
                oufsum+=p[i]-2;
            }
            
        }
        maxn = max(maxn, p[i]);
    }

    if (null)
    {
        cout << "NO" << endl;
    }
    else if (ein<=2)
    {
        cout<<"YES"<<endl;
    }
    else if(ein>2)
    {
        if(maxn>=ein)
        {
            cout<<"YES"<<endl;
        }
        else if(oufsum>=ein)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
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
