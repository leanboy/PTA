/*
“单身狗”是中文对于单身人士的一种爱称。本题请你从上万人的大型派对中找出落单的客人，以便给予特殊关爱。

输入格式：
输入第一行给出一个正整数 N（≤ 50000），是已知夫妻/伴侣的对数；随后 N 行，每行给出一对夫妻/伴侣——为方便起见，每人对应一个 ID 号，为 5 位数字（从 00000 到 99999），ID 间以空格分隔；之后给出一个正整数 M（≤ 10 000），为参加派对的总人数；随后一行给出这 M 位客人的 ID，以空格分隔。题目保证无人重婚或脚踩两条船。

输出格式：
首先第一行输出落单客人的总人数；随后第二行按 ID 递增顺序列出落单的客人。ID 间用 1 个空格分隔，行的首尾不得有多余空格。
*/
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    int N, M;
    int a, b;
    cin >> N;
    vector<int> couple(100000, -1);
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        couple[a] = b; // 对应伴侣的值
        couple[b] = a;
    }
    cin >> M;
    vector<int> guest(M), isExist(100000); // 默认初始化为0, isExist为伴侣是否存在
    for(int i = 0; i < M; i++) {
        cin >> guest[i];
        if(couple[guest[i]] !=  -1)
            isExist[couple[guest[i]]] = 1; // 伴侣的伴侣即本人到场
    }
    set<int> dog; // set默认从大到小排序
    for(int i = 0; i < M; i++)
        if(!isExist[guest[i]]) // 伴侣未到场
            dog.insert(guest[i]);
    printf("%d\n", dog.size());
    for(auto it = dog.begin(); it != dog.end(); it++) {
        if(it != dog.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}