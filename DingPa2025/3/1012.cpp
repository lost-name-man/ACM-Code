#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;

struct Node
{
    int id;
    int x;
    int y;
    int a;
};
vector<Node>arr;
int n;

void solve()
{
    
    cin>>n;
    arr=vector<Node>(n+5);

    for(int i=1; i<=n; i++)
    {
        
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
