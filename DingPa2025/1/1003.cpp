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
#define MOD 1000000000000000003

using namespace std;

const int N = (1 << 17);
int n;
vector<int> arr;
int val[17];

vector<int> f;
void solve()
{
    cin >> n;
    arr = vector<int>(n + 5);
    f = vector<int>(N + 10);
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        arr[i] = ch - 'a';
    }

    for (int i = 0; i < 17; i++)
    {
        cin >> val[i];
    }
    int len;
    cin >> len;
    if (len & 1)
    {
        len++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (i + len - 1 > n)
        {
            break;
        }
        int nowst = 0;
        for (int j = 0; j < len; j++)
        {
            if (arr[i + j] < arr[i + len - 1 - j])
            {
                nowst |= (1 << arr[i + j]);
            }
            else if (arr[i + j] > arr[i + len - 1 - j])
            {
                nowst |= (1 << arr[i + len - 1 - j]);
            }
            else
            {
                nowst = 0;
                break;
            }
        }
        if (nowst == 0)
        {
            continue;
        }
        f[nowst] = 1;
    }

    for (int j = 0; j < 17; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if ((i >> j) & 1)
            {
                f[i] |= f[i ^ (1 << j)];
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < N; i++)
    {
        if (f[i] > 0)
        {
            continue;
        }
        int sum = 0;
        for (int j = 0; j < 17; j++)
        {
            if (((i >> j) & 1) == 0)
            {
                sum += val[j];
            }
        }
        ans = min(ans, sum);
    }
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