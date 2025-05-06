#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define int long long

void solve()
{
	int n, m;
	cin >> n >> m;
	int ans = 0;

	map<int, int> mp;
	int nowtime = 0;
	for (int i = 1; i <= n; i++)
	{
		int p, q;
		cin >> p >> q;
		mp[nowtime] = 1;
		nowtime += 3*16 / q * p;
		
	}
	nowtime = 0;
	for (int i = 1; i <= m; i++)
	{
		int p, q;
		cin >> p >> q;
		if (mp[nowtime])
		{
			ans++;
		}
		nowtime += 3*16 / q * p;
		
	}
	cout << ans << endl;
}

signed main()
{
	std::ios::sync_with_stdio(0);
    std::cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
	}
	return 0;
}