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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

const int N = 1000005;
const int M = N * 2;
using namespace std;

struct Edge
{
};

int n, m, k;
int color[1003][1003];
int viscol[2003];
void solve()
{

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> color[i][j];
        }
    }

    int initx = -1;
    int colnum = 0;
    memset(viscol, 0, sizeof(viscol));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (viscol[color[i][j]] == 0)
            {
                colnum++;
            }
            viscol[color[i][j]]++;
        }
        if (colnum == k)
        {
            initx = i;
            break;
        }
    }

    if (initx == -1)
    {
        cout << 0 << endl;
        return;
    }

    int inity = m;
    int ans = 0;
    for (int i = initx; i <= n; i++)
    {
        for (int j = inity; j >= 1; j--)
        {
            int ok = 1;
            for (int h = 1; h <= i; h++)
            {
                int nowcol = color[h][j];
                viscol[nowcol]--;
                if (viscol[nowcol] <= 0)
                {
                    ok = 0;
                }
            }
            if (ok == 0)
            {
                // j no
                inity = j;
                for (int h = 1; h <= i; h++)
                {
                    int nowcol = color[h][j];
                    viscol[nowcol]++;
                }
                ans += i * (m - j);
                break;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}

/*
input:
1
2 3 10
3 4
2 5
4 7
2 4
3 6
4 8


output:
15

*/