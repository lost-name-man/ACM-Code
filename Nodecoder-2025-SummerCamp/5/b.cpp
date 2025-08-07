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
#define int long long
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;

int a, b, c;
void solve()
{

    vector<int> ans;
    cin >> a >> b >> c;
    if (a == 0 && b == 0)
    {
        if (c == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return;
    }

    int it1 = 0;
    int ca = a;
    while (ca)
    {
        it1++;
        ca >>= 1;
    }
    it1--;

    int cb = b;
    int it2 = 0;
    while (cb)
    {
        it2++;
        cb >>= 1;
    }
    it2--;

    int cc = c;
    int it3 = 0;
    while (cc)
    {
        it3++;
        cc >>= 1;
    }
    it3--;

    if (it3 > it2 && it3 > it1)
    {
        if (it1 > it2)
        {
            ans.push_back(4);
            it2 = it1;
        }
        else if (it2 > it1)
        {
            ans.push_back(3);
            it1 = it2;
            a ^= b;
        }

        for (int i = it1; i <= it3; i++)
        {
            if (((a >> it2) & 1) != ((c >> (it3 - (it1 - it2)) & 1)))
            {
                ans.push_back(3);
                a ^= (1 << it2);
            }
            if (it1 != it3)
            {
                it1++;
                ans.push_back(1);
                a *= 2;
            }
        }
        for (int i = it2; i >= 0; i--)
        {
            if (((a >> it2) & 1) != ((c >> it2) & 1))
            {
                ans.push_back(3);
                a ^= (1 << it2);
            }
            ans.push_back(2);
            it2--;
        }
        ans.push_back(4);
    }
    else
    {
        if (it1 > it2)
        {
            ans.push_back(4);
            it2 = it1;
        }
        else if (it2 > it1)
        {
            ans.push_back(3);
            it1 = it2;
            a ^= b;
        }
        for (int i = it2; i >= 0; i--)
        {
            if (((a >> it2) & 1) != ((c >> it2) & 1))
            {
                ans.push_back(3);
                a ^= (1 << it2);
            }
            ans.push_back(2);
            it2--;
        }
        ans.push_back(4);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
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
