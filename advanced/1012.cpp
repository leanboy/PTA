#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main() {
    int n, m, tmp;
    cin >> n >> m;
    map<int, int[4]> info; // id和对应的成绩
    vector<int> score[4], check(m);
    string s = "ACME";
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        cin >> info[tmp][1] >> info[tmp][2] >> info[tmp][3];
        info[tmp][0] = (info[tmp][1] + info[tmp][2] + info[tmp][3]) / 3.0 + 0.5; // 四舍五入
        for(int j = 0; j < 4; j++)
            score[j].push_back(info[tmp][j]);
    }
    for(int i = 0; i < m; i++)
        cin >> check[i];
    for(int i = 0; i < 4; i++)
        sort(score[i].rbegin(), score[i].rend());
    for(int i = 0; i < m; i++) { // 遍历差分名单
        if(info.find(check[i]) == info.end()) {
            cout << "N/A" << "\n";
        } else {
            vector<int> v;
            for(int j = 0; j < 4; j++)  // 遍历4种成绩
                v.push_back(find(score[j].begin(), score[j].end(), info[check[i]][j]) - score[j].begin() + 1);
            auto it = min_element(v.begin(), v.end());
            cout << *it << " " << s[it - v.begin()] << "\n";
        }
    }
    return 0;
}