#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int n, m;
int arr[100005];
multiset<int> st;
int dq[100005];
int ll = 0, rr = -1;

int f[100005];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] > m)
        {
            cout << -1 << endl;
        }
    }
    int lindex = 1, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += arr[i];
        while (sum > m)
        {
            sum -= arr[lindex++];
            while (ll <= rr && dq[ll] < lindex)
            {
                if (ll < rr)
                {
                    auto it = st.find(f[dq[ll]] + arr[dq[ll + 1]]);
                    st.erase(it);
                }
                ll++;
            }
        }

        while (ll <= rr && arr[dq[rr]] <= arr[i])
        {
            if (ll < rr)
            {
                auto it = st.find(f[dq[rr - 1]] + arr[dq[rr]]);
                st.erase(it);
            }
            rr--;
        }

        if (ll <= rr)
        {
            st.insert(f[dq[rr]] + arr[i]);
        }
        dq[++rr] = i;

        f[i] = f[lindex - 1] + arr[dq[ll]];
        if (!st.empty())
        {
            f[i] = min(f[i], *st.begin());
        }
    }
    cout << f[n] << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}