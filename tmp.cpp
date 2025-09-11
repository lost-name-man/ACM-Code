#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 998244353;

int k, x, y;

vector<int> base;
int findfa(int x)
{
    int nowx = x;
    int nownum = 1;
    int nowp = 0;
    int cx = x - 1;

    nownum = *(lower_bound(base.begin(), base.end(), x) - 1);

    int less = nowx - nownum;
    int tmpfa = (less - 1) / k + 1;

    return tmpfa;
}

int check_bang(int x, int y)
{
    double vib = INF * 1.0 / y;
    if (x <= vib)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

vector<int> fax;
vector<int> fay;
void solve()
{
    cin >> k >> x >> y;

    fax.clear();
    fay.clear();
    base.clear();
    int basenum = 1;
    while (basenum * (k + 1) <= 1e18 && basenum * (k + 1) > 0)
    {
        base.push_back(basenum);
        basenum *= (k + 1);
    }

    fax.push_back(x);
    fay.push_back(y);

    int nowx = x;
    while (nowx != 1)
    {
        int tmpfa = findfa(nowx);
        fax.push_back(tmpfa);
        nowx = tmpfa;
    }

    int nowy = y;
    while (nowy != 1) // 64
    {
        int tmpfa = findfa(nowy); // 64
        fay.push_back(tmpfa);
        nowy = tmpfa;
    }

    reverse(fax.begin(), fax.end());
    reverse(fay.begin(), fay.end());

    int it = fax[min(fax.size(), fay.size()) - 1];

    for (int i = 0; i < min(fax.size(), fay.size()); i++) // 64
    {

        if (fax[i] != fay[i])
        {
            it = fax[i - 1];
            break;
        }
    }
    cout << it << endl;
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
