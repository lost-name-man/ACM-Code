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

const int top = 5000000;

int n;
vector<int> arr;

int spf[top + 5] = {0};

void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        int nownum = arr[i];
        while (nownum > 1)
        {
            int p = spf[nownum];
            while (nownum % p == 0)
            {
                mp[p]++;
                nownum /= p;
            }
        }
    }
    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if (n == 2 && arr[1] != arr[2])
    {
        cout << "NO" << endl;
        return;
    }
    int ok = 1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int nownum = it->second;
        if (nownum % 2 == 1 && n % 2 == 0)
        {
            ok = 0;
            break;
        }
    }
    if (ok == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

void init()
{

    for (int i = 2; i <= top; ++i)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j <= top; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}
signed main()
{

    init();
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
