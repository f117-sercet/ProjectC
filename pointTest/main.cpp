#include <iostream>
using namespace std;
int main() {

    // 指针的定义语法形式：类型* 指针变量;
    int *p1;// p1是指向int类型的数据指针
    long *p2; // p2是指向long类型数据的指针


    // 本质：实就是一个整数表示的内存地址，它本身在内存中所占大小跟系统环境有关，而跟指向的数据类型无关。64位编译环境中，指针统一占8个字节；若是32位系统则占4字节。

    cout<<"p1在内存中的长度为"<< sizeof(p1)<<endl;
    cout<<"p2在内存中的长度为"<< sizeof(p2)<<endl;
    cout<<"p1的地址"<<&p1<<endl;
    //cout<<"p1在内存中存放的内容"<<(*p1)<<endl;
    //cout<<"p2在内存中存放的内容"<<(*p2)<<endl;
    cout << "Hello, World!" << endl;


    // 获取对象地址给指针赋值
    int a = 100;
    int b = 120;
    int *p = &b;
    p = &a;
    cout<< "p:"<< &p<<endl;

    //指针指向数据对象后，可以通过指针来访问对象,访问方式是使用”解引用操作符(*)“
    return 0;
}
