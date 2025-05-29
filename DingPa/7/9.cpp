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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;


struct Edge
{
    int id;
    vector<int>vertex;
    int w;

    const bool operator <(const Edge& other)const
    {
        return this->w > other.w;
    }

};
vector<Edge>edge;

struct Node
{

    int id = 0;
    int fa = 0;
    int edge = 0;
    int vertex = 1;
};

vector<Node>node;

int findfa(int nownode)
{
    while (node[nownode].fa != nownode)
    {
        int nextnode = node[nownode].fa;
        node[nownode].fa = nextnode;
        nownode = nextnode;
    }

    return nownode;
}

int mergefa(int a, int b)
{
    int faa = findfa(a);
    int fab = findfa(b);

    if (faa > fab)
    {
        swap(faa, fab);
    }


    node[faa].edge += node[fab].edge + 1;
    node[faa].vertex += node[fab].vertex;

    node[fab].fa = faa;
    node[fab].edge = 0;
    node[fab].vertex = 0;


    return faa;
}


void solve()
{

    int n, m;
    cin >> n >> m;
    node = vector<Node>(n+5);
    edge = vector<Edge>(m + 5);


    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].vertex.push_back((a));
        edge[i].vertex.push_back((b));
        edge[i].id = i;
        edge[i].w = c;

        if (node[a].id == 0)
        {
            node[a].fa = a;
            node[a].id = a;
            node[a].vertex = 1;
        }
        if (node[b].id == 0)
        {
            node[b].fa = b;
            node[b].id = b;
            node[b].vertex = 1;
        }
    }


    sort(edge.begin() + 1, edge.begin() + 1 + m);



    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int a = edge[i].vertex[0];
        int b = edge[i].vertex[1];
        int noww = edge[i].w;

        int faa = findfa(a), fab = findfa(b);
        if (faa == fab)
        {

            if (node[faa].vertex > node[faa].edge)
            {
                node[faa].edge++;
                ans += noww;
            }
        }
        else
        {
            if (node[faa].vertex + node[fab].vertex > node[faa].edge + node[fab].edge)
            {
                int newfa = mergefa(faa, fab);
                ans += noww;
            }


        }



    }

    cout << ans << endl;


}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}