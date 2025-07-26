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
const int INF = 2e9 + 7;

struct Inval
{
    int l;
    int r;

    bool operator<(const Inval &other) const
    {
        if (this->r == other.r)
        {
            return this->l < other.l;
        }
        return this->r < other.r;
    }
};

set<pair<int, size_t>> allnum;
map<int, int> id_num;
map<int, int> num_id;

void solve()
{
    int n;
    cin >> n;
    allnum = set<pair<int, size_t>>();
    id_num = map<int, int>();
    num_id = map<int, int>();
    if (n == 0)
    {
        cout << 1 << endl;
        return;
    }
    vector<Inval> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        size_t tmp=rnd();
        cin >> arr[i].l >> arr[i].r;
        allnum.insert({arr[i].l, tmp});
        allnum.insert({arr[i].r+1, tmp});
    }

    int cnt = 0;
    map<int, size_t>index_xor;
    for(auto iter=allnum.begin(); iter!=allnum.end(); iter++)
    {
        int index=iter->first;
        size_t xxoo=iter->second;
        index_xor[index]^=xxoo;
    }


    set<size_t>ans;
    ans.insert(0);
    int nowxxoo=0;
    for(auto iter=index_xor.begin(); iter!=index_xor.end(); iter++)
    {
        int nowxor=iter->second;
        nowxxoo^=nowxor;
        ans.insert(nowxxoo);
    }

    cout<<ans.size()<<endl;



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
