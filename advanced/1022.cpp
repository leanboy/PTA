#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main() {
    int m, n;
    string t1, t2;
    map<string, set<string>> info[5]; // 每种信息对应一个一条信息与对应id集合的映射
    cin >> n;
    while(n--) {
        cin >> t1;
        cin.ignore(); // 解决cin与getline的冲突
        getline(cin, t2);
        info[0][t2].insert(t1);
        getline(cin, t2);
        info[1][t2].insert(t1);
        while(cin >> t2) {
            info[2][t2].insert(t1);
            char c = getchar();
            if(c == '\n') break;
        }
        getline(cin, t2);
        info[3][t2].insert(t1);
        getline(cin, t2);
        info[4][t2].insert(t1);
    }
    cin >> m;
    cin.ignore();
    while(m--) {
        getline(cin, t1);
        int num = t1[0] - '1'; // 找到对应的信息
        t2 = t1.substr(3);
        if(info[num].find(t2) == info[num].end()) { // 判断信息是否存在
            cout << t1 << "\n" << "Not Found" << "\n";
        } else {
            cout << t1 << "\n";
            for(auto p : info[num][t2])
                cout << p << "\n";
        }
    }
    return 0;
}