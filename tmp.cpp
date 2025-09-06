#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18;
const int MOD = 1e9 + 7;

int n;
map<string, map<char, int>> mp;
int prob[27];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string team, type;
        char c;
        cin >> team >> c >> type;
        if (mp[team][c] == 0 && type[0] == 'a')
        {
            mp[team][c] = 1;
            prob[c - 'A']++;
        }
    }
    int maxn = 0;
    char ans;
    for (int i = 0; i < 26; i++)
    {
        if (prob[i] > maxn)
        {
            maxn = prob[i];
            ans = i + 'A';
        }
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
