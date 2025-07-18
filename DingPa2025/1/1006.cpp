#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;

struct Node
{
    int x;
    int y;
};

int n, m;
int arr[102][102];
set<int> exnode;
map<int, Node> h_node;
map<Node, int> vis;

Node steps[4] = {{0, 1}, {1, 0}, {0, 1}, {0, -1}};

int check(Node node)
{
    if (node.x < 1 || node.x > n || node.y < 1 || node.y > m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int checkh(Node node1, Node node2)
{
    if (arr[node1.x][node1.y] < arr[node2.x][node2.y])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void myerase(Node node)
{
    auto it = exnode.find(arr[node.x][node.y]);
    exnode.erase(it);
}
void bfs(Node stnode)
{
    queue<Node> q;
    q.push(stnode);
    vis[stnode] = 1;

    myerase(stnode);

    while (!q.empty())
    {
        Node nownode = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Node nextnode = {nownode.x + steps[i].x, nownode.y + steps[i].y};
            if (check(nextnode) == 0 || vis[nextnode] == 1 || checkh(nownode, nextnode))
            {
                continue;
            }
            q.push(nextnode);
            vis[nextnode] = 1;
            myerase(nextnode);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            exnode.insert(arr[i][j]);
            h_node[arr[i][j]] = {i, j};
        }
    }

    bfs({1, 1});
    vector<int> tranfunc;
    while (exnode.size())
    {
        int nowh = *exnode.rbegin();
        Node nownode = h_node[nowh];
        tranfunc.push_back(nowh);
        bfs(nownode);
    }
    sort(tranfunc.begin(), tranfunc.end());
    int ans = 0;

    for (int i = 0; i < tranfunc.size() - 1; i++)
    {
        Node nownode = h_node[tranfunc[i]], nextnode = h_node[tranfunc[i + 1]];
        int nowh = tranfunc[i], nexth = tranfunc[i + 1];
        ans += 114 * (abs(nownode.x - nextnode.x)) + 5141 * (abs(nownode.y - nextnode.y)) + 919810 * (abs(nowh - nexth));
    }
    ans += ((int)1 << 34) * tranfunc.size();
    cout << ans << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}