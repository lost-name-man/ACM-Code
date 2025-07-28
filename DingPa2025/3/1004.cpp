#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;

int total;
vector<int> arr;

int check(int x)
{
    int minn = 0, maxn = 0;
    int ok = 1;
    for (int i = 1; i <= 13; i++)
    {
        int down = (arr[i] - total + 3 * x + 1) / 2;
        int up = arr[i] / 3;
        down = max(0ll, down);
        minn += down;
        maxn += up;
        if (down > up)
        {
            ok = 0;
            break;
        }
    }
    if (x >= minn && x <= maxn && ok == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void solve()
{
    arr = vector<int>(14, 0);
    total = 0;
    for (int i = 1; i <= 13; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    int l = 0, r = total / 4, ans;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
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
