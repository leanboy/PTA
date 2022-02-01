#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> s, t; // 不能用string保存，因为进制可能大于9
    while(n) {
        s.push_back(n % b);
        n /= b; 
    }
    t = s;
    reverse(t.begin(), t.end());
    if(t == s) cout << "Yes" << endl;
    else cout << "No" << endl;
    for(int i = 0; i < t.size(); i++) {
        if(i != 0) cout << " ";
        cout << t[i];
    }
    return 0;
}