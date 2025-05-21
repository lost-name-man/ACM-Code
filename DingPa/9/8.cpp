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


vector<vector<int>>ansxy;
void addinv(int xl, int xr, int yl, int yr)
{
    ansxy[xl][yl]++;
    ansxy[xl][yr + 1]--;
    ansxy[xr + 1][yl]--;
    ansxy[xr + 1][yr + 1]++;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int>arr(n + 5, 0);
    map<int, int>arr_index;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr_index[arr[i]] = i;
    }

    vector<int>arr_sort = arr;
    sort(arr_sort.begin() + 1, arr_sort.begin() + 1 + n);

    //preparation
    ansxy = vector<vector<int>>(n + 5, vector<int>(n + 5, 0));

    vector<int>brr(n + 5, 1);
    brr[0] = -1;
    brr[n + 1] = -1;
    brr[n + 2] = -1;
    for (int q = 1; q <= n; q++)
    {
        int nowval = arr_sort[q];
        int index = arr_index[nowval];
        brr[index] = 0;
        int nulll = index, nullr = index;
        while (brr[nulll - 1] == 0)
        {
            nulll--;
        }
        while (brr[nullr + 1] == 0)
        {
            nullr++;
        }
        int einl = nullr+1, einr = nullr+1;
        if (nullr != n)
        {
            while (brr[einr + 1] == 1)
            {
                einr++;
            }
            addinv(nulll, index, einl, einr);
        }
        else
        {
            continue;
        }





        // cout << "@";
        // cout << nulll << " " << index << " " << einl << " " << einr << endl;
        /*
        cout << "#" << endl;
        vector<vector<int>>ans(n + 5, vector<int>(n + 5, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[i][j] += ansxy[i][j] + ansxy[i - 1][j - 1] - ansxy[i - 1][j] - ansxy[i][j - 1];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << ansxy[i][j] << " ";
            }
            cout << endl;
        }*/

    }





    vector<vector<int>>ans(n + 5, vector<int>(n + 5, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ansxy[i][j] += ansxy[i - 1][j] + ansxy[i][j - 1] - ansxy[i - 1][j - 1];
        }
    }


    // cout << "#" << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << ansxy[i][j] << " ";
    //     }
    //     cout << endl;
    // }



    //query
    for (int que = 1; que <= q; que++)
    {
        int ql, qr;
        cin >> ql >> qr;
        cout << ansxy[ql][qr] << endl;
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