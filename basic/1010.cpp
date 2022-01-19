/*
输入格式:
以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:
以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0。
*/
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    bool first = true; // 判断开头是否输入空格，以及多项式是否是常数
    while (cin >> a >> b)
    {
        if (b != 0)
        {
            if (first)
            {
                printf("%d %d", a * b, b - 1);
                first = false;
            }
            else
                printf(" %d %d", a * b, b - 1);
        }
        char c = getchar();
        if (c == '\n') break;
    }
    if (first) // 多项式是常数
        cout << "0 0";
    return 0;
}