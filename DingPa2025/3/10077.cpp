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

set<int> allnum;
map<int, int> id_num;
map<int, int> num_id;

void solve()
{
    int n;
    cin >> n;
    allnum = set<int>();
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
        cin >> arr[i].l >> arr[i].r;
        allnum.insert(arr[i].l);
        allnum.insert(arr[i].r);
    }

    int cnt = 0;
    for (auto it = allnum.begin(); it != allnum.end(); it++)
    {
        cnt++;
        id_num[cnt] = *it;
        num_id[*it] = cnt;
    }

    vector<int> line(cnt + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        size_t nowx = rnd();
        int nowl = num_id[arr[i].l];
        int nowr = num_id[arr[i].r];
        line[nowl] ^= nowx;
        line[nowr + 1] ^= nowx;
    }

    vector<size_t> s;
    size_t nowc = 0;
    // s.push_back(0);
    int ans = 0;
    for (int i = 1; i <= cnt + 1; i++)
    {
        nowc ^= line[i];
        s.push_back(nowc);
    }
    sort(s.begin(), s.end());
    ans = std::unique(s.begin(), s.end()) - s.begin();
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
