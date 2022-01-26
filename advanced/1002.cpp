#include<iostream>
using namespace std;

int main() {
    double c[1001] = {0}; // 累加两个多项式的系数， 下标为指数
    int k1, k2, t;
    double num;
    cin >> k1;
    for(int i = 0; i < k1; i++) {
        cin >> t >> num;
        c[t] += num;
    }
    cin >> k2;
    for(int i = 0; i < k2; i++) {
        cin >> t >> num;
        c[t] += num;
    }
    int cnt = 0;
    for(int i = 0; i < 1001; i++)
        if(c[i]) cnt++; // 统计不为零的值
    printf("%d", cnt);
    for(int i = 1000; i >= 0; i--) 
        if(c[i]) printf(" %d %.1f", i, c[i]); // 输出一位小数，double输出可用f，输入用lf
    return 0;
}
