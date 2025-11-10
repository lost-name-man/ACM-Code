#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int n, k, m;
map<int, map<int, int>> pval;
vector<int> isf;
vector<pair<int, int>> val;

struct Node
{
    int a;
    int b;
    int val;
    const bool operator<(const Node &others) const
    {
        return this->val > others.val;
    }
};
void solve()
{
    cin >> n >> m >> k;
    isf = vector<int>(k + 5);
    val = vector<pair<int, int>>(k + 5);
    pval = map<int, map<int, int>>();

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        val[i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        isf[tmp] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            if (isf[a] == 1)
            {
                ans++;
            }
            else
            {
                val[a].first++;
            }
            continue;
        }
        if (a > b)
        {
            swap(a, b);
        }
        if (isf[a] == 1 && isf[b] == 1)
        {
            ans++;
        }
        else if (isf[a] == 1)
        {
            val[b].first++;
        }
        else if (isf[b] == 1)
        {
            val[a].first++;
        }
        else
        {
            pval[a][b]++;
        }
    }

    vector<Node> st;
    for (auto it1 = pval.begin(); it1 != pval.end(); it1++)
    {
        for (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
        {
            it2->second += val[it1->first].first + val[it2->first].first;
            st.push_back({it1->first, it2->first, it2->second});
        }
    }

    sort(st.begin(), st.end());
    sort(val.begin() + 1, val.begin() + 1 + k, greater<pair<int, int>>());
    int add = 0;
    if (!st.empty())
    {
        add = st.begin()->val;
    }

    if (k - n == 1)
    {
        add = max(add, val[1].first);
    }
    else
    {
        int a = min(val[1].second, val[2].second), b = max(val[1].second, val[2].second);
        add = max(add, val[1].first + val[2].first);
    }
    ans += add;
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
