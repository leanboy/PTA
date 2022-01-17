/*
读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：
每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10^100。

输出格式：
在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int sum = 0;
    string pingying[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    cin >> s; // 数太大，输入字符串
    for(int i = 0; i < int(s.size()); i++)
        sum += stoi(s.substr(i, 1)); // 字符串转数字
    string sum_str = to_string(sum); // 数字转字符串
    for(int i = 0; i < int(sum_str.size()); i++){
        if(i != 0)
            cout << ' ';
        cout << pingying[sum_str[i] - '0']; // ascii码运算
    }
    return 0;
}