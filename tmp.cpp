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

struct Node
{
    int id;
    int val;
    int lnode = 0, rnode = 0;
};

int n, k;
vector<int> arr;
vector<Node> tree;

int okdivi;
int nowx;
int root = 0;
int dfs(int nownode)
{
    int nowgcd = arr[nownode] + nowx;
    int lgcd = 0, rgcd = 0;
    if (tree[nownode].lnode != 0)
    {
        lgcd = dfs(tree[nownode].lnode);
    }
    if (tree[nownode].rnode != 0)
    {
        rgcd = dfs(tree[nownode].rnode);
    }

    nowgcd = __gcd(__gcd(lgcd, rgcd), nowgcd);
    if (nowgcd % (arr[nownode] + nowx) != 0)
    {
        okdivi = 0;
    }
    return nowgcd;
}
int checkans(int x)
{
    okdivi = 1;
    nowx = x;
    dfs(root);
    return okdivi;
}
void solve()
{
    cin >> n;
    cin >> k;
    arr = vector<int>(n + 5);
    tree = vector<Node>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << k << ' ' << k * (k + 1) / 2 << endl;
        return;
    }
    stack<int> st;

    for (int i = 1; i <= n; i++)
    {
        int lastp = 0;
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            lastp = st.top();
            st.pop();
        }

        if (lastp)
        {
            tree[i].lnode = lastp;
        }
        if (!st.empty())
        {
            tree[st.top()].rnode = i;
        }
        else
        {
            root = i;
        }
        st.push(i);
    }

    int maxans = abs(arr[2] - arr[1]);
    for (int i = 1; i < n; i++)
    {
        maxans = __gcd(maxans, abs(arr[i + 1] - arr[i]));
    }

    if (maxans == 0)
    {
        cout << k << ' ' << k * (k + 1) / 2 << endl;
        return;
    }
    vector<int> posi_divi;
    for (int i = 1; i * i <= maxans; i++)
    {
        if (maxans % i == 0)
        {
            if (i - arr[root] >= 1 && i - arr[root] <= k)
            {
                posi_divi.push_back(i);
            }
            if (maxans / i != i)
            {
                if (maxans / i - arr[root] >= 1 && maxans / i - arr[root] <= k)
                {
                    posi_divi.push_back(maxans / i);
                }
            }
        }
    }

    int ans = 0;
    int num = 0;
    for (int i = 0; i < posi_divi.size(); i++)
    {
        int nowdivi = posi_divi[i];
        int nowx = nowdivi - arr[root];
        int ok = checkans(nowx);

        if (ok == 1)
        {
            num++;
            ans += nowx;
        }
    }
    cout << num << ' ' << ans << endl;
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
