#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 1e16 + 61;

struct Cir
{
    double x;
    double y;
    double r;
};

double x[5], y[5];
Cir c1, c2;

double euc(double x1, double y1, double x2, double y2)
{
    double x = abs(x1 - x2), y = abs(y1 - y2);
    return sqrt(x * x + y * y);
}

void solve()
{
    vector<Cir> point;
    cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4];
    c1.x = (x[1] + x[2]) / 2;
    c1.y = (y[1] + y[2]) / 2;
    c2.x = (x[3] + x[4]) / 2;
    c2.y = (y[3] + y[4]) / 2;
    c1.r = (x[1], y[1], x[2], y[2]) / 2;
    c2.r = (x[3], y[3], x[4], y[4]) / 2;

    point.push_back({c2.x + sqrt(2) * c2.r / 2, c2.y + sqrt(2) * c2.r / 2, 0});
    point.push_back({c2.x + sqrt(2) * c2.r / 2, c2.y - sqrt(2) * c2.r / 2, 0});
    point.push_back({c2.x - sqrt(2) * c2.r / 2, c2.y + sqrt(2) * c2.r / 2, 0});
    point.push_back({c2.x - sqrt(2) * c2.r / 2, c2.y - sqrt(2) * c2.r / 2, 0});

    double ans = INF;
    for (int i = 0; i < 4; i++)
    {
        double dis = abs(point[i].x - c1.x) + abs(point[i].y - c1.y);
        ans = min(ans, dis);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
