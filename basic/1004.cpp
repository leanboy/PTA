// 读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
#include <iostream>
#include <string>
using namespace std;

struct Student  //定义结构体
{
    string name, id;
    int score;
};


int main(){
    Student s , max{"","",0} , min{"","",100}; // 以max、min两个结构体存储最大、最小值
    int n = ;
    cin >> n; 
    while(n--){  //首先判断num的值，当大于零时进入循环，并且num自减1,当num=0时跳出
        cin >> s.name >> s.id >> s.score;  //cin会以空格和回车分割
        max = s.score > max.score ? s : max;  //判断最大值，若大于当前max，则将当前s复制给max
        min = s.score < min.score ? s : min;

    }
    cout << max.name << " " << max.id << endl;
    cout << min.name << " " << min.id << endl;
    return 0;
}