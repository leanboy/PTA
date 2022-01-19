/*
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：
测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：
每个测试用例的输出占一行，输出倒序后的句子。
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> v1;
    string s;
    while(true) {
        cin >> s;
        v1.push_back(s);
        char c = getchar(); // 获取回车字符
        if(c == '\n') break; // 结束读取
    }    
    reverse(v1.begin(), v1.end());
    for(int i = 0; i < v1.size(); i++) {
        if(i != 0) 
            cout << " ";
        cout << v1[i];
    }
    return 0;
}