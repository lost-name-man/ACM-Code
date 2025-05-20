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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;

int n, m;
vector<int> arr(1000006+100);
vector<map<int, int>> num_prim(1000006 + 100);
vector<int> primes;
map<int, size_t> int2hash;

vector<size_t> sumhash(1000006 + 100);


static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

unordered_map<size_t, size_t>hashmap;
size_t hash_int(int x) 
{
    if(hashmap[x]==0)
    {
        hashmap[x]=rnd();
        return hashmap[x];
    }
    else
    {
        return hashmap[x];
    }
}
// hash<int> hash_int;


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 5, 0);
    vector<size_t> b(n + 5);

    map<size_t, int> num_bd;
    size_t nowhash = 0;

    long long ans = 0;
    long long ansl = -1, ansr = -1;
    num_bd[nowhash] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = sumhash[a[i]];
        if (b[i] == 0 && ans == 0)
        {
            ans = 1;
            ansl = i;
            ansr = i;
        }
        nowhash = nowhash ^ b[i];
        int nowindex = num_bd[nowhash];
        if (nowhash == 0)
        {
            if (i > ans)
            {
                ansl = 1;
                ansr = i;
                ans = i;
            }
        }
        else if (nowindex == 0)
        {
            num_bd[nowhash] = i;
        }
        else
        {
            if (i - nowindex > ans)
            {
                ansl = nowindex + 1;
                ansr = i;
                ans = i - nowindex;
            }
            else if (i - nowindex == ans && nowindex + 1 < ansl)
            {
                ansl = nowindex + 1;
                ansr = i;
            }
        }
    }
    if (ans <= 0)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        cout << ansl << " " << ansr << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for (int i = 2; i <= 1e6 + 50; i++)
    {
        if (arr[i] == 0)
        {
            int nowhash = hash_int(i);
            for (int j = i; j <= 1e6 + 50; j += i)
            {
                arr[j] = 1;
                int cpj = j;
                while (cpj % i == 0 && cpj != 0)
                {
                    sumhash[j] ^= nowhash;
                    cpj /= i;
                }
            }
        }
    }
    sumhash[1] = 0;

    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}