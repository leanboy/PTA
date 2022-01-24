/*
集装箱运输货物时，我们必须特别小心，不能把不相容的货物装在一只箱子里。比如氧化剂绝对不能跟易燃液体同箱，否则很容易造成爆炸。

本题给定一张不相容物品的清单，需要你检查每一张集装箱货品清单，判断它们是否能装在同一只箱子里。

输入格式：
输入第一行给出两个正整数：N (≤10^4) 是成对的不相容物品的对数；M (≤100) 是集装箱货品清单的单数。
随后数据分两大块给出。第一块有 N 行，每行给出一对不相容的物品。第二块有 M 行，每行给出一箱货物的清单，格式如下：
K G[1] G[2] ... G[K]
其中 K (≤1000) 是物品件数，G[i] 是物品的编号。简单起见，每件物品用一个 5 位数的编号代表。两个数字之间用空格分隔。

输出格式：
对每箱货物清单，判断是否可以安全运输。如果没有不相容物品，则在一行中输出 Yes，否则输出 No
*/
#include<iostream>
#include<unordered_map> // 时间性能比map更好
#include<vector>
using namespace std;

int main()
{
    int N, M, tmp1, tmp2, num;
    cin >> N >> M;
    unordered_map<int, vector<int>> m; // 整数到向量的映射
    for(int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        m[tmp1].push_back(tmp2);
        m[tmp2].push_back(tmp1);
    }
    while(M--) {
        cin >> num;
        vector<int> v;
        int flag = 0; // 是否存在不相容物品
        int a[100000] = {0};
        while(num--) {
            cin >> tmp1;
            v.push_back(tmp1);
            a[tmp1] = 1; // 标记集装箱出现过的物品，加速查找
        }
        for(int i = 0; i < v.size(); i++)
            for(int j = 0; j < m[v[i]].size(); j++) 
                if(a[m[v[i]][j]] == 1) flag = 1;
        printf("%s\n", flag ? "No" : "Yes");
    }
    return 0;
}