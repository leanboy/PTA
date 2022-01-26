/*
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10^6≤a,b≤10^6 . The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string c = to_string(a + b);
    int len = c.size();
    for(int i = 0; i < len; i++) {
        cout << c[i];
        if(c[i] == '-') continue; // 符号位跳过
        if((i + 1) % 3 == len % 3 && i != len - 1) cout << ","; // 满足隔三位的规律且不在最后则输出句号
    }
    return 0;
}