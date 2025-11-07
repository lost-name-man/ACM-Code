#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iterator>
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
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;

int gcd(int a, int b)
{

    if (a < b)
    {
        swap(a, b);
    }

    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int n, q;
vector<int> arr;
set<pair<int, int>> st;
map<int, map<int, int>> divi;

int nowgcd;

int spx[2000005];
void divierase(int num)
{
    int nownum = num;
    while (nownum != 1)
    {
        int nowp = spx[nownum];
        int cnt = 0;
        while (nownum % nowp == 0)
        {
            cnt++;
            nownum /= nowp;
        }
        divi[nowp][cnt]--;
        if (divi[nowp][cnt] == 0)
        {
            divi[nowp].erase(cnt);
            if (!divi[nowp].empty())
            {
                nowgcd = nowgcd / pow(nowp, cnt) * pow(nowp, divi[nowp].begin()->first);
            }
        }
    }
}

void diviadd(int num)
{
    if (num == 1)
    {
        nowgcd = 1;
        return;
    }
    int nownum = num;
    while (nownum != 1)
    {
        int nowp = spx[nownum];
        int cnt = 0;
        while (nownum % nowp == 0)
        {
            cnt++;
            nownum /= nowp;
        }

        if (cnt < divi[nowp].begin()->first)
        {
            nowgcd = nowgcd / pow(nowp, divi[nowp].begin()->first - cnt);
        }
        divi[nowp][cnt]++;
    }
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
    st = set<pair<int, int>>();
    divi = map<int, map<int, int>>();
    int lastindex = 1;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i - 1] > arr[i])
        {
            st.insert({lastindex, i - 1});
            lastindex = i;
        }
    }
    st.insert({lastindex, n});
    nowgcd = st.begin()->second - st.begin()->first + 1;
    for (auto it = st.begin(); it->second != n; it++)
    {

        int len = it->second - it->first + 1;
        nowgcd = gcd(nowgcd, it->second - it->first + 1);
        int tmp = len;
        while (tmp != 1)
        {
            int i = spx[tmp];
            int divinum = 0;
            while (tmp % i == 0)
            {
                divinum++;
                tmp /= i;
            }

            divi[i][divinum]++;
        }
    }

    cout << nowgcd << endl;
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
                            divierase(it->second - it->first + 1);
                        }
                        it = st.erase(it);
                        it--;
                    }
                    else
                    {
                        cotmp.second = cotmp.first;
                        pair<int, int> tmp = *it;
                        tmp.first++;
                        if (it->second != n)
                        {
                            divierase(it->second - it->first + 1);
                        }
                        it = st.erase(it);
                        it--;
                        if (tmp.second != n)
                        {
                            diviadd(tmp.second - tmp.first + 1);
                        }
                        st.insert(tmp);
                    }

                    pair<int, int> tmp = *it;
                    tmp.second = cotmp.second;
                    if (it->second != n)
                    {
                        divierase(it->second - it->first + 1);
                    }
                    st.erase(it);
                    if (tmp.second != n)
                    {
                        diviadd(tmp.second - tmp.first + 1);
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
                        divierase(it->second - it->first + 1);
                    }
                    if (tmpl.second != n)
                    {
                        diviadd(tmpl.second - tmpl.first + 1);
                    }
                    if (tmpr.second != n)
                    {
                        divierase(tmpr.second - tmpr.first + 1);
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
                if (p != n && v <= arr[p + 1])
                {
                    if (it->first == it->second)
                    {
                        if (it->second != n)
                        {
                            divierase(it->second - it->first + 1);
                        }
                        st.erase(it);
                    }
                    else
                    {
                        pair<int, int> tmp = *it;
                        tmp.second--;
                        if (it->second != n)
                        {
                            divierase(it->second - it->first + 1);
                        }
                        if (tmp.second != n)
                        {
                            diviadd(tmp.second - tmp.first + 1);
                        }
                        st.erase(it);
                        st.insert(tmp);
                    }

                    pair<int, int> tmp = *it;
                    tmp.first--;
                    if (it->second != n)
                    {
                        divierase(it->second - it->first + 1);
                    }
                    if (tmp.second != n)
                    {
                        diviadd(tmp.second - tmp.first + 1);
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
                        divierase(it->second - it->first + 1);
                    }
                    if (tmpl.second != n)
                    {
                        diviadd(tmpl.second - tmpl.first + 1);
                    }
                    if (tmpr.second != n)
                    {
                        diviadd(tmpr.second - tmpr.first + 1);
                    }
                    st.erase(it);
                    st.insert(tmpl);
                    st.insert(tmpr);
                }
            }
        }
        arr[p] = v;
        cout << nowgcd << endl;
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
    // return 0;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
