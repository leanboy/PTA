/*
得到“答案正确”的条件是：
字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    while(n--) { // 逐个判断字符
        int len, pp, pt; // 字符串长度、P位置、T位置
        int cp = 0, ct = 0; // P个数、T个数
        int err = 0; // 错误标志
        cin >> s;
        len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] == 'P') {
                cp++;
                pp = i;
            }
            else if(s[i] == 'T') {
                ct++;
                pt = i;
            }
            else if(s[i] != 'A') {
                err++;
            }
        } 
        // 先判断大条件
        if(err || ct != 1 || cp != 1 || pt - pp <= 1) {
            cout << "NO" << endl;
            continue;
        }
        int x = pp, y = pt - pp -1, z = len - pt -1; // 前、中、后A的数量
        if(x * y == z) {
            cout << "YES" << endl;
            continue;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}