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
vector<int> arr0(n + 5);
int prun()
{
    int ans = 0;
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
                ans++;
            }
            else
            {
                swap(arr0[i], arr0[i + 1]);
                ans++;
            }
        }
    }
    if (arr0[n] == arr0[1])
    {
        ans++;
    }
    return ans;
}
int nrun()
{
    int ans = 0;
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
                ans++;
            }
            else
            {
                swap(arr0[i], arr0[i - 1]);
                ans++;
            }
        }
    }
    if (arr0[2] == arr0[1])
    {
        ans++;
    }
    return ans;
}
void initarr0()
{
    for (int i = 1; i <= n; i++)
    {
        arr0[i] = arr[i];
    }
}
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);

    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        arr[i] = ch - '0';
        arr0[i] = arr[i];
    }

    int ans;
    ans = prun();
    initarr0();
    ans = min(ans, nrun());

    initarr0();
    arr0[1] ^= 1;
    ans = min(ans, prun() + 1);
    initarr0();
    arr0[1] ^= 1;
    ans = min(ans, nrun() + 1);

    initarr0();
    swap(arr0[1], arr0[n]);
    ans = min(ans, prun() + 1);
    initarr0();
    swap(arr0[1], arr0[n]);
    ans = min(ans, nrun() + 1);

    initarr0();
    swap(arr0[1], arr0[2]);
    ans = min(ans, prun() + 1);
    initarr0();
    swap(arr0[1], arr0[2]);
    ans = min(ans, nrun() + 1);
    cout << ans << endl;
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
