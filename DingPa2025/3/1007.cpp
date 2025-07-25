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

void solve()
{
    int n;
    cin >> n;
    vector<Inval> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].l >> arr[i].r;
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n);

    map<int, int> mp;
    set<int> st;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int nowl = arr[i].l, nowr = arr[i].r;
        if (nowl == arr[i - 1].l && nowr == arr[i - 1].r)
        {
            continue;
        }
        int okl = 0;
        if (mp[nowr] == 0)
        {
            okl = 1;
            ans++;
        }
        auto it = st.lower_bound(nowl);
        int nextl;
        if (it == st.end())
        {
            mp[nowl] = 1;
            if (mp[nowr] != 1)
            {
                mp[nowr] = 2;
            }
            st.insert(nowl);
            st.insert(nowr);

            continue;
        }
        else
        {
            nextl = *it;
            if (okl == 0)
            {
                ans++;
            }
            else if (mp[nextl] == 2)
            {
                ans++;
            }
        }
        mp[nowl] = 1;
        if (mp[nowr] != 1)
        {
            mp[nowr] = 2;
        }
        st.insert(nowl);
        st.insert(nowr);
    }
    ans++;
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
