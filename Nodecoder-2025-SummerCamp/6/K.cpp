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
const int INF = 1e17 + 7;
const int MOD = 1e17 + 7;

int gcd(int a, int b)
{

    while (b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
vector<int> primes;

void cul_pre(int n, vector<int> &pri)
{
    vector<bool> not_prime(n + 5, 0);
    for (int i = 2; i <= n; ++i)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
        }
        for (int pri_j : pri)
        {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = true;
            if (i % pri_j == 0)
            {

                break;
            }
        }
    }
}

void cul_prime_factor(int x, vector<pair<int, int>> &factor)
{
    for (int i = 0; i < primes.size(); i++)
    {
        int pri = primes[i];
        if (x % pri == 0)
        {
            int adds = 0;
            while (x % pri == 0)
            {
                adds++;
                x /= pri;
            }
            factor.push_back({pri, adds});
        }
        if (x == 0)
        {
            break;
        }
    }
}

void cul_factor(int x, vector<int> &factor)
{
    for (int i = 1; i * i <= x; i++)
    {
        int pri = i;
        if (x % pri == 0)
        {
            factor.push_back(pri);
            factor.push_back(x / pri);
        }
    }
}

void solve()
{

    int n;
    cin >> n;

    vector<int> arr(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<int> brr(n + 5, 0);
    for (int i = 2; i <= n; i++)
    {
        brr[i] = arr[i] - arr[i - 1];
    }

    // all same
    {
        int ok = 1;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                ok = 0;
                break;
            }
        }

        if (ok == 1)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
        }
    }

    // all add
    int ans = 0;

    {
        int tmpans = brr[2];
        for (int i = 2; i <= n; i++)
        {
            tmpans = gcd(tmpans, abs(brr[i]));
        }

        ans = max(ans, tmpans);
    }

    // a1
    {
        vector<int> aein_factor;
        cul_factor(arr[1], aein_factor);
        for (int ff = 0; ff < aein_factor.size(); ff++)
        {
            int pri = aein_factor[ff];
            int wanum = 0;
            vector<int> waid;
            for (int i = 2; i <= n; i++)
            {
                if (brr[i] % pri != 0)
                {
                    wanum++;
                    waid.push_back(i);
                }
            }

            if (wanum == 0)
            {
                ans = max(ans, pri);
            }
            else if (wanum == 1)
            {
                ans = max(ans, pri);
            }
            else if (wanum == 2)
            {
                // int a, b;
                // a = brr[waid[0]] % pri;
                // b = brr[waid[1]] % pri;

                if ((brr[waid[0]] + brr[waid[1]]) % pri == 0)
                {
                    ans = max(ans, pri);
                }
            }
            else
            {
            }
        }
    }

    reverse(arr.begin() + 1, arr.begin() + 1 + n);
    for (int i = 2; i <= n; i++)
    {
        brr[i] = arr[i] - arr[i - 1];
    }
    // an
    {
        vector<int> aein_factor;
        cul_factor(arr[1], aein_factor);
        for (int ff = 0; ff < aein_factor.size(); ff++)
        {
            int pri = aein_factor[ff];
            int wanum = 0;
            vector<int> waid;
            for (int i = 2; i <= n; i++)
            {
                if (brr[i] % pri != 0)
                {
                    wanum++;
                    waid.push_back(i);
                }
            }

            if (wanum == 0)
            {
                ans = max(ans, pri);
            }
            else if (wanum == 1)
            {
                ans = max(ans, pri);
            }
            else if (wanum == 2)
            {
                // int a, b;
                // a = brr[waid[0]] % pri;
                // b = brr[waid[1]] % pri;

                if ((brr[waid[0]] + brr[waid[1]]) % pri == 0)
                {
                    ans = max(ans, pri);
                }
            }
            else
            {
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cul_pre((int)1e5, primes);

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
