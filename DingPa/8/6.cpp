#include <bits/stdc++.h>

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;


void solve()
{

    
    
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    cin >> T;

    // scanf("%lld", &T);
    int n, k, m, t;
    int c;
    int ans=0;
    while(T--)
    {
        
        cin>>n>>k>>m>>t;
        // scanf("%lld %lld %lld %lld", &n, &k, &m, &t);




        ans=0;
        for(int i=1; i<=t; i++)
        {

            c= k*(__gcd(n, i+1))/n;
            ans+=m*(k-c);

            // int b = n / std::__gcd(n, i + 1);
            // ans += 1ll * m * (k - k / b);
            
        }

        // ans=(ans+((n-1)*t-1))/((n-1)*t);

        ans = (ans + 1ll * t * (n - 1) - 1) / (1ll * t * (n - 1));


        // printf("%lld\n", ans);
        cout<<ans<<endl;
    }
    return 0;
}