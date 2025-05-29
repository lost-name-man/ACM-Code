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

// #define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)
#define PI (3.1415926535)
using namespace std;

double R;
pair<double, double> point[6];

struct Node
{
    double x;
    double y;
};

struct Line
{
    double a;
    double b;
    double c;
};

bool cmp(Node &a, Node &b)
{
    return a.x < b.x;
}
pair<double, double> nowpoint[6];
Node nownode[6];
void to_xy()
{
    nownode[0] = {R * cos(nowpoint[0].second * PI / 180),
                  R * sin(nowpoint[0].second * PI / 180)};
    nownode[1] = {R * cos(nowpoint[1].first * PI / 180),
                  R * sin(nowpoint[1].first * PI / 180)};
    nownode[2] = {R * cos(nowpoint[2].first * PI / 180),
                  R * sin(nowpoint[2].first * PI / 180)};

    nownode[4] = {R * cos(nowpoint[4].second * PI / 180),
                  R * sin(nowpoint[4].second * PI / 180)};
}

Line to_line(Node &node1, Node &node2)
{
    Line line1;
    line1.a = node2.y - node1.y;
    line1.b = node1.x - node2.x;
    line1.c = node2.x * node1.y - node1.x * node2.y;
    return line1;
}

Node askcrossnode(Line &line1, Line &line2)
{
    double x, y;
    double up = line1.b * line2.c - line2.b * line1.c;
    double down = line2.b * line1.a - line1.b * line2.a;
    x = (line1.b * line2.c - line2.b * line1.c) / (line2.b * line1.a - line1.b * line2.a);

    y = (line1.a * line2.c - line1.c * line2.a) / (line1.b * line2.a - line1.a * line2.b);
    return {x, y};
}

double asks_t(Node &node1, Node &node2, Node &node3)
{
    vector<Node> arrt;
    arrt.push_back(node1);
    arrt.push_back(node2);
    arrt.push_back(node3);
    sort(arrt.begin(), arrt.end(), cmp);
    double wight = arrt[2].x - arrt[0].x;

    Line line02 = to_line(arrt[0], arrt[2]);

    double line02_y_with_node2_x = (-line02.c - line02.a * arrt[1].x) / line02.b;
    Node plnode = {arrt[1].x,
                   line02_y_with_node2_x};
    double plhigh = abs(plnode.y - arrt[1].y);
    return plhigh * wight / 2;
}

double asks_r(Node node1, Node node2, Node node3)
{
    double theta;
    if (nowpoint[1].first < nowpoint[0].second)
    {
        theta = nowpoint[1].first + 360 - nowpoint[0].second;
    }
    else
    {
        theta = nowpoint[1].first - nowpoint[0].second;
    }

    double bigs = PI * R * R * theta / 360;
    double smalls = asks_t(node1, node2, node3);
    return bigs - smalls;
}
void solve()
{
    scanf("%lf", &R);
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &point[i].first);
    }
    for (int i = 0; i < 5; i++)
    {
        scanf("%lf", &point[i].second);
    }

    double sumarea = 0;
    double rarea = PI * R * R;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            nowpoint[j] = point[(i + j) % 5];
        }
        to_xy();
        Line line1, line2;
        line1 = to_line(nownode[0], nownode[2]);
        line2 = to_line(nownode[1], nownode[4]);

        Node crossnode = askcrossnode(line1, line2);
        double s_r, s_t;
        s_r = asks_r(nownode[0], nownode[1], {(double)0, (double)0});
        s_t = asks_t(nownode[0], nownode[1], crossnode);
        sumarea += s_r + s_t;
    }
    double ans = rarea - sumarea;
    printf("%.10lf\n", ans);
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // cin >> T;
    scanf("%lld", &T);
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}