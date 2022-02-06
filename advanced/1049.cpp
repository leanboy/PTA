#include<iostream>
using namespace std;

int main() {
    int n, left, right, a = 1, now, sum = 0; // now为当前位数字
    cin >> n;
    while(n / a) { // 保证当前位数字取1的时候不超过n
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) sum += left * a;
        else if(now == 1) sum += left * a + right + 1;
        else sum += (left + 1) * a;
        a = a * 10;
    }    
    cout << sum;
    return 0;
}