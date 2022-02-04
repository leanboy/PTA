#include<iostream>
using namespace std;

int main() {
    int next[100000], n, first1, first2, addr, addr1, addr2, cnt1 = 0, cnt2 = 0;
    char c;
    cin >> first1 >> first2 >> n;
    while(n--) {
        cin >> addr1 >> c >> addr2;
        next[addr1] = addr2;
    }
    addr = first1;
    while(addr != -1) { // 计算两条链表的长度
        cnt1++;
        addr = next[addr];
    }
    addr = first2;
    while(addr != -1) {
        cnt2++;
        addr = next[addr];
    }
    if(cnt1 >= cnt2) { // 长的链表先走
        cnt1 -= cnt2;
        while(cnt1--) 
            first1 = next[first1];
    } else {
        cnt2 -= cnt1;
        while(cnt2--)
            first2 = next[first2];
    }
    while(first1 != -1) { // 一起走
        if(first1 == first2) break;
        first1 = next[first1];
        first2 = next[first2];
    }
    if(first1 == -1) printf("-1");
    else printf("%05d", first1);
    return 0;
}