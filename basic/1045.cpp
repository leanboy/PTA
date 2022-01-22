#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    int max = 0;
    int A[100000], B[100000], C[100000];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        B[i] = A[i]; // A的副本
    }
    sort(A, A + N); // 排序
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i] && max < B[i]) // B[i]位置不变且之前数的最大值小于B[i]
            C[sum++] = B[i];
        max = max > B[i] ? max : B[i];
    }
    printf("%d\n", sum);
    for(int i = 0; i < sum; i++) {
        if(i != 0) printf(" ");
        printf("%d", C[i]);
    }
    printf("\n");
    return 0;
}