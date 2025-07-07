#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1e9 + 7)

using namespace std;

const int N = 1000;
int n, m;
int arr[1003];
int sortarr[1003];
map<int, int> mp;

int multitree[N + 10][N + 10];
int lowbit(int x)
{
    return x & (-x);
}
int update(int x, int val, int nowtree)
{
    for (int i = x; i <= 1000; i += lowbit(i))
    {
        multitree[nowtree][i] += val;
        multitree[nowtree][i] %= MOD;
    }
}
int query(int x, int nowtree)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        sum += multitree[nowtree][i];
        sum %= MOD;
    }
    return sum;
}
void solve(int t)
{
    memset(multitree, 0, sizeof(multitree));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sortarr[i] = arr[i];
    }
    sort(sortarr + 1, sortarr + 1 + n);
    sortarr[0] = INF;
    int base = 1;
    for (int i = 1; i <= n; i++)
    {
        if (sortarr[i] != sortarr[i - 1])
        {
            mp[sortarr[i]] = base;
            base++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int nowval = mp[arr[i]];
        update(nowval, 1, 1);
        for (int j = 2; j <= m; j++)
        {

            int num = query(nowval - 1, j - 1);
            update(nowval, num, j);
        }
    }
    int ans = 0;

    ans = query(n, m);

    cout << "Case #" << t << ": " << ans << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    return 0;
}