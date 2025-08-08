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
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;

int days[55][400];

void init()
{
    int base = 2025;
    int nowd = 3;
    for (int i = 2025 - base; i <= 2075 - base; i++)
    {

        if ((i + base) % 4 == 0)
        {
            for (int j = 1; j <= 366; j++)
            {

                days[i][j] = nowd++;
                nowd %= 8;
                if (nowd == 0)
                {
                    nowd = 1;
                }
            }
        }
        else
        {
            for (int j = 1; j <= 366; j++)
            {
                if (j == 60)
                {
                    days[i][j] = 6;
                }
                else
                {
                    days[i][j] = nowd++;
                }
                nowd %= 8;
                if (nowd == 0)
                {
                    nowd = 1;
                }
            }
        }
        }
}
void solve()
{
    int base = 2025;
    int k;
    int l, r;
    cin >> k >> l >> r;
    l -= base;
    r -= base;
    priority_queue<int> pq;
    for (int i = 1; i <= 366; i++)
    {
        int nowh = 0;
        for (int j = l; j <= r; j++)
        {
            if (days[j][i] == 6 || days[j][i] == 7)
            {
                nowh++;
            }
        }
        pq.push(nowh);
    }

    int ans = 0;
    while (k--)
    {
        int nowh = pq.top();
        pq.pop();
        ans += (r - l + 1) - nowh;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    init();
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
