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
const int INF = 1e18 + 3;
const int MOD = 998244353;

int n, k;

vector<int> fa;
vector<pair<int, int>> crood;

struct Edge
{
    int x;
    int y;
    double dis;
    bool operator<(const Edge &other) const
    {
        return this->dis > other.dis;
    }
};

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = findfa(fa[x]);
}

void connnect(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    if (fax != fay)
    {
        fa[fax] = fay;
    }
}
void solve()
{
    cin >> n >> k;
    fa = vector<int>(n + 5);

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    crood = vector<pair<int, int>>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        int x, y;

        cin >> x >> y;
        crood[i] = {x, y};
    }
    priority_queue<Edge> pq;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double dis = sqrt((crood[i].first - crood[j].first) * (crood[i].first - crood[j].first) + (crood[i].second - crood[j].second) * (crood[i].second - crood[j].second));
            pq.push({i, j, dis});
        }
    }

    int num = n;
    while (num > k)
    {
        Edge nowedge = pq.top();
        pq.pop();
        int fax = findfa(nowedge.x), fay = findfa(nowedge.y);
        if (fax != fay)
        {
            connnect(fax, fay);
            num--;
        }
    }
    double ans;
    while (!pq.empty())
    {
        Edge nowedge = pq.top();
        pq.pop();
        int fax = findfa(nowedge.x), fay = findfa(nowedge.y);
        if (fax != fay)
        {
            ans = nowedge.dis;
            break;
        }
    }
    cout << setprecision(9) << fixed << ans << endl;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    // cin >> T;

    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
