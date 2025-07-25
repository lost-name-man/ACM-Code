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

vector<int> bitnum;
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    bitnum = vector<int>(65, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < 64; j++)
        {
            if (arr[i] & (1ll << j))
                bitnum[j]++;
        }
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n);
    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        int hibit;
        for (int j = 63; j >= 0; j--)
        {
            if (arr[i] & (1ll << j))
            {
                hibit = j;
                break;
            }
        }
        if (bitnum[hibit] > 1)
        {
            ok = 0;
            break;
        }
        for (int j = 63; j >= 0; j--)
        {
            if (arr[i] & (1ll << j))
            {
                bitnum[j]--;
            }
        }
    }
    if (ok == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
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
