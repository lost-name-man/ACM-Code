#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;
const int MOD = 1e9 + 7;

struct Node
{
    int x;
    int y;
    int val;
    int xandy;
    int xdey;
};

bool cmp1(Node &a, Node &b)
{
    return a.xandy < b.xandy;
}
bool cmp2(Node &a, Node &b)
{
    return a.xdey < b.xdey;
}
vector<Node> node;
int n;

int mypow(int n, int p)
{
    int base = n, re = 1;
    while (p)
    {
        if (p & 1)
        {
            re *= base;
            re %= MOD;
        }
        base *= base;
        base %= MOD;
        p >>= 1;
    }
    return re;
}

int inv(int x)
{
    return mypow(x, MOD - 2);
}
int getmod(int x)
{
    return (x % MOD + MOD) % MOD;
}

void solve()
{
    cin >> n;
    node = vector<Node>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        int x, y, val;
        cin >> x >> y >> val;
        node[i] = {x, y, val, x + y, x - y};
    }

    sort(node.begin() + 1, node.begin() + 1 + n, cmp1);

    int sum1 = 0;
    int prea = 0, prec = 0, preac = 0;
    for (int i = 1; i <= n; i++)
    {

        sum1 += getmod(getmod(node[i].val * node[i].xandy) * (i - 1)) + getmod(node[i].xandy * prea) - getmod(node[i].val * prec) - getmod(preac);
        sum1 = getmod(sum1);
        prea += node[i].val;
        prec += node[i].xandy;
        preac += node[i].val * node[i].xandy;
        prea = getmod(prea);
        prec = getmod(prec);
        preac = getmod(preac);
    }
    int sum2 = 0;
    prea = 0, prec = 0, preac = 0;
    sort(node.begin() + 1, node.begin() + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {

        sum2 += getmod(getmod(node[i].val * node[i].xdey) * (i - 1)) + getmod(node[i].xdey * prea) - getmod(node[i].val * prec) - getmod(preac);
        sum1 = getmod(sum1);
        prea += node[i].val;
        prec += node[i].xdey;
        preac += getmod(node[i].val * node[i].xdey);
        prea = getmod(prea);
        prec = getmod(prec);
        preac = getmod(preac);
    }
    int ans = getmod((getmod(sum1 + sum2)) * inv(2));
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
