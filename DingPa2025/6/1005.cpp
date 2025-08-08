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
#define int size_t
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 2e9 + 7;
const int MOD = 1e17 + 7;

vector<vector<int>>croods;
int n, m, k;


pair<int, int> wasd[11]={{0, 0}, {-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-2, -1}, {-2, -2}, {-2, 1}, {-2, 2}, {-3, -1}, {-3, 1}};


int check(int x, int y)
{
    if(x<1 || x>n)
    {
        return 0;
    }
    if(y<1 || y>m)
    {
        return 0;
    }
    return 1;
}



struct Node
{
    int first;
    int second;
    int id;


    bool operator <(const Node &other) const
    {
        return this->first < other.first;
    }
};

void solve()
{
    cin>>n>>m>>k;
    croods=vector<vector<int>>(n+5, vector<int>(m+5, 0));
    vector<Node>arr;
    for(int i=1; i<=k; i++)
    {
        int x, y;
        cin>>x>>y;
        arr.push_back({x, y, i});
    }


    sort(arr.begin(), arr.end());
    for(int i=0; i<k; i++)
    {
        int x, y;
        x=arr[i].first, y=arr[i].second;
        // cout<<"!"<<x<<" "<<y<<endl;
        for(int j=0; j<11; j++)
        {
            int nextx=x+wasd[j].first, nexty=y+wasd[j].second;
            if(check(nextx, nexty))
            {
                croods[nextx][nexty]=arr[i].id;
            }
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(croods[i][j]==0)
            {
                cout<<".";
            }
            else
            {
                cout<<croods[i][j];
            }
            
        }
        cout<<endl;
    }
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
