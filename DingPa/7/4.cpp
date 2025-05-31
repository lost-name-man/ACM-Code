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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

const int N = 1000005;
const int M = N * 2;
using namespace std;

void makelzy(int tot, int x);
void makesame(int tot, int x);
void downlzy(int tot);
void update(int tot, int le, int ri, int x);
int query(int tot, int le, int ri);
void upsame(int tot, int le, int ri, int x);
struct node
{
    int L;
    int R;
    int val0;
    int val1;
    int same0 = INF;
    int same1 = INF;
} tree[2000006];
int arrline0[500005] = {0};
int arrline1[500005] = {0};
void makesame0(int tot, int x)
{
    tree[tot].val0 = x;
    tree[tot].same0 = x;
}
void makesame1(int tot, int x)
{
    tree[tot].val1 = x;
    tree[tot].same1 = x;
}
void downlzy(int tot)
{
    if (tree[tot].same0 != INF)
    {
        makesame0(tot * 2, tree[tot].same0);
        makesame0(tot * 2 + 1, tree[tot].same0);
        tree[tot].same0 = INF;
    }
    if (tree[tot].same1 != INF)
    {
        makesame1(tot * 2, tree[tot].same1);
        makesame1(tot * 2 + 1, tree[tot].same1);
        tree[tot].same1 = INF;
    }
}

int query0(int tot, int k)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (LL == RR)
    {
        if (tree[tot].val0 >= k)
        {
            return LL;
        }
        else
        {
            return -1;
        }
    }
    downlzy(tot);
    if (tree[tot * 2].val0 >= k)
    {
        query0(tot * 2, k);
    }
    else
    {
        query0(tot * 2 + 1, k);
    }
}
int query1(int tot, int k)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (LL == RR)
    {
        if (tree[tot].val1 >= k)
        {
            return LL;
        }
        else
        {
            return -1;
        }
    }
    downlzy(tot);
    if (tree[tot * 2].val1 >= k)
    {
        query1(tot * 2, k);
    }
    else
    {
        query1(tot * 2 + 1, k);
    }
}

void upsame0(int tot, int le, int ri, int x)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        makesame0(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        downlzy(tot);
        upsame0(tot * 2, le, ri, x);
        upsame0(tot * 2 + 1, le, ri, x);
        tree[tot].val0 = max(tree[tot * 2].val0, tree[tot * 2 + 1].val0);
        return;
    }
}
void upsame1(int tot, int le, int ri, int x)
{
    int LL = tree[tot].L, RR = tree[tot].R;
    if (le <= LL && ri >= RR)
    {
        makesame1(tot, x);
        return;
    }
    else if (!(le > RR || ri < LL))
    {
        downlzy(tot);
        upsame1(tot * 2, le, ri, x);
        upsame1(tot * 2 + 1, le, ri, x);
        tree[tot].val1 = max(tree[tot * 2].val1, tree[tot * 2 + 1].val1);
        return;
    }
}

void build(int tot, int LL, int RR)
{
    tree[tot].L = LL;
    tree[tot].R = RR;
    tree[tot].same0 = INF;
    tree[tot].same1 = INF;
    if (LL == RR)
    {
        tree[tot].val0 = arrline0[LL];
        tree[tot].val1 = arrline1[LL];

        return;
    }
    int m = (LL + RR) / 2;
    build(tot * 2, LL, m);
    build(tot * 2 + 1, m + 1, RR);
    tree[tot].val0 = max(tree[tot * 2].val0, tree[tot * 2 + 1].val0);
    tree[tot].val1 = max(tree[tot * 2].val1, tree[tot * 2 + 1].val1);
}

string str;
int q;
set<int> ranges;
map<int, pair<int, int>> mp;

void mergerange(int nowindex)
{
    auto it = ranges.lower_bound(nowindex);
    int sumlen = mp[*it].first;
    if (it != ranges.end())
    {
        it++;
        sumlen += mp[*it].first;
        if (mp[*it].second == 0)
        {
            upsame0(1, *it, *it, 0);
        }
        else
        {
            upsame1(1, *it, *it, 0);
        }
        it = ranges.erase(it);
        it--;
    }
    if (it == ranges.begin())
    {
        mp[*it].first = sumlen;
        if (mp[*it].second == 0)
        {
            upsame1(1, *it, *it, sumlen);
            upsame0(1, *it, *it, 0);
        }
        else
        {
            upsame0(1, *it, *it, sumlen);
            upsame1(1, *it, *it, sumlen);
        }
    }
    else
    {
        if (mp[*it].second == 0)
        {
            upsame0(1, *it, *it, 0);
        }
        else
        {
            upsame1(1, *it, *it, 0);
        }
        it = ranges.erase(it);
        it--;
        sumlen += mp[*it].first;
        mp[*it].first = sumlen;
        if (mp[*it].second == 0)
        {
            upsame1(1, *it, *it, sumlen);
            upsame0(1, *it, *it, 0);
        }
        else
        {
            upsame0(1, *it, *it, sumlen);
            upsame1(1, *it, *it, sumlen);
        }
    }
}
void solve()
{
    mp = map<int, pair<int, int>>();
    ranges = set<int>();
    cin >> str;
    int n = str.size();
    str = "@" + str;
    int st = 1;
    memset(arrline0, 0, sizeof(arrline0));
    memset(arrline1, 0, sizeof(arrline1));
    for (int i = 1; i < n; i++)
    {
        if (str[i] != str[i + 1])
        {
            if (str[i] == '0')
            {
                ranges.insert(st);
                arrline0[st] = i - st + 1;
                mp[st] = {i - st + 1, 0};
            }
            else
            {
                ranges.insert(st);
                arrline1[st] = i - st + 1;
                mp[st] = {i - st + 1, 1};
            }
            st = i + 1;
        }
    }
    if (str[n] == '0')
    {
        ranges.insert(st);
        arrline0[st] = n - st + 1;
        mp[st] = {n - st + 1, 0};
    }
    else
    {
        ranges.insert(st);
        arrline1[st] = n - st + 1;
        mp[st] = {n - st + 1, 1};
    }
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int op, k;
        cin >> op >> k;
        if (op == 0)
        {
            int nowindex = query0(1, k);
            cout << nowindex << endl;
            if (nowindex != -1)
            {
                mergerange(nowindex);
            }
        }
        else
        {
            int nowindex = query1(1, k);
            cout << nowindex << endl;
            if (nowindex != -1)
            {
                mergerange(nowindex);
            }
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}