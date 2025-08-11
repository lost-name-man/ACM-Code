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
const int MOD = 998244353;

int n;
vector<int> arr, id, pre, f;

vector<pair<int, int>> inver;

void sta()
{
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            inver[st.top()].second = i - 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        inver[st.top()].second = n;
        st.pop();
    }

    st = stack<int>();
    for (int i = n; i >= 1; i--)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            inver[st.top()].first = i + 1;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        inver[st.top()].first = 1;
        st.pop();
    }
}

int getmod(int x)
{
    return (x % MOD + MOD) % MOD;
}
void solve()
{
    cin >> n;
    arr = id = pre = f = vector<int>(n + 5);
    inver = vector<pair<int, int>>(n + 5);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        id[arr[i]] = i;
    }
    sta();

    f[0] = 1;
    pre[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        for (int j = 1; j <= n; j++)
        {
            if (id[j] > i || inver[j].second < i)
            {
                continue;
            }
            int nowl = inver[j].first;
            int index = id[j];
            f[i] += pre[index - 1] - pre[nowl - 1];
            f[i] = getmod(pre[i]);
        }
        pre[i] += f[i];
    }
    cout << f[n] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
