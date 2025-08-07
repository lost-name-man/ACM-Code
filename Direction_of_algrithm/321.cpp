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

int n;
int val[10][10];
double f[16][10][10][10][10];
double sumsq[10][10][10][10];
double ax;
void dfs(int times, int x1, int y1, int x2, int y2)
{
    if (f[times][x1][y1][x2][y2])
    {
        return;
    }
    f[times][x1][y1][x2][y2] = INF;
    if (times == 1)
    {
        f[times][x1][y1][x2][y2] = sumsq[x1][y1][x2][y2];
        return;
    }

    for (int i = x1; i < x2; i++)
    {
        dfs(times - 1, x1, y1, i, y2);
        f[times][x1][y1][x2][y2] = min(f[times][x1][y1][x2][y2], f[times - 1][x1][y1][i][y2] + sumsq[i + 1][y1][x2][y2]);
        dfs(times - 1, i + 1, y1, x2, y2);
        f[times][x1][y1][x2][y2] = min(f[times][x1][y1][x2][y2], f[times - 1][i + 1][y1][x2][y2] + sumsq[x1][y1][i][y2]);
    }
    for (int i = y1; i < y2; i++)
    {
        dfs(times - 1, x1, y1, x2, i);
        f[times][x1][y1][x2][y2] = min(f[times][x1][y1][x2][y2], f[times - 1][x1][y1][x2][i] + sumsq[x1][i + 1][x2][y2]);
        dfs(times - 1, x1, i + 1, x2, y2);
        f[times][x1][y1][x2][y2] = min(f[times][x1][y1][x2][y2], f[times - 1][x1][i + 1][x2][y2] + sumsq[x1][y1][x2][i]);
    }
}

double asksum(int x1, int y1, int x2, int y2)
{
    double sum = 0;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            sum += val[i][j];
        }
    }
    return (sum - ax) * (sum - ax);
}
void solve()
{

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> val[i][j];
            sum += val[i][j];
        }
    }
    ax = sum * 1.0 / n;
    for (int x1 = 1; x1 <= 8; x1++)
    {
        for (int x2 = x1; x2 <= 8; x2++)
        {
            for (int y1 = 1; y1 <= 8; y1++)
            {
                for (int y2 = y1; y2 <= 8; y2++)
                {
                    sumsq[x1][y1][x2][y2] = asksum(x1, y1, x2, y2);
                }
            }
        }
    }

    dfs(n, 1, 1, 8, 8);

    cout << fixed << setprecision(3) << sqrt(f[n][1][1][8][8] / n * 1.0) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
