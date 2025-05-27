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

#define int long long
#define INF 1e18
#define endl '\n'
#define MOD (int)(1000000007)

using namespace std;

int l, c, p;
vector<string> modestr;
string txtstr;

int ans[200005] = {0};
int val[200005];
int indu[200005];

struct Node
{

    int thisch;
    int nextch[26] = {0};
    int fail = 1;
    vector<int> endnum;
};

vector<Node> trie;
int tot = 1;
void insert(string &s, int index)
{
    int nownode = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int nowch = s[i] - 'a';
        Node tmpnode;
        if (trie[nownode].nextch[nowch] == 0)
        {
            tmpnode.fail = 1;
            tmpnode.thisch = nowch;
            trie.push_back(tmpnode);

            tot++;
            trie[nownode].nextch[nowch] = tot;
            nownode = trie[nownode].nextch[nowch];
        }
        else
        {
            nownode = trie[nownode].nextch[nowch];
        }

        if (i == s.size() - 1)
        {
            trie[nownode].endnum.push_back(index);
        }
    }
}

void bfs()
{
    for (int i = 0; i < 26; i++)
    {
        trie[0].nextch[i] = 1;
    }
    queue<int> q;
    q.push(1);
    trie[1].fail = 0;
    while (!q.empty())
    {
        int nownode = q.front();
        int nowfail = trie[nownode].fail;
        q.pop();
        map<int, int> ok;
        for (int i = 0; i < 26; i++)
        {
            int nextnode = trie[nownode].nextch[i];
            if (nextnode == 0)
            {
                trie[nownode].nextch[i] = trie[nowfail].nextch[i];
                continue;
            }
            trie[nextnode].fail = trie[nowfail].nextch[i];
            if (ok[trie[nowfail].nextch[i]] == 0)
            {
                ok[trie[nowfail].nextch[i]] = 1;
                indu[trie[nowfail].nextch[i]]++;
            }

            q.push(nextnode);
        }
    }
}

void query(string &s)
{
    int nownode = 1;
    for (int i = 0; i < s.size(); i++)
    {
        int nowch = s[i] - 'a';
        int nextnode = trie[nownode].nextch[nowch];
        val[nextnode]++;

        nownode = nextnode;
    }
}

void kopu()
{

    queue<int> q;
    for (int i = 1; i <= tot; i++)
    {
        if (indu[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int nownode = q.front();
        q.pop();
        for (int i = 0; i < trie[nownode].endnum.size(); i++)
        {
            int nowindex = trie[nownode].endnum[i];
            ans[nowindex] += val[nownode];
        }
        int nextnode = trie[nownode].fail;
        val[nextnode] += val[nownode];
        indu[nextnode]--;
        if (indu[nextnode] == 0)
        {
            q.push(nextnode);
        }
    }
}

void solve()
{
    cin >> l >> c >> p;
    modestr = vector<string>(l + 1);
    trie = vector<Node>(2);

    for (int i = 1; i <= l; i++)
    {
        cin >> modestr[i];
        insert(modestr[i], i);
    }

    bfs();
    for (int i = 1; i <= l; i++)
    {
        query(modestr[i]);
    }
    kopu();
    for (int i = 1; i <= l; i++)
    {
        cout << ans[i] << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}