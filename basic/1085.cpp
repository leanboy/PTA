/*
输入格式：
输入第一行给出一个正整数 N（≤10^5），即考生人数。随后 N 行，每行按下列格式给出一个考生的信息：

准考证号 得分 学校
其中准考证号是由 6 个字符组成的字符串，其首字母表示考试的级别：B代表乙级，A代表甲级，T代表顶级；得分是 [0, 100] 区间内的整数；学校是由不超过 6 个英文字母组成的单位码（大小写无关）。注意：题目保证每个考生的准考证号是不同的。

输出格式：
首先在一行中输出单位个数。随后按以下格式非降序输出单位的排行榜：

排名 学校 加权总分 考生人数
其中排名是该单位的排名（从 1 开始）；学校是全部按小写字母输出的单位码；加权总分定义为乙级总分/1.5 + 甲级总分 + 顶级总分*1.5的整数部分；考生人数是该属于单位的考生的总人数。

学校首先按加权总分排行。如有并列，则应对应相同的排名，并按考生人数升序输出。如果仍然并列，则按单位码的字典序输出。
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Sch 
{
    string name;
    double avg;
    int sum, num;
};

bool cmp(Sch a, Sch b) {
    if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.num != b.num) return a.num < b.num;
    return a.name < b.name;
}

int main()
{
    int N, cnt = 1;
    double score;
    cin >> N;
    string id, sch;
    map<string, int> idx;
    vector<Sch> v;
    for(int i = 0; i < N; i++) {
        cin >> id >> score >> sch;
        for(auto &c : sch) // 每个字符化为小写
            c = tolower(c);
        if(idx[sch] == 0) {
            idx[sch] = cnt++;
            if(id[0] == 'B') v.push_back(Sch{sch, score / 1.5, 0, 1});
            else if(id[0] == 'A') v.push_back(Sch{sch, score, 0, 1});
            else v.push_back(Sch{sch, score * 1.5, 0, 1});
        }
        else {
            int tmp = idx[sch] - 1;
            if(id[0] == 'B')
                v[tmp].avg += score / 1.5;
            else if(id[0] == 'A')
                v[tmp].avg += score;
            else
                v[tmp].avg += score * 1.5;
            v[tmp].num++;
        }
    }
    for(auto &p : v) // double转int
        p.sum = (int)p.avg;
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", cnt - 1);
    int rank = 0, pre = -1;
    for(int i = 0; i < v.size(); i++) {
        if(pre != v[i].sum)
            rank = i + 1;
        pre = v[i].sum;
        printf("%d %s %d %d\n", rank, v[i].name.c_str(), v[i].sum, v[i].num);
    }
    return 0;
}