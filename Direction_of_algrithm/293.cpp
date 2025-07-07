#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

int n, m;
int x0;
int h[100005];
int ga[100005], gb[100005];
int f[20][100005][2];
int da[20][100005][2], db[20][100005][2];

void init_g()
{
    set<pair<int, int>> st;
    st.insert({1e12, 0});
    st.insert({(1e12 + 1), 0});
    st.insert({-1e12, 0});
    st.insert({(-1e12 - 1), 0});

    for (int i = n; i >= 1; i--)
    {
        auto nowit = st.lower_bound({h[i], i});
        nowit--;
        nowit--;
        int d1 = INF, d2 = INF, p1 = 0, p2 = 0;
        for (int j = 1; j <= 4; j++)
        {
            int nowh = nowit->first, nowp = nowit->second;
            int nowd = abs(h[i] - nowh);
            if (nowd < d1)
            {
                d2 = d1, d1 = nowd;
                p2 = p1, p1 = nowp;
            }
            else if (nowd < d2)
            {
                d2 = nowd;
                p2 = nowp;
            }
            nowit++;
        }
        st.insert({h[i], i});
        ga[i] = p2;
        gb[i] = p1;
    }
}
void init_f()
{
    for (int i = 1; i <= n; i++)
    {
        f[0][i][0] = ga[i];
        f[0][i][1] = gb[i];
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                f[i][j][0] = f[i - 1][f[i - 1][j][0]][1];
                f[i][j][1] = f[i - 1][f[i - 1][j][1]][0];
            }
            else
            {
                f[i][j][0] = f[i - 1][f[i - 1][j][0]][0];
                f[i][j][1] = f[i - 1][f[i - 1][j][1]][1];
            }
        }
    }
}

void init_dp()
{
    for (int i = 1; i <= n; i++)
    {
        da[0][i][0] = abs(h[ga[i]] - h[i]);
        da[0][i][1] = 0;
        db[0][i][0] = 0;
        db[0][i][1] = abs(h[gb[i]] - h[i]);
    }
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1)
            {
                da[i][j][0] = da[i - 1][j][0] + da[i - 1][f[i - 1][j][0]][1];
                da[i][j][1] = da[i - 1][j][1] + da[i - 1][f[i - 1][j][1]][0];
                db[i][j][0] = db[i - 1][j][0] + db[i - 1][f[i - 1][j][0]][1];
                db[i][j][1] = db[i - 1][j][1] + db[i - 1][f[i - 1][j][1]][0];
            }
            else
            {
                da[i][j][0] = da[i - 1][j][0] + da[i - 1][f[i - 1][j][0]][0];
                da[i][j][1] = da[i - 1][j][1] + da[i - 1][f[i - 1][j][1]][1];
                db[i][j][0] = db[i - 1][j][0] + db[i - 1][f[i - 1][j][0]][0];
                db[i][j][1] = db[i - 1][j][1] + db[i - 1][f[i - 1][j][1]][1];
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    init_g();
    init_f();
    init_dp();
    cin >> x0;

    double achub = INF;
    int h1 = -INF, ans1;
    for (int i = 1; i <= n; i++)
    {
        int nowindex = i;
        int sumd = 0, suma = 0, sumb = 0;
        for (int j = 19; j >= 0; j--)
        {
            if (f[j][nowindex][0] == 0)
            {
                continue;
            }
            if (sumd + da[j][nowindex][0] + db[j][nowindex][0] <= x0)
            {
                suma += da[j][nowindex][0];
                sumb += db[j][nowindex][0];
                sumd = suma + sumb;
                nowindex = f[j][nowindex][0];
            }
        }
        double nowachub;
        int nowh1;
        if (sumb == 0)
        {
            nowachub = INF;
        }
        else
        {
            nowachub = suma * 1.0 / sumb * 1.0;
        }
        if (nowachub < achub || (nowachub == achub && h[i] > h1))
        {
            achub = nowachub;
            h1 = h[i];
            ans1 = i;
        }
    }
    cout << ans1 << endl;

    cin >> m;
    for (int i = 1; i <= m; i++)
    {

        int x, s;
        cin >> x >> s;
        int nowindex = x;
        int sumd = 0, suma = 0, sumb = 0;
        for (int j = 19; j >= 0; j--)
        {
            if (f[j][nowindex][0] == 0)
            {
                continue;
            }
            if (sumd + da[j][nowindex][0] + db[j][nowindex][0] <= s)
            {
                suma += da[j][nowindex][0];
                sumb += db[j][nowindex][0];
                sumd = suma + sumb;
                nowindex = f[j][nowindex][0];
            }
        }
        cout << suma << ' ' << sumb << endl;
    }
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