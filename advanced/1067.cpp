#include<iostream>
using namespace std;

int main() {
    int n, t, sum = 0, a[100000];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        a[t] = i; // 下标为元素，值为位置
    }
    for(int i = 1; i < n; i++) {
        if(a[i] != i) { // 元素不在对应位置上
            while(a[0] != 0) { // 不能成环
                swap(a[0], a[a[0]]); // 以0为中枢使部分元素放到对应的位置上
                sum++;
            }
            if(a[i] != i) {
                swap(a[i], a[0]); // 使0不在对应位置上
                sum++;
            }
        }
    }
    cout << sum;
    return 0;
}