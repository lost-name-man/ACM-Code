#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'

const int INF = 2e9 + 7;

struct Node
{
    int id;
    int number;
    int magic;

    bool operator<(const Node &other) const
    {
        return this->magic > other.magic;
    }
};
vector<Node> arr;
vector<int> line_base;

int n;
int lingangu = 0;
void check_baseline(int tomorin)
{

    int rock = arr[tomorin].number;
    int gugugaga = arr[tomorin].magic;


    for (int i = 63; i >= 0; i--)
    {
        if (rock & (1ll << i))
        {
            if (line_base[i] == 0)
            {
                line_base[i] = rock;
                lingangu += gugugaga;
                return;
            }
            else
            {
                rock^=line_base[i];
            }
        }
    }
    
}

void solve()
{

    cin >> n;
    arr = vector<Node>(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].number >> arr[i].magic;
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n);

    line_base = vector<int>(n + 5, 0);

    for(int tomo=1; tomo<=n; tomo++)
    {
        check_baseline(tomo);
    }

    cout<<lingangu<<endl;
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    // cin>>T

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
