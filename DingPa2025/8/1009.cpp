#include <cstddef>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <iomanip>
#include <random>
#include <chrono>
using namespace std;
#define int unsigned __int128
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;



inline void prints(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        prints(x / 10);
    }
    putchar(x % 10 + '0');
}

int query(int l, int r, int turn, int times)
{
    int len = (r - l + 1);
    int a = (l + r);
    int re = 0;

    re += (times * turn + times * (times - 1) / 2) * (a * len / 2);
    re += (times) * (times - 1) / 2 * (len * len) * turn;

    int x = times - 1;
    re += (x * (x + 1) * (2 * x + 1) / 6) * (len * len);
    return re;
}

void solve()
{
    int n, w;
    {
        long long lln, llw;
        cin>>lln>>llw;
        n=lln;
        w=llw;
    }


    if (w == 1)
    {
        prints((n * (n + 1)) / 2);
        printf("\n");
        return;
    }

    int copyn = n;
    int turn = 1;
    int ans = 0;

    int l = 1, r;

    while (1)
    {
        if (copyn < w)
        {
            break;
        }

        if (1)
        {
            int unitlen = copyn / w;
            int len = copyn % w + 1;

            int times = ceil(len * 1.0 / unitlen * 1.0);
            copyn -= times * unitlen;

            r = l + unitlen - 1;
            int tmpans;
            tmpans = query(l, r, turn, times);
            ans += tmpans;
            l += times * unitlen;
            turn += times;
        }
        else
        {
            int unitlen = copyn / w;
            r = l + unitlen - 1;
            ans += turn * (l + r) * unitlen / 2;
            copyn -= unitlen;
            l += unitlen;
            turn++;
        }
    }

    if (l <= n)
    {
        r = n;
        int len = r - l + 1;
        ans += turn * ((r + l) * (len)) / 2;
    }

    prints(ans);
    printf("\n");
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}