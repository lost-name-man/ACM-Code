#include <climits>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
#define int long long
#define endl '\n'
const long long INF = 1e18 + 7;

int lowbit(int x)
{
    return x & (-x);
}
vector<int> trees;
vector<int> arr;
int n;
int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        res += trees[i];
    }
    return res;
}

int querys(int l, int r)
{
    int res = 0;
    res = sum(r) - sum(l - 1);
    return res;
}
void add(int x, int y)
{
    for (int i = x; i <= n; i += lowbit(i))
    {
        trees[i] += y;
    }
}


void solve()
{

    cin >> n;

    arr = vector<int>(n + 5, 0);
    trees = vector<int>(n * 4 + 5, 0);

    vector<int>reflct(n + 5, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        reflct[arr[i]] = i;

    }

    int l_lim = 1, r_lim = n;

    int ans = 1;
    for (int nowval = 1; nowval < n; nowval++)
    {
        while (querys(l_lim, l_lim) == 1)
        {
            l_lim++;
        }
        while (querys(r_lim, r_lim) == 1)
        {
            r_lim--;
        }


        int nowindex = reflct[nowval];
        int tmpans1 = querys(l_lim, nowindex)+2;
        int tmpans2 = querys(nowindex, r_lim)+2;
        ans = max({ ans, tmpans1, tmpans2 });
        add(nowindex, 1);
    }



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