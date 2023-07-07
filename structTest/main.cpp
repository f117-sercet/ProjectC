#include <iostream>
using namespace std;

/**
 * sruct 结构体名
{
 类型1 数据对象1;
类型2 数据对象2;
类型3 数据对象3;
    …
};

 * @return
 */

struct studentInfo{
    string name;
    int age;
    double score;
} stu1,stu2{"小明",1,75};
enum week{ Mon, Tue, Wed, Thu, Fri, Sat, Sun};
int main() {


    // 结构体初始化
    studentInfo stu3 ={"小王",22,87};
    cout << "学生姓名：" << stu3.name << "\t年龄：" << stu3.age << "\t成绩：" << stu3.score << endl;

    return 0;

    week w1 = Mon;
    week w2 = Tue;
    //week w3 = 2;    // 错误，类型不匹配
    week w3 = week(3);    // int类型强转为week类型后赋值

    /**
     * ?	默认情况下，会将整数值赋给枚举量
     * ?	枚举量默认从0开始，每个枚举量依次加1；所以上面week枚举类型中，一周七天枚举量分别对应着0~6的常量值
     * ?	可以通过对枚举量赋值，显式地设置每个枚举量的值
     * ?	如果直接用一个整型值对枚举类型赋值，将会报错，因为类型不匹配；
     * ?	可以通过强制类型转换，将一个整型值赋值给枚举对象；
     * ?	最初的枚举类型只有列出的值是有效的；而现在C++通过强制类型转换，允许扩大枚举类型合法值的范围。不过一般使用枚举类型要避免直接强转赋值。
     */

}
