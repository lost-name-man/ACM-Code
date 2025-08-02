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
const int INF = 1e16 + 7;
const int MOD = 1e9 + 7;

int num[5];
vector<int> item[5];
vector<int> it;
int initans(int x, int y)
{

    int ans = 0;
    for (int i = 0; i <= x - 1; i++)
    {
        ans += item[3][i];
    }
    for (int i = 0; i <= y - 1; i++)
    {
        ans += item[4][i];
    }
    return ans;
}
void solve()
{
    it = vector<int>(5, 0);
    for (int i = 1; i <= 4; i++)
    {
        item[i] = vector<int>();
    }
    // int sumsq = 0;
    int ans = 0;
    for (int i = 1; i <= 4; i++)
    {
        cin >> num[i];
        // sumsq += num[i];
    }
    for (int i = 1; i <= 4; i++)
    {
        int k, val;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> val;
            item[i].push_back(val);
        }
        for (int j = 1; j <= 500; j++)
        {
            item[i].push_back(0);
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        sort(item[i].begin(), item[i].end(), greater<int>());
    }

    int val1 = 0;
    while (num[1])
    {
        val1 += item[1][it[1]];
        num[1]--;
        it[1]++;
    }

    for (int i = 0; i <= 100; i++) // three
    {
        for (int j = 0; j <= 100; j++) // four
        {
            if (i > num[3] || j > num[4])
            {
                break;
            }
            int tmpans = initans(i, j) + val1;
            int less3 = num[3] - i, less4 = num[4] - j;

            int tmpit1 = it[1], tmpit2 = it[2];
            for (int k = 1; k <= less3; k++)
            {
                tmpans += item[1][tmpit1++];
            }
            int twi = num[2] + less3 + less4 * 2;
            while (twi)
            {
                if (item[1][tmpit1] + item[1][tmpit1 + 1] > item[2][tmpit2])
                {
                    tmpans += item[1][tmpit1] + item[1][tmpit1 + 1];
                    tmpit1 += 2;
                }
                else
                {
                    tmpans += item[2][tmpit2];
                    tmpit2++;
                }
                twi--;
            }
            ans = max(ans, tmpans);
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
