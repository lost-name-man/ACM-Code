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

struct Crood
{
    int x;
    int y;
    int z;
};

struct Dire
{
    int val;
    int id;

    bool operator<(const Dire& other) const
    {
        return this->val < other.val;
    }
};

struct Tdire
{
    int val;
    int xid;
    int yid;
    int zid;


    bool operator<(const Tdire& other) const
    {
        return this->val < other.val;
    }
};


int n, m;
Crood planet[N];
Crood p[N];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> planet[i].x >> planet[i].y >> planet[i].z;
    }

    vector<Dire> xdir(m + 5), ydir(m + 5), zdir(m + 5);
    vector<int> vis(m + 5, 0);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        p[i].x = planet[a].x + planet[b].x;
        p[i].y = planet[a].y + planet[b].y;
        p[i].z = planet[a].z + planet[b].z;
        xdir[i].val = planet[a].x + planet[b].x;
        xdir[i].id = i;
        ydir[i].val = planet[a].y + planet[b].y;
        ydir[i].id = i;
        zdir[i].val = planet[a].z + planet[b].z;
        zdir[i].id = i;

    }
    sort(xdir.begin() + 1, xdir.begin() + 1 + m);
    sort(ydir.begin() + 1, ydir.begin() + 1 + m);
    sort(zdir.begin() + 1, zdir.begin() + 1 + m);
    map<int, Crood> mp;
    for (int i = 1; i <= m; i++)
    {
        int nowx = xdir[i].id, nowy = ydir[i].id, nowz = zdir[i].id;
        mp[nowx].x = i;
        mp[nowy].y = i;
        mp[nowz].z = i;
    }
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({ 0,1 });
    int ans = 0;
    while (!pq.empty())
    {
        int nownode = pq.top().second;
        int nowx = mp[nownode].x;
        int nowy = mp[nownode].y;
        int nowz = mp[nownode].z;

        if (vis[nownode])
        {
            pq.pop();
            continue;
        }
        //cout << "##" << pq.top().first << endl;
        vis[nownode] = 1;
        ans += pq.top().first;
        pq.pop();

        if (nowx != 1)
        {
            pq.push({ xdir[nowx].val - xdir[nowx - 1].val,xdir[nowx - 1].id });
        }
        if (nowx != m)
        {
            pq.push({ xdir[nowx + 1].val - xdir[nowx].val,xdir[nowx + 1].id });
        }
        if (nowy != 1)
        {
            pq.push({ ydir[nowy].val - ydir[nowy - 1].val,ydir[nowy - 1].id });
        }
        if (nowy != m)
        {
            pq.push({ ydir[nowy + 1].val - ydir[nowy].val,ydir[nowy + 1].id });
        }
        if (nowz != 1)
        {
            pq.push({ zdir[nowz].val - zdir[nowz - 1].val,zdir[nowz - 1].id });
        }
        if (nowz != m)
        {
            pq.push({ zdir[nowz + 1].val - zdir[nowz].val,zdir[nowz + 1].id });
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


*/