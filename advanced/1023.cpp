#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    string num, num2;
    map<char, int> m, m2; // 可直接用数组存储
    int c = 0, n;
    cin >> num;
    for(auto c : num) 
        m[c]++;
    for(int i = num.size() - 1; i >= 0; i--) {  
        n = ((num[i] - '0') * 2 + c) % 10;
        c = ((num[i] - '0') * 2 + c) / 10;
        num2 += to_string(n);
    }
    if(c) num2 += '1';
    reverse(num2.begin(), num2.end());
    for(auto c : num2) 
        m2[c]++;
    printf("%s\n", m == m2 ? "Yes" : "No");
    cout << num2;
    return 0;
}