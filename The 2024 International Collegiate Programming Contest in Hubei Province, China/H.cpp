#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
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
#include <iomanip>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;

int n, m, k;
vector<int> dag[2000006];
int target = 0;

vector<pair<int, int>> boomloc;
pair<int, int> steps[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int locfish[1003][1003] = {0};
int vis[2000006] = {0};
void insertboom(int x, int y)
{
    boomloc.push_back({x, y});
    for (int i = 0; i < 4; i++)
    {
        int nx = x + steps[i].first, ny = y + steps[i].second;
        if (nx < 1 || nx > n || ny < 1 || ny > m)
        {
            continue;
        }
        boomloc.push_back({nx, ny});
    }
}
void solve()
{

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y, num;
        cin >> x >> y >> num;
        target += num << (i * 2);
        insertboom(x, y);
        locfish[x][y] = i + 1;
    }
    sort(boomloc.begin(), boomloc.end());
    boomloc.erase(unique(boomloc.begin(), boomloc.end()), boomloc.end());

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0] = 1;
    int ans = 0;
    while (!q.empty())
    {
        int nowst = q.front().first;
        int nowdeep = q.front().second;

        q.pop();

        if (nowst == target)
        {
            ans = nowdeep;
            break;
        }
        for (auto iter = boomloc.begin(); iter != boomloc.end(); iter++)
        {
            int nextst = nowst;
            int x = iter->first, y = iter->second;
            // self
            {
                int nx = x, ny = y;
                int fishid = locfish[nx][ny] - 1;
                if (fishid != -1)
                {

                    int nowfish = (nowst >> (fishid * 2)) % 4;
                    int fishtop = (target >> (fishid * 2)) % 4;
                    if (nowfish == fishtop)
                    {
                    }
                    else
                    {
                        nextst += (1 << (fishid * 2));
                    }
                }
            }
            for (int j = 0; j < 4; j++)
            {
                int nx = x + steps[j].first, ny = y + steps[j].second;
                int fishid = locfish[nx][ny] - 1;
                if (fishid == -1)
                {
                    continue;
                }
                int nowfish = (nowst >> (fishid * 2)) % 4;
                int fishtop = (target >> (fishid * 2)) % 4;
                if (nowfish == fishtop)
                {
                    continue;
                }
                else
                {
                    nextst += (1 << (fishid * 2));
                }
            }
            if (nextst != nowst)
            {
                if (vis[nextst] == 1)
                {
                    continue;
                }
                vis[nextst] = 1;
                q.push({nextst, nowdeep + 1});
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
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}