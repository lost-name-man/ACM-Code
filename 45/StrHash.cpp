#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 使用 long long 类型以防止溢出，避免使用模数
// 如果字符串较长或需要多个哈希，建议加上大质数模数
typedef long long ll;

const int MAXN = 100005; // 字符串最大长度
const ll P = 131;        // 哈希基数，通常选择大于字符集大小的质数

ll p[MAXN]; // 存储 P 的幂次方
ll h[MAXN]; // 存储前缀哈希值

// 初始化哈希表
// s: 待处理的字符串
// n: 字符串长度
void init_hash(const string& s, int n) {
    p[0] = 1;
    h[0] = s[0];
    for (int i = 1; i < n; ++i) {
        // 计算 P^i
        p[i] = p[i - 1] * P;
        // 计算前缀哈希值
        h[i] = h[i - 1] * P + s[i];
    }
}

// 获取子串哈希值
// l: 子串起始索引 (0-based)
// r: 子串结束索引 (0-based)
ll get_hash(int l, int r) {
    if (l == 0) {
        return h[r];
    }
    // 使用前缀哈希差分计算子串哈希
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    string s;
    cout << "请输入一个字符串: ";
    cin >> s;
    int n = s.length();

    // 初始化
    init_hash(s, n);

    // 示例：查询子串哈希值
    // 查询 s[1..3] ("bcd") 的哈希值
    int l = 1, r = 3;
    ll sub_hash = get_hash(l, r);
    cout << "子串 s[" << l << ".." << r << "] 的哈希值为: " << sub_hash << endl;
    
    // 示例：判断两个子串是否相等
    // 查询 s[0..2] ("abc") 和 s[3..5] ("def")
    ll hash1 = get_hash(0, 2);
    ll hash2 = get_hash(3, 5);
    
    if (hash1 == hash2) {
        cout << "子串 s[0..2] 和 s[3..5] 相等" << endl;
    } else {
        cout << "子串 s[0..2] 和 s[3..5] 不相等" << endl;
    }

    return 0;
}