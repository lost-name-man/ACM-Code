#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

struct Node
{
    int l;
    int r;
    int val;
    const bool operator<(const Node &a) const
    {
        return this->l < a.l;
    }
};
int n, q;

void solve()
{
    vector<int> arr, pre0, pre1;
    cin >> n >> q;
    arr = vector<int>(n + 5);
    pre0 = vector<int>(n + 5);
    string str;
    cin >> str;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = str[i - 1] - '0';
        pre0[i] = pre0[i - 1] + (arr[i] == 0);
    }

    vector<Node> block1;
    block1.push_back({0, 0, 0});
    pre1.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            int l = i, r = n;
            for (int j = i; j <= n; j++)
            {
                if (arr[j] == 0)
                {
                    r = j - 1;
                    break;
                }
            }
            int len = r - l + 1;
            int nowval;
            if (len & 1)
            {
                nowval = len / 2 + 2;
            }
            else
            {
                nowval = len / 2;
            }

            block1.push_back({l, r, nowval});
            pre1.push_back(pre1[pre1.size() - 1] + nowval);
            i = r;
        }
    }

    block1.push_back({n + 1, n + 1, 0});
    pre1.push_back(pre1[pre1.size() - 1]);

    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        Node tmpl = {l, l}, tmpr = {r, r};
        int itl = upper_bound(block1.begin(), block1.end(), tmpl) - block1.begin() - 1;
        int itr = upper_bound(block1.begin(), block1.end(), tmpr) - block1.begin() - 1;

        int preitl = itl, preitr = itr;

        if (arr[r] == 1)
        {
            preitr--;
        }

        preitl++;

        int nowval = 0;
        int nowlen;
        if (arr[l] == 0 && arr[r] == 0)
        {
            nowlen = 0;
        }
        else if (arr[l] == 1 && arr[r] == 0)
        {
            int bl = l, br = block1[itl].r;
            nowlen = (br - bl + 1);
        }
        else if (arr[l] == 0 && arr[r] == 1)
        {
            int bl = block1[itr].l, br = r;
            nowlen = (br - bl + 1);
        }
        else
        {
            nowlen = (block1[itl].r - l + 1) + (r - block1[itr].l + 1);
        }

        if (nowlen & 1)
        {
            nowval = nowlen / 2 + 2;
        }
        else
        {
            nowval = nowlen / 2;
        }

        if (preitr >= preitr)
        {
            nowval += pre1[preitr] - pre1[preitl - 1];
        }

        int now0 = pre0[r] - pre0[l - 1];
        int ans;
        if (nowval >= now0)
        {
            ans = 0;
        }
        else
        {
            ans = (now0 - nowval) / 3;
        }
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
