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
const int INF = 1e16 + 7;
const int MOD = 998244353;

struct Node
{

    int id;
    int a;
    int b;

    bool operator < (const Node &other)
    {
        return this->a<other.a;
    }
};

void solve()
{
    int n;
    cin>>n;
    vector<Node>node(n+5);
    for(int i=1; i<=n; i++)
    {
        node[i].id=i;
        cin>>node[i].a;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>node[i].b;
    }



    sort(node.begin()+1, node.begin()+1+n);

    vector<int>deltaa(n+5, 0);
    vector<int>deltab(n+5, 0);
    for(int i=1; i<=n; i++)
    {
        deltaa[i]=node[i].a+node[i].b;
        deltab[i]=node[i].a-node[i].b;
    }


    sort(deltaa.begin()+1, deltaa.begin()+1+n);
    sort(deltab.begin()+1, deltab.begin()+1+n);

    int delta=INF;

    for(int i=2; i<=n; i++)
    {
        delta=min(delta, deltaa[i]-deltaa[i-1]);
        delta=min(delta, deltab[i]-deltab[i-1]);
    }


    cout<<delta<<endl;




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
