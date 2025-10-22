#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

struct Node
{
    int type;
    int x;
    int y;
};

vector<Node> allp;
map<int, int> line;
map<pair<int, int>, int> roadp;

map<int, map<int, bool>> line_dis_isroad;

bool cmp1(Node &a, Node &b)
{
    if (a.x == b.x)
    {
        return a.type < b.type;
    }
    return a.x < b.x;
}
bool cmp2(Node &a, Node &b)
{
    if (a.x == b.x)
    {
        return a.type < b.type;
    }
    return a.x > b.x;
}
bool cmp3(Node &a, Node &b)
{
    if (a.y == b.y)
    {
        return a.type < b.type;
    }
    return a.y < b.y;
}
bool cmp4(Node &a, Node &b)
{
    if (a.y == b.y)
    {
        return a.type < b.type;
    }
    return a.y > b.y;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    allp = vector<Node>();
    line = map<int, int>();
    line_dis_isroad = map<int, map<int, bool>>();
    roadp = map<pair<int, int>, int>();

    int endx = 0,
        endy = 0;
    allp.push_back({endx, endy, 0});
    roadp[{endx, endy}] = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'U')
        {
            endy++;
        }
        else if (s[i] == 'D')
        {
            endy--;
        }
        else if (s[i] == 'L')
        {
            endx--;
        }
        else
        {
            endx++;
        }
        allp.push_back({0, endx, endy});
        roadp[{endx, endy}] = 1;
    }

    int num = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (roadp[{x, y}] == 1)
        {
            num++;
        }
        allp.push_back({1, x, y});
    }

    int a = endy, b = -endx;
    if (endx == 0 && endy == 0)
    {
        cout << num << endl;
        return;
    }

    int moder;
    int modtype; // 0==x, 1==y

    if (endx > 0)
    {
        sort(allp.begin(), allp.end(), cmp1);
        moder = endx;
        modtype = 0;
    }
    else if (endx < 0)
    {
        sort(allp.begin(), allp.end(), cmp2);
        moder = endx;
        modtype = 0;
    }
    else
    {
        if (endy > 0)
        {
            sort(allp.begin(), allp.end(), cmp3);
            moder = endy;
            modtype = 1;
        }
        else
        {
            sort(allp.begin(), allp.end(), cmp4);
            moder = endy;
            modtype = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < allp.size(); i++)
    {
        int nowc = allp[i].x * a + allp[i].y * b;
        int nowx = allp[i].x;
        int nowy = allp[i].y;
        int nowdis;
        if (modtype == 0)
        {
            nowdis = nowx % moder;
        }
        else
        {
            nowdis = nowy % moder;
        }

        if (allp[i].type == 0)
        {
            line_dis_isroad[nowc][nowdis] = 1;
        }
        else
        {
            if (line_dis_isroad[nowc][nowdis] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
