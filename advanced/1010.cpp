#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert(string n, long long radix) { // 化为10进制
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}

long long find_radix(string n, long long num) {
    char c = *max_element(n.begin(), n.end());
    long long low = (isdigit(c) ? c - '0': c - 'a' + 10) + 1; // 基数下限
    long long high = max(num, low); // 基数上限
    while (low <= high) { // 二分法
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1; // 溢出判断
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main() {
    string n1, n2;
    long long tag, radix, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }   
    return 0;
}