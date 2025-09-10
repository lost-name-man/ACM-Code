#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 1e9 + 7;

struct Edge
{
    int id;
    int w;
    int from;
    int to;
    int next;
};
vector<Edge> edge;
vector<int> head;
int ctot;
void addedge(int x, int y, int w)
{
    ctot++;
    edge[ctot].from = x;
    edge[ctot].to = y;
    edge[ctot].w = w;
    edge[ctot].next = head[x];
    head[x] = ctot;
}

vector<int> fa;

int findfa(int x)
{
    if (fa[x] == x)
    {
        return x;
    }

    int xfa = fa[x];
    fa[x] = findfa(xfa);

    return fa[x];
}

int addfa(int x, int y)
{
    int fafa = findfa(x);
    int sonfa = findfa(y);
    if (fafa > sonfa)
    {
        swap(fafa, sonfa);
    }

    fa[sonfa] = fafa;

    return 1;
}

void solve()
{

    int n, m;
    cin >> n >> m;
    fa = vector<int>(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }

    vector<int> edg(m + 5, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edg[i]=u;
        addfa(u, v);
    }

    map<int, int> size_num;

    vector<int> comp_edgenum(n+5, 0);
    vector<int> fa_sonnum(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        int nowfa = findfa(i);
        fa_sonnum[nowfa]++;      
    }
    for(int i=1; i<=m; i++)
    {
        int nowedg = edg[i];
        int faedg=findfa(nowedg);
        // cout<<"#"<<faedg<<endl; 
        comp_edgenum[faedg]++;
    }

    // for(int i=1; i<=n; i++)
    // {
    //     cout<<fa[i]<<endl;
    // }

    int ans = INF;

    for (int i = 1; i <= n; i++)
    {
        if (fa_sonnum[i] != 0)
        {
            size_num[fa_sonnum[i]]++;

            int nodenum = fa_sonnum[i];
            int edgenum = comp_edgenum[i];
            int shouldedge = (nodenum * (nodenum - 1)) / 2;
            int delta = shouldedge - edgenum;

            // cout<<"@"<<nodenum<<" "<<edgenum<<endl;

            if (delta > 0)
            {

                ans = min(ans, delta);
            }
        }
    }

    if (ans == INF)
    {
        // cout<<"!"<<endl;
        vector<int> zwei_machten;
        for (auto iter = size_num.begin(); iter != size_num.end(); iter++)
        {
            while (zwei_machten.size() < 2 && iter->second > 0)
            {
                zwei_machten.push_back(iter->first);
                iter->second--;
            }
        }

        ans = zwei_machten[0] * zwei_machten[1];
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
