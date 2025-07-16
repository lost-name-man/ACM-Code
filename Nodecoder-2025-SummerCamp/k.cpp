#include <bits/stdc++.h>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;
const int N = 200000;

int n;

int vis[N + 10][3];
vector<vector<int>> tree;
int doornum[N + 10];
int deep[N + 10][3];
int usedr[N + 10][3];
map<pair<int, int>, int> visver;
void dfs(int nowroom, int nowdoor)
{
    int nextroom = tree[nowroom][nowdoor];
    int nextdoor = (nowdoor + 1) % doornum[nextroom];
    pair<int, int> road = {nowroom, nextroom};
    if (road.first > road.second)
    {
        swap(road.first, road.second);
    }
    if (visver[road] == 1)
    {
        usedr[nowroom][nowdoor]++;
    }
    visver[road] = 1;

    if (vis[nextroom][nextdoor] == 1)
    {
        if (deep[nextroom][nextdoor] == 0)
        {
            deep[nowroom][nowdoor] = 1;
            return;
        }
        else
        {
            deep[nowroom][nowdoor] = deep[nextroom][nextdoor] + 1;
        }
    }
    else
    {
    }
}
void solve()
{

    cin >> n;
    tree = vector<vector<int>>(n + 10);
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        doornum[i] = num;
        for (int j = 0; j < num; j++)
        {
            int nextroom;
            cin >> nextroom;
            tree[i].push_back(nextroom);
        }
    }

    for (int i = 1; i <= n; i++)
    {
    }
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