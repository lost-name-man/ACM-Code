#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int n, k;
int sumop;
int work1(int cn)
{
    int cnt = 0;

    while (cn > 1)
    {
        cn -= ceil(cn * 1.0 / k);
        cnt++;
    }

    int index = 1;
    for (int i = 1; i <= cnt; i++)
    {
        index = index + ceil(index * 1.0 / (k - 1));
    }
    return index;
}
int work2(int cn)
{
    int cnt = 0;
    while (cn > 1)
    {
        int nowde = ceil(cn * 1.0 / k);

        if (nowde == 1)
        {
            cnt += cn - 1;
            cn = 1;
            continue;
        }
        int be_next_num = cn - ((nowde - 1) * k + 1) + 1; // 成为下一个至少需要减多少
        int to_next_turn = ceil(be_next_num * 1.0 / nowde);

        cnt += to_next_turn;
        cn -= to_next_turn * nowde;
    }

    int nowcnt = 0;
    int index = 1;
    while (nowcnt < cnt)
    {
        int addnum = ceil(index * 1.0 / (k - 1));
        int be_next_num = (addnum) * (k - 1) + 1; // 前面有addnum个-1与一个1
        int to_next_turn = ceil((be_next_num - index) * 1.0 / addnum);

        int turn = min(cnt - nowcnt, to_next_turn);
        index = index + turn * addnum;
        nowcnt += turn;
    }

    return index;
}
void solve()
{
    cin >> n >> k;
    int ans;
    if (k < 1e9 && k * k <= n)
    {
        ans = work1(n);
    }
    else
    {
        ans = work2(n);
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
