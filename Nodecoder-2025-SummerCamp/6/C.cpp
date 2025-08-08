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
const int INF = 2e9 + 7;
const int MOD = 1e17 + 7;


int f(vector<int> &p)
{
    stack<int>stk;
    for(int i=0; i<p.size(); i++)
    {
        int elem=p[i];
        while(stk.size() && stk.top()>elem)
        {
            stk.pop();
        }
        stk.push(elem);
    }


    return stk.size();
}

void solve(int n)
{
    vector<int>arr;
    // int n;
    // cin>>n;

    cout<<"#n=="<<n<<endl;
    for(int i=1; i<=n; i++)
    {
        arr.push_back(i);
    }


    int ans=0;
    map<int, int>val_num;
    do
    {
        int num=f(arr);
        val_num[num]++;
        // cout<<"!"<<num<<endl;
        ans+=pow(num, 3);
    } while (next_permutation(arr.begin(), arr.end()));


    cout<<ans<<endl;

    vector<int>vs;
    for(auto iter=val_num.begin(); iter!=val_num.end(); iter++)
    {
        cout<<"@"<<iter->first<<" "<<iter->second<<endl;
        vs.push_back(iter->second);
    }
    vector<int>outpus;

    for(int i=0; i<(int)vs.size()-2; i++)
    {

        int nowval=vs[i];
        int dtimes=nowval/2;
        outpus.push_back(dtimes);
        vs[i]-=2*dtimes;
        vs[i+1]-=3*dtimes;
        vs[i+2]-=1*dtimes;
    }

    for(int i=0; i<outpus.size(); i++)
    {
        cout<<"%"<<outpus[i]<<endl;
    }


    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;

    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
}
