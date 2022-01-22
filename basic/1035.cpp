/*
根据维基百科的定义：插入排序是迭代算法，逐一获得输入数据，逐步产生有序的输出序列。每步迭代中，算法从输入序列中取出一元素，将之插入有序序列中正确的位置。如此迭代直到全部元素有序。
归并排序进行如下迭代操作：首先将原始序列看成N个只包含1个元素的有序子序列，然后每次迭代归并两个相邻的有序子序列，直到最后只剩下1个有序的序列。
现给定原始序列和由某排序算法产生的中间序列，请你判断该算法究竟是哪种排序算法？
输入格式：

输入在第一行给出正整数N (<=100)；随后一行给出原始序列的N个整数；最后一行给出由某排序算法产生的中间序列。这里假设排序的目标序列是升序。数字间以空格分隔。

输出格式：

首先在第1行中输出“Insertion Sort”表示插入排序、或“Merge Sort”表示归并排序；然后在第2行中输出用该排序算法再迭代一轮的结果序列。题目保证每组测试的结果是唯一的。数字间以空格分隔，且行末不得有多余空格。
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, A[100], B[100], i, j;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
        cin >> B[i];
    for(i = 0; i < N - 1 && B[i] <= B[i + 1]; i++); // 由于测试结果唯一，只需找到以一个乱序的位置
    for(j = i + 1; A[j] == B[j] && j < N; j++); // 之后的两数组值相等则为插入排序
    if(j == N) {
        cout << "Insertion Sort" << endl;
        sort(A, A + i + 2); // 再进行一轮排序
    } 
    else{
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while(flag) { // flag = 1两数组值不相等
            flag = 0;
            for(i = 0; i < N; i++) {
                if(A[i] != B[i])
                    flag = 1;
            }
            k = k * 2; // 归并排序的间隔
            for(i = 0; i < N / k; i++) // 进行一轮归并排序
                sort(A + i * k, A + (i + 1) * k);
            sort(A + N / k * k, A + N); // 对最后长度不足k的值进行排序
        }
    }
    for(j = 0; j < N; j++) {
        if(j != 0) printf(" ");
        printf("%d", A[j]);
    }
    return 0;
}