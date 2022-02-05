#include<iostream>
#include<algorithm>
using namespace std;

struct gasStation{
    double p, d;
};

bool cmp(gasStation b, gasStation c) {
    return b.d < c.d;
}

int main() {
    double cMax, d, dAvg, curP, x = 0, cost = 0, gas = 0, minP;
    int n, i, tmp, mint, flag = 1;
    gasStation a[501]; // 终点也算一站
    cin >> cMax >> d >> dAvg >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i].p >> a[i].d;
    a[n].d = d, a[n].p = 0.0; // 终点赋值
    sort(a, a + n, cmp);
    if(a[0].d != 0.0) { // 起点无加油站
        printf("The maximum travel distance = 0.00");
        flag = 0;
    }
    i = 0;
    while(i < n && flag) {
        curP = a[i].p; // 当前油价
        x = a[i].d; // 当前位置
        tmp = i + 1; // 向前走
        minP = a[tmp].p; // 记录最低的油价
        mint = tmp;
        while(a[tmp].d - x <= cMax * dAvg) { // 能开到的站
            if(a[tmp].p <= minP) { 
                minP = a[tmp].p;
                mint = tmp;
            }
            if(a[tmp].p <= curP) { // 存在油价更低的站
                cost += ((a[tmp].d - x) / dAvg - gas) * curP;
                i = tmp;
                gas = 0; // 只需加油加到够开到下一个站
                break;
            } else {
                tmp++;
            }
        }
        if(a[tmp].d - x > cMax * dAvg) { // 最大公里数内没有更低的油价
            if(tmp - 1 == i) { // 走不到下一个站
                printf("The maximum travel distance = %.2f", x + cMax * dAvg);
                flag = 0;
                break;
            }
            cost += (cMax - gas) * curP;
            gas = cMax - (a[mint].d - x) / dAvg; 
            i = mint; // 去油价最低的站
        }
    }
    if(flag) printf("%.2f", cost);
    return 0;
}