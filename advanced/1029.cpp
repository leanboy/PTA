#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, t, mid;
    int i, j;
    cin >> n;
    vector<int> a1(n);
    for(i = 0; i < n; i++)
        cin >> a1[i];
    cin >> m;
    vector<int> a2(m);
    for(i = 0; i < m; i++)
        cin >> a2[i];
    t = (n + m - 1) / 2;
    i = 0, j = 0;
    while(i < n && j < m) { // 双指针
        if(i + j - 1 == t) break;
        mid = (a1[i] < a2[j]) ? a1[i++] : a2[j++];
    }
    if(i == n && i + j - 1 < t) mid = a2[t - n]; // 若一个数组已经遍历完
    if(j == m && i + j - 1 < t) mid = a1[t - m];
    cout << mid;
    return 0;
}