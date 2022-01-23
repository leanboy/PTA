/*
本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m−n 取所有可能值中的最小值。

输入格式：
输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10^4，相邻数字以空格分隔。

输出格式：
输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int m, n;
    int A[10000];
    int i, j;
    for(i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N); // 默认从小到大排序
    for(i = 1; i <= sqrt(N); i++)
        if(N % i == 0)
            n = i;
    m = N / n;
    vector<vector<int>> B(m, vector<int>(n)); // 二维向量，占用更少内存
    // static int B[10000][10000]; // 防止栈溢出，栈只有2M
    i = 0, j = 0;
    int nl = 0, nh = n, ml = 0, mh = m; // 行列的最大最小值
    int flag = 1; // 维护4种状态
    B[i][j] = A[--N];
    while(N) {
        if(flag == 1) 
            if(j < nh) j++;
            else {
                j--; // 抵消上一步超出范围的影响
                flag = 2;
                ml++;
                continue;
            }
        else if(flag == 2)
            if(i < mh) i++;
            else {
                i--;
                flag = 3;
                nh--;
                continue;
            }
        else if(flag == 3)
            if(j >= nl) j--;
            else {
                j++;
                flag = 4;
                mh--;
                continue;
            }
        else
            if(i >= ml) i--;
            else {
                i++;
                flag = 1;
                nl++;
                continue;
            }
        if(i >= ml && i < mh && j >= nl && j < nh) B[i][j] = A[--N];
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(j != 0) printf(" ");
            printf("%d", B[i][j]);
        }
        printf("\n");
    }
    return 0;
}