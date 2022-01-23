/*
英国天文学家爱丁顿很喜欢骑车。据说他为了炫耀自己的骑车功力，还定义了一个“爱丁顿数” E ，即满足有 E 天骑车超过 E 英里的最大整数 E。据说爱丁顿自己的 E 等于87。

现给定某人 N 天的骑车距离，请你算出对应的爱丁顿数 E（≤N）。

输入格式：
输入第一行给出一个正整数 N (≤10^5)，即连续骑车的天数；第二行给出 N 个非负整数，代表每天的骑车距离。

输出格式：
在一行中给出 N 天的爱丁顿数
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int &a : A)
        cin >> a;
    sort(A.rbegin(), A.rend());
    int m = 0;
    for(int i = 0; i < N; i++) {
        if(i + 1 < A[i]) m = min(i + 1, A[i]);
        else break;
    }
    cout << m;
    return 0;
}