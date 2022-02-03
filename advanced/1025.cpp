#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct stu {
    long long id;
    int score, f_rank, location, l_rank;
};

bool cmp(stu a, stu b) {
    if(a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

int main() {
    int n, m, grade;
    vector<stu> v;
    long long t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        vector<stu> v2;
        for(int j = 0; j < m; j++) {
            scanf("%lld %d", &t, &grade);
            v2.push_back(stu{t, grade, 0, i + 1, 0});
        }
        sort(v2.begin(), v2.end(), cmp);
        v2[0].l_rank = 1;
        for(int k = 1; k < m; k++)
            v2[k].l_rank = (v2[k].score == v2[k - 1].score) ? v2[k-1].l_rank : (k + 1); // 生成排序号，不能一个个寻找，太慢
        v.insert(v.begin(), v2.begin(), v2.end()); // 插入总的向量里
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.size() << "\n";
    v[0].f_rank = 1;
    for(vector<stu>::size_type k = 1; k < v.size(); k++) 
        v[k].f_rank = (v[k].score == v[k - 1].score) ? v[k - 1].f_rank : (k + 1);
    for(auto p : v)
        printf("%013lld %d %d %d\n", p.id, p.f_rank, p.location, p.l_rank); // 注册号为13位
    return 0;
}