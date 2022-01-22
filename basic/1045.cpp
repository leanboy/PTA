#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sum = 0;
    int A[100000], B[100000];
    for(int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++) {
        int flag = 1;
        for(int j = 0; j < i; j++)
            if(A[j] > A[i]) {
                flag = 0;
                break;
            }
        if(flag) 
            for(int j = i + 1; j < N; j++)
                if(A[j] < A[i]) {
                    flag = 0;
                    break;
                }
        if(flag) 
            B[sum++] = A[i];
    }
    printf("%d\n", sum);
    sort(B, B + sum);
    for(int i = 0; i < sum; i++) {
        if(i != 0) printf(" ");
        printf("%d", B[i]);
    }
    return 0;
}