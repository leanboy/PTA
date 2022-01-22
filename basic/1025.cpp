/*
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：
Address Data Next
其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int first, k, n, temp;
    cin >> first >> n >> k;
    int data[100005], next[100005], list[100005]; // 下标为地址
    for (int i = 0; i < n; i++) {
        cin >> temp; // 地址
        cin >> data[temp] >> next[temp]; // 地址对应的数值与下地址
    }
    int sum = 0; // 可能有游离的结点
    while (first != -1) {
        list[sum++] = first; // list按从头到尾顺序记录地址
        first = next[first];
    }
    for (int i = 0; i < (sum - sum % k); i += k) // 末尾不足k个元素不反转
        reverse(list + i, list + i + k);
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]); // list[i + 1]即为下一个输出的元素的地址
    printf("%05d %d -1", list[sum - 1], data[list[sum - 1]]);
    return 0;
}