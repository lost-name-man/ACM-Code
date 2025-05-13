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

const int N = 1000005;
const int M = N * 2;
using namespace std;

int n;
int arr[N];
int numindex[N];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        numindex[arr[i]] = i;
    }
    int lastindex = 0;
    int maxn = 0;
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (numindex[i] > lastindex)
        {
            len++;
            lastindex = numindex[i];
            maxn = max(len, maxn);
        }
        else
        {
            lastindex = 0;
            len = 1;
        }
    }
    cout << n - maxn << endl;
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