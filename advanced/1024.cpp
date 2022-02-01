#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string stringAdd(string a, string b) {
    string s;
    int m, c = 0; // c为进位
    for(int i = a.size() - 1; i >= 0; i--) {
        m = (a[i] - '0' + b[i] - '0' + c) % 10; // 加和
        c = (a[i] - '0' + b[i] - '0' + c) / 10; // 计算进位
        s += to_string(m);
    }
    if(c) s += '1';
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string n, m;
    int k, cnt = 0;
    cin >> n >> k;
    while(k--) {
        m = n;
        reverse(m.begin(), m.end());
        if(m == n || k == -1) break;
        n = stringAdd(m, n); // 不能先算加和，考虑到本身就是回文数的情况
        cnt++;
    }
    cout << n << "\n" << cnt;
    return 0;
}