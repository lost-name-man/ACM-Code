#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

void solve()
{
    string str;

    int num = 0;
    while (cin >> str)
    {
        cout << "!" << endl;
        cout << str.size() << endl;
        for (int i = 0; i < str.size() - 2; i++)
        {
            if (str[i] == 'G' && str[i + 1] == 'Z' && str[i + 2] == 'U')
            {
                num++;
            }
        }
    }
    // getline(cin, str);

    if (num == 0)
    {

        cout << "yezhulin" << endl;
    }
    else if (num % 2 == 1)
    {

        cout << "heshangpo" << endl;
    }
    else
    {
        cout << "qingrenpo" << endl;
    }
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int T = 1;
    // cin>>T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
