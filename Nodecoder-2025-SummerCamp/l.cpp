#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000000000000003

using namespace std;

struct Node
{
    int index;
    int val;
    bool operator<(const Node &other) const
    {
        return this->val < other.val;
    }
};

int n, q;

void solve()
{
    cin >> n >> q;
    map<int, int> good;
    map<int, int> numb;

    // map<int, int> num_nums;

    vector<Node> arr(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].val;
        arr[i].index = i;
    }

    sort(arr.begin() + 1, arr.begin() + 1 + n);
    vector<int> index_reflect(n + 5, 0);
    for (int i = 1; i <= n; i++)
    {
        index_reflect[arr[i].index] = i;
    }

    int loss_threshold = ((n - 1) + 1) / 2;

    int goodnum = 0;
    int numbnum = 0;
    {
        int tmploss = 0;
        int lastval = arr[n].val;
        for (int i = n; i >= 1; i--)
        {
            int nowval = arr[i].val;
            if (nowval < lastval)
            {
                tmploss = n - i;
                lastval = nowval;
            }

            if (tmploss < loss_threshold)
            {
                good[nowval]++;
                // num_nums[nowval]++;
                goodnum++;
            }
            else
            {
                numb[nowval]++;
                // num_nums[nowval]++;
                numbnum++;
            }
        }
    }

    for (int qq = 1; qq <= q; qq++)
    {
        int p, v;
        cin >> p >> v;
        int nowindex = index_reflect[p];
        int lastval = arr[nowindex].val;
        arr[nowindex].val += v;
        int newval = arr[nowindex].val;

        if (good[lastval] > 0)
        {
            good[lastval]--;

            good[newval]++;
            // num_nums[lastval]--;
            // num_nums[newval]++;

            while (good.begin()->second == 0)
            {
                good.erase(good.begin());
            }
            int mingoodval = good.begin()->first;
            if (goodnum - good[mingoodval] >= loss_threshold)
            {
                goodnum -= good[mingoodval];
                numbnum += good[mingoodval];
                numb[mingoodval] = good[mingoodval];
                good.erase(mingoodval);
                mingoodval = good.begin()->first;
            }
        }
        else
        {



            while (good.begin()->second == 0)
            {
                good.erase(good.begin());
            }
            int mingoodval = good.begin()->first;
            if (newval >= mingoodval)
            {

                numb[lastval]--;
                good[newval]++;
                numbnum--;
                goodnum++;

                if (goodnum - good[mingoodval] >= loss_threshold)
                {
                    goodnum -= good[mingoodval];
                    numbnum += good[mingoodval];
                    numb[mingoodval] = good[mingoodval];
                    good.erase(mingoodval);
                    mingoodval = good.begin()->first;
                }
            }
            else
            {
                numb[lastval]--;
                numb[newval]++;
            }
        }

        cout << numbnum << endl;
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