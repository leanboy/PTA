#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, tmp, res = 0;
    cin >> n >> m;
    vector<int> fav(n+1, 0);
    for(int i = 0; i < m; i++) { // 记录喜欢颜色的位置，不喜欢为0
        cin >> tmp;
        fav[tmp] = i + 1;
    }
    cin >> m;
    vector<int> a;
    while(m--) { // 转化为最长不递减子序列的问题
        cin >> tmp;
        if(fav[tmp]) a.push_back(fav[tmp]);
    }
    int len = (int)a.size();
    vector<int> dp(len, 1); // 初始化为1
    for(int i = 0; i < len; i++) { // 考虑res == 1的情况，i不能设为1
        for(int j = 0; j < i; j++)
            if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}