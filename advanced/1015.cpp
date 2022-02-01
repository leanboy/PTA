#include<iostream>
using namespace std;

bool isPrime(int a) {
    for(int i = 2; i * i <= a; i++) // 判断是否是素数
        if(a % i == 0) return false;
    if(a != 1) return true;
    return false;
}

int reverseR(int n, int d) {
    int len = 0, a[100];
    do{
        a[len++] = n % d;
        n /= d;
    }while(n);
    for(int i = 0; i < len; i++) 
        n = n * d + a[i]; // 反转
    return n;
}

int main() {
    int n, d;
    while(true) {
        cin >> n;
        if(n < 0) break;
        cin >> d;
        if(isPrime(n) && isPrime(reverseR(n, d)))
            cout << "Yes" << "\n";
        else    
            cout << "No" << "\n";
    }
    return 0;
}