

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
    const bool operator<(const Xy &a) const
    {
        if (this->x == a.x)
        {
            return this->y < a.y;
        }
        return this->x < a.x;
    }
};

int n, m, k;
int crood[1003][1003] = {0};
Xy steps[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
set<Xy> boomloc;
vector<Xy> fishloc;
void insertboomloc(int x, int y)
{
    boomloc.insert({x, y});
    for (int i = 0; i < 4; i++)
    {
        int nowx = x + steps[i].x, nowy = y + steps[i].y;
        if (nowx < 1 || nowx > n || nowy < 1 || nowy > m)
        {
            continue;
        }
        boomloc.insert({nowx, nowy});
    }
}
int checkover()
{
    int ok = 1;
    for (int i = 0; i < fishloc.size(); i++)
    {
        int x = fishloc[i].x, y = fishloc[i].y;
        if (crood[x][y] > 0)
        {
            ok = 0;
            break;
        }
    }
    return ok;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int x, y, num;
        cin >> x >> y >> num;
        crood[x][y] = num;
        fishloc.push_back({x, y});
        insertboomloc(x, y);
    }
    int ans = 0;
    while (checkover() != 1)
    {
        ans++;
        int maxn = 0;
        Xy maxboom;
        for (auto iter = boomloc.begin(); iter != boomloc.end(); iter++)
        {
            int nowx = iter->x, nowy = iter->y;
            int nownum = 0;
            nownum += (crood[nowx][nowy] != 0);
            for (int i = 0; i < 4; i++)
            {
                int nx = nowx + steps[i].x, ny = nowy + steps[i].y;
                nownum += (crood[nx][ny] != 0);
            }
            if (nownum > maxn)
            {
                maxn = nownum;
                maxboom = {nowx, nowy};
            }
        }
        if (crood[maxboom.x][maxboom.y] > 0)
        {
            crood[maxboom.x][maxboom.y]--;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = maxboom.x + steps[i].x, ny = maxboom.y + steps[i].y;
            if (crood[nx][ny] > 0)
            {
                crood[nx][ny]--;
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