#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        ll i = 0;
        __int128 j = 1;
        while (true)
        {
            ++i;
            j *= 2;
            if (b %j != 0)
            {
                printf("%lld %lld\n", i, 0LL);
                break;
            }
            j *= 2;
            if (a %j != 0)
            {
                printf("%lld %lld\n", i, 1LL);
                break;
            }
        }
    }
    return 0;
}
