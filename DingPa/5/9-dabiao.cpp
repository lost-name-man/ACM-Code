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
#define INF 1e9
#define endl '\n'
#define MOD (int)(998244353)

const int N = 1000005;
const int M = N * 2;
using namespace std;

vector<double>win;

int qpow(int x, int p)
{
    int base = x,sum=1;
    while (p)
    {
        if (p & 1)
        {
            sum *= base;
            sum %= MOD;
        }
        base = base * base;
        base %= MOD;
        p = p >>1 ;
    }

    return sum % MOD;
}

int inv(int x)
{
    int ret = qpow(x, MOD - 2) % MOD;
    return ret;
}

/*int adivb(int a, int b)
{
    int ret = (a%MOD * inv(b))%MOD;
    return ret;
}*/
double adivb(int a, int b)
{
    return 1.0 * a / b;
}

void check(int nowx)
{
    double up, down;
    if (win[nowx - 2] < win[nowx - 5])
    {
        //cout << nowx << " : -> " << nowx - 1 << " choose: -2" << endl;
        up = win[nowx - 2];
    }
    else if (win[nowx - 2] == win[nowx - 5])
    {
        //cout << nowx << " : -> " << nowx - 1 << " choose: ==" << endl;
        up = win[nowx - 2];
    }
    else
    {
        //cout << nowx << " : -> " << nowx - 1 << " choose: -5" << endl;
        up = win[nowx - 5];
    }


    if (win[nowx - 5] < win[nowx - 8])
    {
        //cout << nowx << " : -> " << nowx - 4 << " choose: -5" << endl;
        down = win[nowx - 5];
    }
    else if (win[nowx - 5] == win[nowx - 8])
    {
        //cout << nowx << " : -> " << nowx - 4 << " choose: ==" << endl;
        down = win[nowx - 5];
    }
    else
    {
        //cout << nowx << " : -> " << nowx - 4 << " choose: -8" << endl;
        down = win[nowx - 8];
    }

    win[nowx] = 1.0 / 2 * up + 1.0 / 2 * down;
    cout << nowx << " == " << win[nowx] << endl;

}

void solve()
{
    
    for (int i = 9; i <= 100; i++)
    {
        check(i);
    }
    
}

signed main()
{
    win = vector<double>(10004);
    win[0] = 0;
    win[1] = adivb(1, 2);
    win[2] = 0;
    win[3] = adivb(1, 4);
    win[4] = adivb(1, 2);
    win[5] = adivb(0, 4);
    win[6] = adivb(1, 2);
    win[7] = adivb(0, 4);
    win[8] = adivb(1, 8);

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