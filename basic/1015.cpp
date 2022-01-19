/*
输入格式：
输入第一行给出 3 个正整数，分别为：N（≤10^5），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student
{
    int ID, D, C;
};

bool cmp(student s1, student s2) { // 排序算法，根据不同优先级进行分类
    if (s1.D + s1.C != s2.D + s2.C) 
        return (s1.D + s1.C) > (s2.D + s2.C); // 降序
    else if(s1.D != s2.D)
        return s1.D > s2.D; // 降序
    return s1.ID < s2.ID; // 升序
}

int main()
{
    int N, L, H;
    int id, d, c;
    cin >> N >> L >> H;
    int sum = N;
    vector<student> vec[4]; // 四个等级数组
    while(N--) {
        cin >> id >> d >> c;
        student s = {id, d, c}; // 结构体赋值
        if(d >= H && c >= H) 
            vec[0].push_back(s);
        else if(d >= H && c >= L)
            vec[1].push_back(s);
        else if(d >= L && c >= L && d >= c)
            vec[2].push_back(s);
        else if(d >= L && c >= L)
            vec[3].push_back(s);
        else
            sum--;
    }   
    cout << sum << "\n";
    for(int i = 0 ;i < 4; i++) {
        sort(vec[i].begin(), vec[i].end(), cmp); // 各个等级排序
        for(student s : vec[i])
            cout << s.ID << " " << s.D << " " << s.C << "\n"; // endl比\n慢很多，数据多时用"\n"
    }
    return 0;
}