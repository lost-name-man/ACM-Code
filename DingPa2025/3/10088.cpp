#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000007

using namespace std;

int n;
string instr;
vector<int> arr;

vector<int> nullein(1000006);
vector<int> einnull(1000006);

int check(vector<int> &arr, vector<int> &crr)
{
    vector<int> f(n + 5, 0);

    map<int, int> len_num;

    int wanum = 0;
    int nowlen = 0;


    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == crr[i])
        {

        }
        else
        {
            wanum++;
        }

    }
    if(wanum==n)
    {
        return n/2;
    }
    
    int st=1;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==crr[i])
        {
            st=i;
            break;
        }
    }

    for (int t = 1; t <= n; t++)
    {

        
        int i=st;

        if (arr[i] == crr[i])
        {
            if (nowlen > 0)
            {
                len_num[nowlen]++;
                nowlen = 0;
            }
        }
        else
        {
            nowlen++;
            wanum++;
        }

        st=st+1;
        if(st>n)
        {
            st=1;
        }
        // cout << "#" << nowlen << endl;
    }
    len_num[nowlen]++;

    int ret = 0;
    for (auto iter = len_num.begin(); iter != len_num.end(); iter++)
    {
        int len = iter->first;
        int num = iter->second;

        // cout << "@" << len << " " << num << endl;

        ret += ((len + 1) / 2) * num;
    }

    return ret;
}

void solve()
{
    cin >> n;
    cin >> instr;
    arr = vector<int>(n + 5, 0);

    for (int i = 1; i <= n; i++)
    {
        arr[i] = instr[i - 1] - '0';
    }

    vector<int> arr_copy = arr;
    int ans = check(arr_copy, nullein);
    // cout << "!" << ans << endl;
    ans = min(ans, check(arr_copy, einnull));
    // cout << "!" << ans << endl;

    reverse(arr_copy.begin() + 1, arr_copy.begin() + 1 + n);
    ans = min(ans, check(arr_copy, nullein));
    // cout << "!" << ans << endl;
    ans = min(ans, check(arr_copy, einnull));
    // cout << "!" << ans << endl;

    cout << ans << endl;
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;

    for (int i = 1; i <= 1000000; i++)
    {
        nullein[i] = (i % 2) ^ 1;
        einnull[i] = (i % 2);
    }

    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
