#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

int l, r;
vector<int> lbi, rbi;

void tobi(int x, vector<int> &re)
{
    for (int i = 60; i >= 0; i--)
    {
        re[i] = (x >> i) & 1;
    }
}

int cmp(vector<int> &a, vector<int> &b)
{
    for (int i = 63; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            return 1;
        }
        else if (a[i] < b[i])
        {
            return -1;
        }
    }
    return 0;
}
void solve()
{
    cin >> l >> r;
    lbi = rbi = vector<int>(64);
    tobi(l, lbi);
    tobi(r, rbi);

    vector<int> tmplbi(64);
    vector<int> ansbi(64);

    if (2 >= l && 2 <= r)
    {
        cout << 2 << endl;
        return;
    }
    int ok = 0;
    for (int i = 2; i <= 32; i++)
    {
        ansbi = vector<int>(64);
        tmplbi = vector<int>(64);
        int onenum = i - 1;
        int low = (1 << i);
        int tmpl = l - low;
        tobi(tmpl, tmplbi);

        int all0 = 1;
        for (int j = 0; j <= i; j++)
        {
            if (tmplbi[j] == 1)
            {
                all0 = 0;
            }
        }
        for (int j = 60; j > i; j--)
        {
            if (tmplbi[j] == 1)
            {
                if (onenum > 0)
                {
                    ansbi[j] = 1;
                }
                onenum--;
            }
        }
        if (onenum < 0)
        {
            int chal;
            for (int j = 0; j <= 60; j++)
            {
                if (ansbi[j] == 1 && ansbi[j + 1] == 0) // 1 to rear
                {
                    swap(ansbi[j], ansbi[j + 1]);
                    chal = j + 1;
                    break;
                }
            }
            int einnum = 0;
            for (int j = i + 1; j <= chal - 1; j++)
            {
                if (ansbi[j] == 1)
                {
                    einnum++;
                    ansbi[j] == 0;
                }
            }

            for (int j = i + 1; j <= chal - 1; j++)
            {
                if (einnum == 0)
                {
                    break;
                }
                if (ansbi[j] == 0)
                {
                    ansbi[j] = 1;
                    einnum--;
                }
            }
        }
        else if (onenum > 0)
        {
            for (int j = i + 1; j <= 63; j++)
            {
                if (ansbi[j] == 0)
                {
                    ansbi[j] = 1;
                    onenum--;
                }
                if (onenum == 0)
                {
                    break;
                }
            }
        }
        else
        {
            if (all0 != 1)
            {

                //
                int chal;
                for (int j = 0; j <= 60; j++)
                {
                    if (ansbi[j] == 1 && ansbi[j + 1] == 0) // 1 to rear
                    {
                        swap(ansbi[j], ansbi[j + 1]);
                        chal = j + 1;
                        break;
                    }
                }
                int einnum = 0;
                for (int j = i + 1; j <= chal - 1; j++)
                {
                    if (ansbi[j] == 1)
                    {
                        einnum++;
                        ansbi[j] == 0;
                    }
                }

                for (int j = i + 1; j <= chal - 1; j++)
                {
                    if (einnum == 0)
                    {
                        break;
                    }
                    if (ansbi[j] == 0)
                    {
                        ansbi[j] = 1;
                        einnum--;
                    }
                }
            }
        }

        ansbi[i] = 1;
        int check = cmp(ansbi, rbi);
        if (check == 0 || check == -1)
        {
            ok = 1;
            break;
        }
    }

    if (ok == 0)
    {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i <= 63; i++)
    {
        ans += ansbi[i] * (1 << i);
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
