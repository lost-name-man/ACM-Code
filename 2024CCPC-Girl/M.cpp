#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int n;
vector<int> fa, isleaf, vis, deep;

void solve()
{
    cin >> n;
    fa = vis = deep = vector<int>(n + 5, 0);
    isleaf = vector<int>(n + 5, 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        isleaf[fa[i]] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    deep[1] = 1;
    vector<int> node;
    for (int i = 1; i <= n; i++)
    {
        if (isleaf[i] == 1)
        {
            node = vector<int>();
            int nownode = i;
            int nowdeep = 1;
            while (deep[nownode] == 0)
            {
                node.push_back(nownode);
                nowdeep++;
                nownode = fa[nownode];
            }
            for (int j = 0; j < node.size(); j++)
            {
                deep[node[j]] = nowdeep + deep[nownode] - (1 + j);
            }
            pq.push({deep[i], i});
        }
    }

    int ans = 0;
    while (!pq.empty())
    {
        int nownode = pq.top().second;
        int nowans = 0;
        while (vis[nownode] == 0 && nownode != 1)
        {
            nowans++;
            vis[nownode] = 1;
            nownode = fa[nownode];
        }
        vis[nownode] = 1;
        ans = max(ans, nowans);
        pq.pop();
    }
    cout << ans << endl;
}
signed main()
{
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}