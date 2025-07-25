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
#define MOD 1000000007

using namespace std;

int n;
vector<int> arr;
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    vector<int> arr0(n + 5), arr1(n + 5);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        arr[i] = ch - '0';
        arr0[i] = arr[i];
        arr1[i] = arr[i];
    }

    int ans0 = 0, ans1 = 0;
    if (arr[1] == 0)
    {
        ans1++;
    }
    else
    {
        ans0++;
    }
    arr0[1] = 0;
    arr1[1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (arr0[i] != arr0[i - 1])
        {
            continue;
        }
        else
        {
            if (arr0[i + 1] == arr0[i])
            {
                arr0[i] = arr0[i] ^ 1;
                ans0++;
            }
            else
            {
                swap(arr0[i], arr0[i + 1]);
                ans0++;
            }
        }
    }
    if (arr0[n] == 0)
    {
        ans0++;
    }

    for (int i = 2; i < n; i++)
    {
        if (arr1[i] != arr1[i - 1])
        {
            continue;
        }
        else
        {
            if (arr1[i + 1] == arr1[i])
            {
                arr1[i] = arr1[i] ^ 1;
                ans1++;
            }
            else
            {
                swap(arr1[i], arr1[i + 1]);
                ans1++;
            }
        }
    }
    if (arr1[n] == 1)
    {
        ans1++;
    }
    ///////////////////////////////////////

    for (int i = 1; i <= n; i++)
    {
        arr0[i] = arr[i];
        arr1[i] = arr[i];
    }
    int ans00 = 0, ans11 = 0;
    if (arr[1] == 0)
    {
        ans11++;
    }
    else
    {
        ans00++;
    }
    arr0[1] = 0;
    arr1[1] = 1;
    for (int i = n; i > 2; i--)
    {
        int lastindex = i + 1;
        if (i + 1 > n)
        {
            lastindex = 1;
        }
        if (arr0[i] != arr0[lastindex])
        {
            continue;
        }
        else
        {
            if (arr0[i - 1] == arr0[i])
            {
                arr0[i] = arr0[i] ^ 1;
                ans00++;
            }
            else
            {
                swap(arr0[i], arr0[i - 1]);
                ans00++;
            }
        }
    }
    if (arr0[2] == 0)
    {
        ans00++;
    }

    for (int i = n; i > 2; i--)
    {
        int lastindex = i + 1;
        if (i + 1 > n)
        {
            lastindex = 1;
        }
        if (arr1[i] != arr1[lastindex])
        {
            continue;
        }
        else
        {
            if (arr1[i - 1] == arr1[i])
            {
                arr1[i] = arr1[i] ^ 1;
                ans11++;
            }
            else
            {
                swap(arr1[i], arr1[i - 1]);
                ans11++;
            }
        }
    }
    if (arr1[2] == 1)
    {
        ans11++;
    }
    cout << min({ans0, ans1, ans00, ans11}) << endl;
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
