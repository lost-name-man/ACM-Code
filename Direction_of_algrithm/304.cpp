#include <bits/stdc++.h>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(998244353)

using namespace std;

const int N = 100000;

struct Node
{
    int l;
    int r;
    int j;
};

int n, l, p;
string poem[N + 10];
int arr[N + 10];
vector<int> prearr;
vector<ld> f;
vector<int> lastindex;
Node dq[N + 10];
int ll = 0, rr = 0;

ld mypow(ld x)
{
    ld v = 1;
    for (int k = p; k; k >>= 1, x *= x)
        if (k & 1)
            v *= x;
    return (v > 0 ? v : -v);
}
ld fi(int i, int j)
{
    return f[j] + mypow(abs(l - (prearr[i] - prearr[j] + i - j - 1)));
}
void solve()
{
    cin >> n >> l >> p;
    prearr = vector<int>(n + 10);
    f = vector<ld>(n + 10);
    lastindex = vector<int>(n + 10);
    ll = 0, rr = 0;
    dq[0] = {1, n, 0};
    for (int i = 1; i <= n; i++)
    {
        cin >> poem[i];
        arr[i] = poem[i].size();
        prearr[i] = prearr[i - 1] + arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        while (ll <= rr && dq[ll].r < i)
        {
            ll++;
        }
        dq[ll].l = i;
        int j = dq[ll].j;
        f[i] = fi(i, j);
        lastindex[i] = j;

        int ok = 0;
        while (ll <= rr && fi(dq[rr].l, dq[rr].j) >= fi(dq[rr].l, i))
        {
            ok = 1;
            rr--;
        }

        if (ll <= rr && fi(dq[rr].r, dq[rr].j) >= fi(dq[rr].r, i))
        {
            ok = 1;
            int l = dq[rr].l, r = dq[rr].r, j = dq[rr].j;
            int mid;
            int jindex;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (fi(mid, j) >= fi(mid, i))
                {
                    r = mid - 1;
                }
                else
                {
                    jindex = mid;
                    l = mid + 1;
                }
            }
            dq[rr].r = jindex;
            dq[++rr] = {jindex + 1, n, i};
        }
        else if (ok != 0)
        {

            int index;
            if (ll <= rr)
            {
                index = dq[rr].r;
            }
            else
            {
                i + 1;
            }
            dq[++rr] = {index + 1, n, i};
        }
    }
    int it = n;
    vector<int> end_of_poem;
    while (it != 0)
    {
        end_of_poem.push_back(it);
        it = lastindex[it];
    }

    reverse(end_of_poem.begin(), end_of_poem.end());
    it = 0;
    if (f[n] <= INF)
    {
        cout << (int)f[n] << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << poem[i];
            if (i != end_of_poem[it])
            {
                cout << ' ';
            }
            if (i == end_of_poem[it])
            {
                it++;
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Too hard to arrange" << endl;
    }
    for (int i = 1; i <= 20; i++)
    {
        cout << '-';
    }
    cout << endl;
}

signed main()
{
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    int T = 1;

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}