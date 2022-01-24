#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct stu
{
    string name;
    int Gp, Gm, Gn, G;
};

bool cmp(stu a, stu b) {
    return a.G != b.G ? a.G > b.G : a.name < b.name;
}

int main()
{
    int P, M, N, score, cnt = 1;
    string s;
    vector<stu> v, ret;
    map<string, int> m;
    cin >> P >> M >> N;
    for(int i = 0; i < P; i++) {
        cin >> s >> score;
        if(score >= 200) {
            v.push_back(stu{s, score, -1, 0, 0}); // 结构体赋值
            m[s] = cnt++; // map用来记录编程成绩合格的学生的位置，方便之后录入其他成绩的之后对应人名
        }
    }
    for(int i = 0; i < M; i++) {
        cin >> s >> score;
        if(m[s]) // key不存在返回0
            v[m[s] - 1].Gm = score;
    }
    for(int i = 0; i < N; i++) {
        cin >> s >> score;
        if(m[s]) {
            int tmp = m[s] - 1;
            v[tmp].Gn = v[tmp].G = score;
            if(v[tmp].Gm > v[tmp].Gn)
                v[tmp].G = int(0.4 * v[tmp].Gm + 0.6 * v[tmp].Gn + 0.5); // 加0.5为四舍五入
        }
    }
    for(auto Stu : v)
        if(Stu.G >= 60)
            ret.push_back(Stu); // 合格的放入另一个vector中
    sort(ret.begin(), ret.end(), cmp);
    for(auto Stu : ret)
        cout << Stu.name << " " << Stu.Gp << " " << Stu.Gm << " " << Stu.Gn << " " << Stu.G << "\n";
    return 0;
}