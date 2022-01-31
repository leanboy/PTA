#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int id, best;
    int score[4], rank[4];
}stu[2005];

int exist[1000000], flag = -1; // 全局变量，便于cmp进行调用

bool cmp(node a, node b) { // 对4种成绩进行排序
    return a.score[flag] > b.score[flag];
}

int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++) {
        sort(stu, stu + n, cmp);
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) { // 计算排位
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i - 1].score[flag])
                stu[i].rank[flag] = stu[i - 1].rank[flag];
        }
    }
    for(int i = 0; i < n; i++) {
        exist[stu[i].id] = i + 1; // 全部加1，若为0则不存在
        stu[i].best = min_element(stu[i].rank, stu[i].rank + 4) - stu[i].rank;
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = exist[id];
        if(temp) {
            int best = stu[temp - 1].best;
            printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}