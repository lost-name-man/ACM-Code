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

int n, m;
vector<pair<int, int>> inter;
vector<int> ans;

vector<vector<int>> crood;
vector<int> vis;
void solve()
{
    int n;
    cin >> n >> m;
    inter = vector<pair<int, int>>(m + 5);
    ans = vector<int>(2 * n + 5);
    crood = vector<vector<int>>(2 * n + 5);
    vis = vector<int>(m + 5);
    for (int i = 1; i <= m; i++)
    {
        cin >> inter[i].first >> inter[i].second;
        crood[inter[i].first].push_back(i);
        crood[inter[i].second].push_back(-i);
    }
    sort(inter.begin() + 1, inter.begin() + 1 + m);

    stack<int> st;
    int cntl = 0;
    for (int i = 2 * n; i >= 1; i--)
    {
        int ok = 0;
        for (int j = 0; j < crood[i].size(); j++)
        {
            if (crood[i][j] > 0 && vis[crood[i][j]] == 0)
            {
                ok = 1;
                ans[i] = 1;
                cntl++;
            }
            else
            {
                st.push(-crood[i][j]);
            }
        }
        if (ok == 1)
        {
            while (!st.empty())
            {
                vis[st.top()] = 1;
                st.pop();
            }
        }
    }
    if (cntl > n)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (cntl == n)
        {
            break;
        }
        if (ans[i] == 0)
        {
            ans[i] = 1;
            cntl++;
        }
    }

    int ok = 1;
    int prel = 0, prer = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (ans[i] == 1)
        {
            prel++;
        }
        else
        {
            prer++;
        }
        if (prer > prel)
        {
            ok = 0;
        }
    }
    if (ok == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 1; i <= 2 * n; i++)
        {
            if (ans[i] == 0)
            {
                cout << ')';
            }
            else
            {
                cout << '(';
            }
        }
    }
    cout << endl;
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
