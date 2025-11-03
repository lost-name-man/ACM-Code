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

vector<int> fa;

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = findfa(fa[x]);
}

void connect(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    if (fax != fay)
    {
        fa[fax] = fay;
    }
}
void solve()
{
    fa = vector<int>(26);
    for (int i = 0; i < 26; i++)
    {
        fa[i] = i;
    }
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (s1.size() != s2.size())
    {
        cout << "NO" << endl;
        return;
    }
    else if (s1.size() != s3.size())
    {
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i])
        {
            connect(s1[i] - 'a', s2[i] - 'a');
        }
    }

    int ok = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == s3[i])
        {
            continue;
        }
        if (findfa(s1[i] - 'a') != findfa(s3[i] - 'a'))
        {
            ok = 1;
            break;
        }
    }

    if (ok == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;

    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
