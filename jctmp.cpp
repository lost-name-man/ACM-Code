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
const int INF = 1e18;

int n, m;
vector<vector<int>> crood;
map<int, int> havepair;
map<int, int> line_row;
vector<int> fa;

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    else
    {
        return fa[x] = findfa(fa[x]);
    }
}

void connect(int x, int y)
{
    int fax = findfa(x), fay = findfa(y);
    if (fax != fay)
    {
        fa[fax] = fay;
    }
}

int conver(int x)
{

    return m - x + 1;
}
void solve()
{
    cin >> n >> m;
    crood = vector<vector<int>>(n + 5, vector<int>(m + 5));
    fa = vector<int>(2 * n + 5);

    havepair = map<int, int>();
    line_row = map<int, int>();
    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char tmp;
            cin >> tmp;
            crood[i][j] = tmp - '0';
        }
        for (int j = 1; j <= m; j++)
        {
            if (crood[i][j] == 1 && crood[i][j] == crood[i][m - j + 1])
            {
                havepair[j] = i;
            }
        }
    }

    {
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (crood[i][j] == 1 && havepair[j] != 0 && havepair[j] != i)
                {
                    ok = 0;
                }
            }
        }
        if (ok == 0)
        {
            cout << 0 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (crood[i][j] == 1)
            {
                if (crood[i][conver(j)] == 1)
                {
                    continue;
                }
                if (line_row[j] == 0)
                {
                    line_row[j] = i;
                    line_row[conver(j)] = i + n;
                }
                else
                {

                    connect(i, line_row[j]);
                    connect(i + n, line_row[conver(j)]);
                }
            }
        }
    }

    {
        int ok = 1;
        for (int i = 1; i <= n; i++)
        {
            if (findfa(i) == findfa(i + n))
            {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            cout << 0 << endl;
            return;
        }
    }

    set<int> st;
    for (int i = 1; i <= 2 * n; i++)
    {
        st.insert(findfa(i));
    }

    int p = st.size() / 2;
    cout << pow(2, p) << endl;
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