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
const int INF = 1e18;
const int MOD = 11380;

string s;
int f[102][102];
int mp[102][102];
int p[102][102];
int checksame(int l, int r, int len)
{
    string str;
    for (int i = l; i <= l + len - 1; i++)
    {
        str += s[i];
    }
    int re = 0;

    for (int i = l; i + len - 1 <= r; i += len)
    {
        string tmpstr;
        for (int j = i; j <= i + len - 1; j++)
        {
            tmpstr += s[j];
        }
        if (str != tmpstr)
        {
            re = -1;
            break;
        }
        else
        {
            re = f[i][i + len - 1];
        }
    }

    if (re == -1)
    {
        return re;
    }
    int cnt = (r - l + 1) / len;
    re += 2 + to_string(cnt).size();
    return re;
}

void myprint(int l, int r)
{
    if (l == r)
    {
        cout << s[l];
    }
    else if (p[l][r] >= 0)
    {
        myprint(l, p[l][r]);
        myprint(p[l][r] + 1, r);
    }
    else
    {
        int num = -p[l][r];
        int len = (r - l + 1) / (num);

        cout << num << '(';
        myprint(l, l + len - 1);
        cout << ')';
    }
}
void solve()
{
    cin >> s;
    int len = s.size();
    s = '0' + s;

    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j + i - 1 <= len; j++)
        {
            int l = j, r = j + i - 1;
            f[l][r] = i;
            p[l][r] = l;
            for (int si = 1; si < i; si++)
            {
                if (i % si != 0)
                {
                    continue;
                }
                int re = checksame(l, r, si);
                if (re == -1)
                {
                    continue;
                }
                if (re < f[l][r])
                {
                    f[l][r] = re;
                    p[l][r] = -(i / si);
                }
            }

            for (int k = l; k <= r - 1; k++)
            {
                if (f[l][k] + f[k + 1][r] < f[l][r])
                {
                    f[l][r] = f[l][k] + f[k + 1][r];
                    p[l][r] = k;
                }
            }
        }
    }
    myprint(1, len);
    cout << endl;
    // cout << f[1][len] << endl;
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
