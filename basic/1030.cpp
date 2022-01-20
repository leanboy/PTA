/*
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：
输入第一行给出两个正整数 N 和 p，其中 N（≤10^5）是输入的正整数的个数，p（≤10^9）是给定的参数。第二行给出 N 个正整数，每个数不超过 10^9。

输出格式：
在一行中输出最多可以选择多少个数可以用它们组成一个完美数列
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N, p;
    cin >> N >> p;
    long long A[100000]; // 测试点5，某些数可以达到10​^9*10^9=10^18, int范围不够
    for(int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    int a1 = 0, a2 = N - 1;
    while(A[a2] > A[a1] * p && a1 < a2) { // 双指针
        if(A[a2] / A[a1 + 1] < A[a2 - 1] / A[a1])
            a1++;
        else    
            a2--;
    }
    cout << a2 - a1 + 1;
    return 0;
}