#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;
#define int long long
#define endl '\n'
const int INF = 1e18 + 3;
const int MOD = 20220911;

struct Sub
{
    int id;
    map<int, int>card_num;
    
    pair<int, int> declare_x_y;
    map<int, int>lastdispose;

};
vector<Sub>sub(4);
map<int, int>ondesk_cards;
int nowsub=0;
void solve()
{
    for(int i=0; i<4; i++)
    {
        for(int j=1; j<=13; j++)
        {
            int x;
            cin>>x;
            sub[i].card_num[x]++;
        }
    }

    int m;
    cin>>m;

    
    for(int turn=1; turn<=m; turn++)
    {
        int lastsub=(nowsub-1+4)%4;

        char op;
        cin>>op;
        if(op=='S')
        {
            cin>>sub[nowsub].declare_x_y.first>>sub[nowsub].declare_x_y.second;
            sub[nowsub].lastdispose.clear();

            for(int i=1; i<=sub[nowsub].declare_x_y.second; i++)
            {
                int x;
                cin>>x;
                sub[nowsub].lastdispose[x]++;
                sub[nowsub].card_num[x]--;
                ondesk_cards[x]++;
            }
        }
        else if(op=='!')
        {
            
            sub[nowsub].declare_x_y.first=sub[lastsub].declare_x_y.first;
            cin>>sub[nowsub].declare_x_y.second;
            sub[nowsub].lastdispose.clear();

            for(int i=1; i<=sub[nowsub].declare_x_y.second; i++)
            {
                int x;
                cin>>x;
                sub[nowsub].lastdispose[x]++;
                sub[nowsub].card_num[x]--;
                ondesk_cards[x]++;
            }
        }
        else
        {
            if(sub[lastsub].lastdispose[sub[lastsub].declare_x_y.first]==sub[lastsub].declare_x_y.second)
            {
                for(auto iter=ondesk_cards.begin(); iter!=ondesk_cards.end(); iter++)
                {
                    sub[nowsub].card_num[iter->first]+=iter->second;
                }

                ondesk_cards.clear();
                
            }
            else
            {
                for(auto iter=ondesk_cards.begin(); iter!=ondesk_cards.end(); iter++)
                {
                    sub[lastsub].card_num[iter->first]+=iter->second;
                }

                ondesk_cards.clear();
            }
        }


        //remedies
        nowsub=(nowsub+1)%4;
    }    

    
    for(int i=0; i<4; i++)
    {
        for(auto iter=sub[i].card_num.begin(); iter!=sub[i].card_num.end(); iter++)
        {
            while(iter->second>0)
            {
                cout<<iter->first<<" ";
                iter->second--;
            }
        }
        cout<<endl;
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
}
