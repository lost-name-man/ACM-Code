#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

struct Segtree
{
    int l;
    int r;
    int val;
};

vector<Segtree> tree;

int n, q;
vector<int> arr;
set<pair<int, int>> st;

int nowgcd;

int spx[2000005];

// Segtree
void build(int tot, int L, int R)
{
    tree[tot].l = L, tree[tot].r = R;
    if (L == R)
    {
        tree[tot].val = 0;
        return;
    }
    int mid = (L + R) / 2;
    build(tot * 2, L, mid);
    build(tot * 2 + 1, mid + 1, R);
    tree[tot].val = 0;
}

int query(int tot, int L, int R)
{
    int mid = (L + R) / 2;
    if (tree[tot].l >= L && tree[tot].r <= R)
    {
        return tree[tot].val;
    }
    else if (tree[tot].l > R || tree[tot].r < L)
    {
        return 0;
    }
    else
    {
        return __gcd(query(tot * 2, L, mid), query(tot * 2 + 1, mid + 1, R));
    }
}

void update(int tot, int index, int x)
{
    int mid = (tree[tot].l + tree[tot].r) / 2;
    if (tree[tot].l == index)
    {
        tree[tot].val = x;
        return;
    }
    if (index <= mid)
    {
        update(tot * 2, index, x);
    }
    else
    {
        update(tot * 2 + 1, index, x);
    }
    tree[tot].val = __gcd(tree[tot * 2].val, tree[tot * 2 + 1].val);
}

int ask_divi_num(int num)
{
    if (num == 1)
    {
        return 1;
    }
    int nownum = num;
    int re = 1;
    while (nownum != 1)
    {
        int nowp = spx[nownum];
        int cnt = 0;
        while (nownum % nowp == 0)
        {
            cnt++;
            nownum /= nowp;
        }
        re *= cnt + 1;
    }
}
void solve()
{

    cin >> n >> q;
    vector<int> arr(n + 5);
    tree = vector<Segtree>(4 * n + 5);
    st = set<pair<int, int>>();

    int lastindex = 1;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i - 1] > arr[i])
        {
            st.insert({lastindex, i - 1});
            update(1, lastindex, i - 1 - lastindex + 1);
            lastindex = i;
        }
    }
    st.insert({lastindex, n});

    cout << ask_divi_num(tree[1].val) << endl;
    for (int i = 1; i <= q; i++)
    {
        int p, v;
        cin >> p >> v;
        auto it = st.lower_bound({p, 0});
        if (v > arr[p])
        {
            if (p == it->first)
            {
                pair<int, int> cotmp = *it;
                if (p != 1 && v >= arr[p - 1])
                {
                    if (it->first == it->second || v <= arr[p + 1])
                    {

                        if (it->second != n)
                        {
                            update(1, it->first, 0);
                        }
                        it = st.erase(it);
                        it--;
                    }
                    else
                    {
                        cotmp.second = cotmp.first; // yi ge
                        pair<int, int> tmp = *it;
                        tmp.first++;
                        if (it->second != n)
                        {
                            update(1, tmp.first, 0);
                        }
                        it = st.erase(it);
                        it--;
                        if (tmp.second != n)
                        {
                            update(1, tmp.first, tmp.second - tmp.first + 1);
                        }
                        st.insert(tmp);
                    }

                    pair<int, int> tmp = *it;
                    tmp.second = cotmp.second;
                    if (it->second != n)
                    {
                        update(1, it->first, 0);
                    }
                    st.erase(it);
                    if (tmp.second != n)
                    {
                        update(1, it->first, tmp.second - tmp.first + 1);
                    }
                    st.insert(tmp);
                }
            }
            else if (p != it->second)
            {
                if (v > arr[p + 1])
                {
                    pair<int, int> tmpl = {it->first, p}, tmpr = {p + 1, it->second};
                    if (it->second != n)
                    {
                        update(1, it->first, 0);
                    }
                    if (tmpl.second != n)
                    {
                        update(1, tmpl.first, tmpl.second - tmpl.first + 1);
                    }
                    if (tmpr.second != n)
                    {
                        update(1, tmpr.first, tmpr.second - tmpr.first + 1);
                    }
                    st.erase(it);
                    st.insert(tmpl);
                    st.insert(tmpr);
                }
            }
        }
        else if (v < arr[p])
        {
            if (p == it->second)
            {
                pair<int, int> cotmp = *it;
                if (p != n && v <= arr[p + 1])
                {
                    if (it->first == it->second || v >= arr[p - 1])
                    {
                        if (it->second != n)
                        {
                            update(1, it->first, 0);
                        }
                        st.erase(it);
                    }
                    else
                    {
                        cotmp.first = cotmp.second;
                        pair<int, int> tmp = *it;
                        tmp.second--;
                        if (it->second != n)
                        {
                            update(1, it->first, 0);
                        }
                        if (tmp.second != n)
                        {
                            update(1, tmp.first, tmp.second - tmp.first + 1);
                        }
                        st.erase(it);
                        st.insert(tmp);
                    }

                    pair<int, int> tmp = *it;
                    tmp.first = cotmp.first;
                    if (it->second != n)
                    {
                        update(1, it->first, 0);
                    }
                    if (tmp.second != n)
                    {
                        update(1, tmp.first, tmp.second - tmp.first + 1);
                    }
                    st.erase(it);
                    st.insert(tmp);
                }
            }
            else if (p != it->first) // 长度至少为2
            {
                if (v < arr[p - 1])
                {
                    pair<int, int> tmpl = {it->first, p - 1}, tmpr = {p, it->second};
                    if (it->second != n)
                    {
                        update(1, it->first, 0);
                        // divierase(it->second - it->first + 1);
                    }
                    if (tmpl.second != n)
                    {
                        update(1, tmpl.first, tmpl.second - tmpl.first + 1);
                        // diviadd(tmpl.second - tmpl.first + 1);
                    }
                    if (tmpr.second != n)
                    {
                        update(1, tmpr.first, tmpr.second - tmpr.first + 1);
                        // diviadd(tmpr.second - tmpr.first + 1);
                    }
                    st.erase(it);
                    st.insert(tmpl);
                    st.insert(tmpr);
                }
            }
        }
        arr[p] = v;
        cout << ask_divi_num(tree[1].val) << endl;
    }
}

void init()
{
    for (int i = 2; i <= 200000; i++)
    {
        if (spx[i] == 0)
        {
            for (int j = i; j <= 200000; j += i)
            {
                spx[j] = i;
            }
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    cin >> T;

    init();
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
