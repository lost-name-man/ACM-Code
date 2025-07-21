#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
#include<fstream>
#include <iomanip>

typedef long double ld;
#define int long long
#define INF 1e18
#define endl '\n'
#define MOD 1000000007

using namespace std;

void dabiao()
{
    ofstream outfile;
	outfile.open("dabiao.txt");
    vector<vector<int>>crood(20+5, vector<int>(20+5, 0));
    for(int i=1; i<=20; i++)
    {
        crood[1][i]=1;
        crood[i][1]=1;
    }
    for(int i=2; i<=20; i++)
    {
        for(int j=2; j<=20; j++)
        {
            crood[i][j]=crood[i-1][j]+crood[i][j-1];
        }
        
    }
    for(int i=20; i>=1; i--)
    {
        for(int j=1; j<=20; j++)
        {
            outfile<<setw(5)<<crood[i][j]<<" ";
        }
        outfile<<endl;
        
    }
    
}


void solve()
{
    dabiao();
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