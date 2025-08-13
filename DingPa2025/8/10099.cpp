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
const int INF = 1e9;
const int MOD = 11380;

// inline __int128 read()
// {
//     __int128 x = 0, f = 1;
//     char ch = getchar();

//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }

//     while (ch >= '0' && ch <= '9')
//     {
//         x = x * 10 + ch - '0';
//         ch = getchar();
//     }

//     return x * f;
// }

// inline void prints(__int128 x)
// {
//     if (x < 0)
//     {
//         putchar('-');
//         x = -x;
//     }
//     if (x > 9)
//     {
//         prints(x / 10);
//     }
//     putchar(x % 10 + '0');
// }


constexpr int LEN = 1004;



void clear(int a[]) {
  for (int i = 0; i < LEN; ++i) a[i] = 0;
}

void read(int a[]) {
  static char s[LEN + 1];
  scanf("%s", s);

  clear(a);

  int len = strlen(s);
  for (int i = 0; i < len; ++i) a[len - i - 1] = s[i] - '0';
}

void print(int a[]) {
  int i;
  for (i = LEN - 1; i >= 1; --i)
    if (a[i] != 0) break;
  for (; i >= 0; --i) putchar(a[i] + '0');
  putchar('\n');
}

void add(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    c[i] += a[i] + b[i];
    if (c[i] >= 10) {
      c[i + 1] += 1;
      c[i] -= 10;
    }
  }
}

void sub(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    c[i] += a[i] - b[i];
    if (c[i] < 0) {
      c[i + 1] -= 1;
      c[i] += 10;
    }
  }
}

void mul(int a[], int b[], int c[]) {
  clear(c);

  for (int i = 0; i < LEN - 1; ++i) {
    for (int j = 0; j <= i; ++j) c[i] += a[j] * b[i - j];

    if (c[i] >= 10) {
      c[i + 1] += c[i] / 10;
      c[i] %= 10;
    }
  }
}

bool greater_eq(int a[], int b[], int last_dg, int len) {
  if (a[last_dg + len] != 0) return true;
  for (int i = len - 1; i >= 0; --i) {
    if (a[last_dg + i] > b[i]) return true;
    if (a[last_dg + i] < b[i]) return false;
  }
  return true;
}

void div(int a[], int b[], int c[], int d[]) {
  clear(c);
  clear(d);

  int la, lb;
  for (la = LEN - 1; la > 0; --la)
    if (a[la - 1] != 0) break;
  for (lb = LEN - 1; lb > 0; --lb)
    if (b[lb - 1] != 0) break;
  if (lb == 0) {
    puts("> <");
    return;
  }

  for (int i = 0; i < la; ++i) d[i] = a[i];
  for (int i = la - lb; i >= 0; --i) {
    while (greater_eq(d, b, i, lb)) {
      for (int j = 0; j < lb; ++j) {
        d[i + j] -= b[j];
        if (d[i + j] < 0) {
          d[i + j + 1] -= 1;
          d[i + j] += 10;
        }
      }
      c[i] += 1;
    }
  }
}



int query(int l, int r, int turn, int times)
{
    int len = (r - l + 1);
    int a = (l + r);
    int re = 0;

    re += (times * turn + times * (times - 1) / 2) * (a * len / 2);
    re += (times) * (times - 1) / 2 * (len * len) * turn;

    int x = times - 1;
    re += (x * (x + 1) * (2 * x + 1) / 6) * (len * len);
    return re;
}


int tlechecker=0;

void solve()
{
    int n[LEN], w[LEN];



    if (w == 1)
    {
        prints((n * (n + 1)) / 2);
        printf("\n");
        return;
    }

    int copyn = n;
    int turn = 1;
    int ans = 0;

    int l = 1, r;

    
    while (1)
    {
        if (copyn < w)
        {
            break;
        }

        if (w * w >= copyn)
        {
            int unitlen = copyn / w;
            int len = copyn % w + 1;

            int times = ceil(len * 1.0 / unitlen * 1.0);
            copyn -= times * unitlen;

            r = l + unitlen - 1;
            int tmpans;
            tmpans = query(l, r, turn, times);
            ans += tmpans;
            l += times * unitlen;
            turn += times;
        }
        else
        {
            int unitlen = copyn / w;
            r = l + unitlen - 1;
            ans += turn * (l + r) * unitlen / 2;
            copyn -= unitlen;
            l += unitlen;
            turn++;
        }

        tlechecker++;
        if(tlechecker>1e8)
        {
            break;
        }

    }

    if (l <= n)
    {
        r = n;
        int len = r - l + 1;
        ans += turn * ((r + l) * (len)) / 2;
    }

    prints(ans);
    printf("\n");
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