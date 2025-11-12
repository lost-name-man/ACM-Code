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
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int n;
vector<int> arr, brr, crr;

bool p(int num)
{
    // vector<int> pre(n + 5);
    //  int cnt = 0;
    vector<int> inv1, inv2;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            if (brr[i] >= num)
            {
                inv1.push_back(1);
            }
            continue;
        }
        int lx = (num - brr[i]) / arr[i];
        int exp = (((num - brr[i]) % arr[i]) != 0);

        int tmpa = (num - brr[i]), tmpb = arr[i];
        if (tmpa > 0 && tmpb < 0 || tmpa > 0 && tmpb < 0)
        {
            if (arr[i] > 0)
            {
                int lindex;
                if (exp)
                {
                    lindex = (lower_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }
                else
                {
                    lindex = (lower_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }

                inv1.push_back(lindex);
            }
            else
            {
                int rindex;

                if (exp)
                {
                    rindex = (lower_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }
                else
                {
                    rindex = (upper_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin() - 1);
                }
                inv2.push_back(rindex - 1);
            }
        }
        else
        {

            if (arr[i] > 0)
            {
                int lindex;
                if (exp)
                {
                    lindex = (upper_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }
                else
                {
                    lindex = (lower_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }

                inv1.push_back(lindex);
            }
            else
            {
                int rindex;

                if (exp)
                {
                    rindex = (upper_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }
                else
                {
                    rindex = (upper_bound(crr.begin() + 1, crr.begin() + 1 + n, lx) - crr.begin());
                }
                inv2.push_back(rindex - 1);
            }
        }
    }
    sort(inv1.begin(), inv1.end(), greater<int>());
    sort(inv2.begin(), inv2.end());

    int nownum = 0;
    int index1 = n, index2 = 1;
    for (int i = 0; i < inv1.size(); i++)
    {
        if (index1 >= inv1[i] && index1 >= index2)
        {
            index1--;
            nownum++;
        }
    }
    for (int i = 0; i < inv2.size(); i++)
    {
        if (index2 <= inv2[i] && index1 >= index2)
        {
            index2++;
            nownum++;
        }
    }
    if (nownum >= (n / 2 + n % 2))
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
    cin >> n;
    arr = brr = crr = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> crr[i];
    }
    sort(crr.begin() + 1, crr.begin() + 1 + n);

    int l = -2 * (1e18), r = 2 * 1e18;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        // int mid = (l + r) / 2;
        if (p(mid))
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
