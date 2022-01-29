#include<iostream>
#include<map>
using namespace std;

int main() {
    int k1, k2, n, sum = 0;
    double an;
    map<int, double> m1, m2, m3;
    cin >> k1;
    for(int i = 0; i < k1; i++) {
        cin >> n >> an;
        m1[n] = an;
    }
    cin >> k2;
    for(int i = 0; i < k2; i++) {
        cin >> n >> an;
        m2[n] = an;
    }
    for(auto p1 : m1) 
        for(auto p2 : m2) 
            m3[p1.first + p2.first] += p1.second * p2.second;
    for(auto p : m3)
        if(p.second) sum++;
    cout << sum;
    for(auto it = m3.rbegin(); it != m3.rend(); it++) // 此时auto为reverse_iterator，反向遍历
        if(it->second)
            printf(" %d %.1f", it->first, it->second);
    return 0;
}