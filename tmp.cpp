#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

int y, b, c;

void mul(vector<int> &arr)
{
    int jin = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] * 2;
    }
    for (int i = 0; i < arr.size(); i++)
    {

        if (i + 1 == arr.size())
        {
            arr.push_back(arr[i] / 10);
            arr[i] %= 10;
            break;
        }
        else
        {
            arr[i + 1] += arr[i] / 10;
            arr[i] %= 10;
        }
        }
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            arr.pop_back();
        }
        else
        {
            break;
        }
    }
}

void solve()
{
    vector<int> arr;
    cin >> y >> b >> c;
    fflush(stdout);
    y = 1;
    while (y)
    {
        arr.push_back(y % 10);
        y /= 10;
    }
    int type = 0;

    while (type != 2)
    {
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            cout << arr[i];
        }
        cout << endl;
        fflush(stdout);
        mul(arr);
        cin >> type;
        fflush(stdout);
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
