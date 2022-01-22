/*
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：
输入只有一行，包含一个字符串，长度不超过10^5，只包含 P、A、T 三种字母。

输出格式：
在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。
*/
#include <iostream>
#define Mod 1000000007
using namespace std;

int main()
{
    string s;
    cin >> s;
    int P = 0, T = 0;
    long long sum = 0;
    for(auto x : s)
        if (x == 'T')
            T++; //遍历一次字符串，计算'T'总共的数量
    for(auto x : s)
    {
        if(x == 'P')
            P++; //P表示'A'前'P'的数量
        if(x == 'T')
            T--; //表示'A'后面的'T'的数量。
        if(x == 'A')
            sum = (sum + P * T) % Mod; // 每次都取余，防止溢出
    }
    cout << sum;
    return 0;
}
