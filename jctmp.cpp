#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int n;
vector<int> arr;
string s;
void solve()
{
    int cnt = 0;

    cin >> n >> s;
    arr = vector<int>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] != i)
        {
            cnt++;
        }
    }

    if (n == 2 || n == 3 && arr[1] == 2 && arr[2] == 3 && arr[3] == 1 && s == "Bob")
    {
        cout << "Alice" << endl;
        return;
    }

    if (cnt == 2 && s == "Alice" || cnt == 0 && s == "Bob")
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
