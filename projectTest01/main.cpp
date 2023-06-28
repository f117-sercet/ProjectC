
// 头文件
#include <iostream>
using namespace std;
#include <math.h>

void weclome() {// 输出一行信息
    cout <<"Hello World"<<endl;

    // 提示输入姓名
    cout << "请输入您的名字:"<< endl;

    // 用一个变量 接收键盘输入
    string name;
    cin >> name;

    // 输出欢迎信息
    cout << "Hello,"<<name<<endl;
}

// 主函数
int main() {

    // 调用函数
    weclome();
     cin.get();
    // 这里写两次是因为之前输入信息时敲回车确认，会由第一个get捕捉到
    cin.get();

}
