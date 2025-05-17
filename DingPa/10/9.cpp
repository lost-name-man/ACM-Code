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

using namespace std;

int n, m;
int arr[1000006] = { 0 };
vector<map<int, int>>num_prim(1000006);
vector<int>primes;
map<int, size_t>int2hash;
hash<int> hash_int;
vector<size_t>sumhash(1000006);
void solve()
{
    int n;
    cin >> n;
    vector<int>a(n + 5, 0);
    vector<size_t>b(n + 5);
    
    unordered_map<size_t, vector<int>>num_bd;
    size_t nowhash = 0;

    int ans = 0;
    int ansl = -1, ansr = -1;
    num_bd[nowhash].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = sumhash[a[i]];
      /*  if (b[i] == 0 && ans==0)
        {
            ans = 1;
            ansl = i;
            ansr = i;
        }*/
        nowhash = nowhash ^ b[i];
        num_bd[nowhash].emplace_back(i);
    }

    


    for (auto iter = num_bd.begin(); iter != num_bd.end(); iter++)
    {
        int nowans = iter->second.back() - iter->second.front();
        if (nowans > ans)
        {
            ans = nowans;
            ansl = iter->second.front()+ 1;
            ansr = iter->second.back();
        }
        else if (nowans >= ans && iter->second.front() < ansl)
        {
            ans = nowans;
            ansl = iter->second.front()+1;
            ansr = iter->second.back();
        }

    }

    cout << ansl << " " << ansr << endl;


}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    for (int i = 2; i <= 1e6; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i; j <= 1e6; j += i)
            {
                arr[j] = 1;
                int num = 0;
                int cpj = j;
                while (cpj % i == 0 && cpj != 0)
                {
                    num++;
                    cpj /= i;
                }
                num_prim[j][i] = num % 2;
            }
            primes.emplace_back(i);
            num_prim[i][i] = 1;
        }

    }
    for (int i = 0; i < primes.size(); i++)
    {
        int nowp = primes[i];
        int2hash[nowp] = hash_int(nowp);
    }

    for (int i = 1; i <= 1e6; i++)
    {
        size_t nowsum = 0;
        for (auto iter = num_prim[i].begin(); iter != num_prim[i].end(); iter++)
        {
            if (iter->second != 0)
            {
                nowsum = nowsum ^ (int2hash[iter->first]);
            }

        }
        sumhash[i] = nowsum;
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