#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), f(n), b(n); // f[i]储存以i结尾的maxSum，b[i]储存其对应的开头位置
    for(int i = 0; i < n; i++)
        cin >> a[i];
    f[0] = a[0], b[0] = 0;
    for(int i = 1; i < n; i++) {
        f[i] = a[i] + (f[i - 1] >= 0 ? f[i - 1] : 0);
        b[i] = f[i - 1] >= 0 ? b[i - 1] : i; // 等号保证开头位置最小
    }
    int maxSum = *max_element(f.begin(), f.end());
    int t = max_element(f.begin(), f.end()) - f.begin();
    if(maxSum >= 0)
        cout << maxSum << " " << a[b[t]] << " " << a[t];
    else 
        cout << 0 << " " << a[0] << " " << a[n - 1];
    return 0;
}