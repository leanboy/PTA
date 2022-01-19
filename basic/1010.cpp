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