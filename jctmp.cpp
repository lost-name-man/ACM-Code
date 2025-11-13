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
const int INF = 1e18;

int n, m, k;
vector<vector<int>> crood, anscrood;

pair<int, int> steps[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int checkout(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> m >> k;
    crood = vector<vector<int>>(n + 5, vector<int>(m + 5));
    anscrood = vector<vector<int>>(n + 5, vector<int>(m + 5, INF));

    int headx, heady;
    for (int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (i == 1)
        {
            headx = x, heady = y;
        }
        crood[x][y] = k - i + 1;
    }
    crood[headx][heady] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == '#')
            {
                crood[i][j] = INF;
            }
        }
    }

    // bfs
    vector<vector<int>> vis(n + 5, vector<int>(m + 5));
    queue<pair<int, int>> q;

    anscrood[headx][heady] = 0;
    q.push({headx, heady});
    while (!q.empty())
    {
        int nowx = q.front().first, nowy = q.front().second;
        q.pop();
        vis[nowx][nowy] = 0;
        for (int i = 0; i < 4; i++)
        {
            int nextx = nowx + steps[i].first, nexty = nowy + steps[i].second;
            if (checkout(nextx, nexty) == 1)
            {
                if (max(anscrood[nowx][nowy] + 1, crood[nextx][nexty]) < anscrood[nextx][nexty])
                {
                    anscrood[nextx][nexty] = max(anscrood[nowx][nowy] + 1, crood[nextx][nexty]);
                    if (vis[nextx][nexty] == 0)
                    {
                        q.push({nextx, nexty});
                        vis[nextx][nexty] = 1;
                    }
                }
            }
        }
    }

    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (anscrood[i][j] == INF)
            {
                continue;
            }
            else
            {
                ans += anscrood[i][j] * anscrood[i][j];
            }
        }
    }
    cout << ans << endl;
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
