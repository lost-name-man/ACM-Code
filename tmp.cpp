#include <bits/stdc++.h>

#define int long long
#define INF ((long long)1e18)
#define endl '\n'
#define MOD 998244353

using namespace std;

const int N = 1000000;

int n, m;

struct hf
{
    int x;
    int y;
    int hx;
    int hy;
};
struct Node
{
    int x;
    int y;
    vector<hf> attack;
};

vector<Node> horse;
pair<int, int> croodh[11];
hf steps[8] = {{-2, 1, -1, 0}, {-1, 2, 0, 1}, {1, 2, 0, 1}, {2, 1, 1, 0}, {2, -1, 1, 0}, {1, -2, 0, -1}, {-1, -2, 0, -1}, {-2, -1, -1, 0}};
int dp[102][102][1500] = {0};
map<pair<int, int>, int> exhorse;
bool isout(int x, int y)
{
    if (x < 0 || x > n || y < 0 || y > n)
    {
        return 1;
    }
    return 0;
}

bool safes(int x, int y, int st)
{

    //!!!!!!!!!!
    if (x == 2 && y == 2 && st == 25)
    {
        // cout<<"!"<<endl;
    }

    int ok = 1;
    for (int i = 0; i < m; i++)
    {
        if (((st >> i) & 1) == 0)
        {
            int nowhorse = i + 1;
            for (int j = 0; j < horse[nowhorse].attack.size(); j++)
            {
                int hx = horse[nowhorse].attack[j].hx, hy = horse[nowhorse].attack[j].hy;
                int fid = exhorse[{hx, hy}] - 1;
                if (fid == -1)
                {
                    if (horse[nowhorse].attack[j].x == x && horse[nowhorse].attack[j].y == y)
                    {
                        ok = 0;
                        break;
                    }
                }
                else
                {
                    int exf = ((st >> (fid)) & 1);
                    if (exf == 1)
                    {
                        if (horse[nowhorse].attack[j].x == x && horse[nowhorse].attack[j].y == y)
                        {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
        }
        if (ok == 0)
        {
            break;
        }
    }
    return ok;
}

int dang[102][102][1500] = {0};
void solve()
{

    cin >> n >> m;

    horse = vector<Node>(m + 5);
    int ok = 1;
    for (int i = 1; i <= m; i++)
    {

        cin >> croodh[i].first >> croodh[i].second;
        horse[i].x = croodh[i].first;
        horse[i].y = croodh[i].second;
        exhorse[{croodh[i].first, croodh[i].second}] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        x = croodh[i].first;
        y = croodh[i].second;

        for (int j = 0; j < 8; j++)
        {
            int hx = x + steps[j].hx, hy = y + steps[j].hy;
            if (isout(x + steps[j].x, y + steps[j].y) == 0)
            {
                horse[i].attack.push_back({x + steps[j].x, y + steps[j].y, hx, hy});
                if ((x + steps[j].x == 0 && y + steps[j].y == 0) && (exhorse[{hx, hy}] == 0))
                {
                    ok = 0;
                }
            }
        }
    }
    if (ok == 0)
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 0; i < (1 << m); i++)
    {
        int st = i;
        for (int i = 0; i < m; i++)
        {
            if (((st >> i) & 1) == 0)
            {
                int nowhorse = i + 1;
                for (int j = 0; j < horse[nowhorse].attack.size(); j++)
                {
                    int hx = horse[nowhorse].attack[j].hx, hy = horse[nowhorse].attack[j].hy;
                    int fid = exhorse[{hx, hy}] - 1;
                    if (fid == -1)
                    {
                        dang[horse[nowhorse].attack[j].x][horse[nowhorse].attack[j].y][st] = 1;
                    }
                    else
                    {
                        int exf = ((st >> (fid)) & 1);
                        if (exf == 1)
                        {
                            dang[horse[nowhorse].attack[j].x][horse[nowhorse].attack[j].y][st] = 1;
                        }
                    }
                }
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            for (int st = 0; st < (1 << m); st++)
            {
                int hid = exhorse[{i, j}] - 1;
                if (dang[i][j][st] == 0)
                {
                    if (hid != -1)
                    {
                        if (i != 0)
                        {
                            dp[i][j][st | (1ll << hid)] += dp[i - 1][j][st];
                            dp[i][j][st | (1ll << hid)] %= MOD;
                        }
                        if (j != 0)
                        {
                            dp[i][j][st | (1ll << hid)] += dp[i][j - 1][st];
                            dp[i][j][st | (1ll << hid)] %= MOD;
                        }
                    }
                    else
                    {
                        if (i != 0)
                        {
                            dp[i][j][st] += dp[i - 1][j][st];
                            dp[i][j][st] %= MOD;
                        }
                        if (j != 0)
                        {
                            dp[i][j][st] += dp[i][j - 1][st];
                            dp[i][j][st] %= MOD;
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int st = 0; st < (1ll << m); st++)
    {
        ans += dp[n][n][st];
        ans %= MOD;
    }
    cout << ans << endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin>>T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}

/*

3 4
0 3
1 1
1 2
2 2


3 5
0 3
1 1
1 2
1 3
2 2

10 8
0 3
1 3
2 3
3 3
4 3
5 3
6 3
7 3

*/
