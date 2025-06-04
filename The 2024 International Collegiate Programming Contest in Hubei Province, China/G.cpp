

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
#define MOD (int)(998244353)

using namespace std;

struct Xy
{
    int x;
    int y;
};
int m;
int crood[21][21] = {0};
int lib[21][21] = {0};
Xy steps[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int vis[21][21] = {0};

int del1 = 0, del2 = 0;
int sum1 = 0, sum2 = 0;
void bfs(int x, int y, int c)
{
    queue<Xy> q;
    vector<Xy> del;
    q.push({x, y});
    vis[x][y] = 1;
    int ok = 0;
    while (!q.empty())
    {
        int nowx = q.front().x, nowy = q.front().y;
        q.pop();
        if (lib[nowx][nowy] != 0)
        {
            ok = 1;
            break;
        }
        else
        {
            del.push_back({nowx, nowy});
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = nowx + steps[i].x, ny = nowy + steps[i].y;
            if (crood[nx][ny] == c && vis[nx][ny] == 0)
            {
                q.push({nx, ny});
                vis[nx][ny] = 1;
            }
        }
    }
    if (ok == 1) // no thing
    {
        return;
    }

    for (int i = 0; i < del.size(); i++)
    {
        int nowx = del[i].x, nowy = del[i].y;
        crood[nowx][nowy] = 0;
        for (int j = 0; j < 4; j++)
        {
            int nx = nowx + steps[j].x, ny = steps[j].y + nowy;
            lib[nx][ny]++;
        }
        if (c == 1)
        {
            del1++;
        }
        else
        {
            del2++;
        }
    }
}
void solve()
{
    for (int i = 0; i <= 20; i++)
    {
        crood[0][i] = 3;
        crood[20][i] = 3;
        crood[i][0] = 3;
        crood[i][20] = 3;
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        del1 = 0;
        del2 = 0;
        int nowc;
        if (i % 2 == 1)
        {
            nowc = 1;
        }
        else
        {
            nowc = 2;
        }
        if (nowc == 1)
        {
            sum1++;
        }
        else
        {
            sum2++;
        }
        int x, y;
        cin >> x >> y;
        crood[x][y] = nowc;
        int nowlib = 4;
        for (int j = 0; j < 4; j++)
        {
            int nx = steps[j].x + x, ny = steps[j].y + y;
            if (crood[nx][ny] != 0)
            {
                nowlib--;
                lib[nx][ny]--;
            }
        }
        lib[x][y] = nowlib;

        memset(vis, 0, sizeof(vis));
        if (nowc == 1)
        {
            for (int i = 1; i <= 19; i++)
            {
                for (int j = 1; j <= 19; j++)
                {
                    if (vis[i][j] == 1 || crood[i][j] != 2)
                    {
                        continue;
                    }
                    bfs(i, j, crood[i][j]);
                }
            }
            for (int i = 1; i <= 19; i++)
            {
                for (int j = 1; j <= 19; j++)
                {
                    if (vis[i][j] == 1 || crood[i][j] != 1)
                    {
                        continue;
                    }
                    bfs(i, j, crood[i][j]);
                }
            }
        }
        else
        {
            for (int i = 1; i <= 19; i++)
            {
                for (int j = 1; j <= 19; j++)
                {
                    if (vis[i][j] == 1 || crood[i][j] != 1)
                    {
                        continue;
                    }
                    bfs(i, j, crood[i][j]);
                }
            }
            for (int i = 1; i <= 19; i++)
            {
                for (int j = 1; j <= 19; j++)
                {
                    if (vis[i][j] == 1 || crood[i][j] != 2)
                    {
                        continue;
                    }
                    bfs(i, j, crood[i][j]);
                }
            }
        }
        cout << del1 << ' ' << del2 << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}