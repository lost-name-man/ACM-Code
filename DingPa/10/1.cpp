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

void solve()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str;
        int t;
        cin >> t;
        int hours = (str[0] - '0') * 10 + (str[1] - '0');
        int mins = (str[3] - '0') * 10 + (str[4] - '0');
        hours += t;
        hours += 24;
        hours %= 24;
        if(hours<10)
        {
            cout<<0;
        }
        cout << hours << ":" ;
        if(mins<10)
        {
            cout<<0;
        }
        cout<< mins << endl;
    }
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