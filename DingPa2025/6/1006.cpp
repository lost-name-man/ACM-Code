#include <cstddef>
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
#include <random>
#include <chrono>
using namespace std;
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;

int k, n, a, b, c, d;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lca(int a, int b)
{
    return a * b / (gcd(a, b));
}

int cmp(int a, int b, int c, int d)
{
    int base = lca(b, d);

    int aa = a * (base / b);
    int cc = c * (base / d);

    if (aa >= cc)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> k >> n >> a >> b >> c >> d;
    int times1 = k * d / (c * n);

    int son2 = k;
    int fa2 = n * (times1 + 1);
    int times2 = times1 + 1;
    // int base = lca(lca(fa2,b),d);

    // int aa = a * (b / base);
    // int cc = c * (d / base);
    // int son22 = son2 * (fa2 / base);
    // cout << "#" << son2 << " " << fa2 << endl;
    if (cmp(a, b, son2, fa2))
    {
        int son = (times1 + 1) * c;
        int fa = d;
        cout << son / gcd(son, fa) << '/' << fa / gcd(son, fa) << endl;
    }
    else
    {
        int son4 = (times2 + 1) * son2;
        int fa4 = fa2;
        int son3 = (times1 + 1) * c;
        int fa3 = d;
        int anss3 = son3 / gcd(son3, fa3);
        int ansf3 = fa3 / gcd(son3, fa3);
        int anss4 = son4 / gcd(son4, fa4);
        int ansf4 = fa4 / gcd(son4, fa4);
        cout << "!";
            cout << son3 / gcd(son3, fa3) << '/' << fa3 / gcd(son3, fa3) << endl;
        cout << "@";
            cout << son4 / gcd(son4, fa4) << '/' << fa4 / gcd(son4, fa4) << endl;
        if (cmp(anss3, ansf3, anss4, ansf4))
        {
            cout << "!";
            cout << son3 / gcd(son3, fa3) << '/' << fa3 / gcd(son3, fa3) << endl;
        }
        else
        {
            cout << "@";
            cout << son4 / gcd(son4, fa4) << '/' << fa4 / gcd(son4, fa4) << endl;
        }
    }
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
