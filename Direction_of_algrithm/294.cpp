#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

string s1, s2;
int n1, n2;

int f[102][31];

bool check()
{
    int len1 = s1.size(), len2 = s2.size();
    vector<int> letters(26, 0);
    for (int i = 0; i < len1; i++)
    {
        letters[s1[i] - 'a']++;
    }
    int ok = 1;
    for (int i = 0; i < len2; i++)
    {
        if (letters[s2[i] - 'a'] == 0)
        {
            ok = 0;
            break;
        }
    }
    return ok;
}

void init_f0()
{
    int len1 = s1.size(), len2 = s2.size();

    for (int i = 0; i < len1; i++)
    {
        int s2index = 0;
        for (int j = 0;; j++)
        {
            int s1index = (i + j) % len1;
            if (s2[s2index] == s1[s1index])
            {
                s2index++;
            }
            if (s2index == len2)
            {
                f[i][0] = j + 1;
                break;
            }
        }
    }
}
void solve()
{
    while (cin >> s2 >> n2 >> s1 >> n1)
    {
        memset(f, 0, sizeof(f));
        int len1 = s1.size(), len2 = s2.size();
        if (check() == 0)
        {
            cout << 0 << endl;
            continue;
        }
        init_f0();

        for (int j = 1; j < 30; j++)
        {
            for (int i = 0; i < len1; i++)
            {
                int nows1index = i, nexts1index = (i + f[i][j - 1]) % len1;
                f[i][j] = f[i][j - 1] + f[nexts1index][j - 1];
            }
        }
        int sumlen = 0;
        int s1index = 0;
        int maxs2 = 0;
        for (int i = 29; i >= 0; i--)
        {
            if (sumlen + f[s1index][i] <= n1 * len1)
            {
                maxs2 += pow(2, i);
                sumlen = sumlen + f[s1index][i];
                s1index = (s1index + f[s1index][i]) % len1;
            }
        }
        cout << maxs2 / n2 << endl;
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