#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) { // 字符串大小比较为逐个比较ascii码
    return a < b;
}

int main() {
    int m;
    cin >> m;
    vector<string> id(m), signIn(m), signOut(m);
    for(int i = 0; i < m; i++) 
        cin >> id[i] >> signIn[i] >> signOut[i];
    cout << id[min_element(signIn.begin(), signIn.end(), cmp) - signIn.begin()] << " ";
    cout << id[max_element(signOut.begin(), signOut.end(), cmp) - signOut.begin()];
    return 0;
}