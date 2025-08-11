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
#define int  unsigned __int128
#define endl '\n'
static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e9;
const int MOD = 11380;



inline __int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar(); 


    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }


    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }

    return x * f;
}


inline void prints(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        prints(x / 10); 
    }
    putchar(x % 10 + '0'); 
}


int ysf(int n, int w)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        int tmp=ysf(n - 1, w);
        int ret=(tmp + w - 1) % n + 1;

        return ret;
    }
    
}

void solve()
{
    int n, w;
    // cin>>n>>w;
    n=read();
    w=read();

    if(w==1)
    {
        prints((n*(n+1))/2);
        cout<<endl;
        return;
    }

    int copyn=n;


    int turn=0;
    // map<int, int>turn_num;
    int ans=0;

    int l=1, r;
    while(1)
    {
        turn++;
        int len=copyn/w;
        // turn_num[turn]=len;

        r=l+len-1;
        
        
        if(copyn<w)
        {
            break;
        }
        // cout<<"@"<<l<<" "<<r<<endl;
        ans+=turn*((r+l)*(len))/2;
        
        // cout<<"$"<<ans<<endl;

        copyn-=len;
        l+=len;
    }


    if(l<=n)
    {
        
        
        r=n;
        int len=r-l+1;
        // cout<<"#"<<len<<endl;
        // cout<<"@"<<l<<" "<<r<<endl;
        ans+=turn*((r+l)*(len))/2;
    }
    


    prints(ans);
    cout<<endl;

    // cout<<"!!!!!!!!"<<n<<" "<<w<<"!!!!!!!!!!!"<<endl;
    // for(auto iter=turn_num.begin(); iter!=turn_num.end(); iter++)
    // {
    //     cout<<iter->first<<" "<<iter->second<<endl;
    // }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long T = 1;

    cin >> T;
    

    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
