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
// #define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;

int n, k;
vector<vector<int>> crood;
vector<vector<int>> pre;
vector<int> column, row;

void initpre()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
}
void solve()
{
    cin >> n >> k;
    crood = pre = vector<vector<int>>(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; i++)
    {
        int x, y, v;

        cin >> x >> y >> v;
        x++;
        y++;
        crood[x][y] += v;
        column.push_back(x);
        row.push_back(y);
    }

    initpre();
    for (int i = 0; i < column.size(); i++)
    {
        for (int j = 0; j < row.size(); j++)
        {
            int nowx = column[i], nowy = row[j];
        }
    }
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
