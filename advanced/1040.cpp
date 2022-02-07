#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int len = (int)s.size(), ans = 1;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1; // 长度为1的子串初始化
        if(i < len - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1; // 长度为2的子串初始化
            ans = 2;
        }
    }
    for(int L = 3; L <= len; L++) { // 按照子串的长度递增的次序遍历，避免状态无法转移
        for(int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) { // s[i]~s[j]是否是回文串的状态转移方程
                dp[i][j] = 1;
                ans = L; // 更新最大长度
            }
        }
    }
    cout << ans;
    return 0;
}