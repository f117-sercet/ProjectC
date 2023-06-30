#include <iostream>

using namespace std;
// 基本数据类型
int main() {

    //std::cout << "Hello, World!" << std::endl;

    short a = 1;
    cout << "a的长度为：" << sizeof(a) << endl;

    int b;
    cout << "b的长度为：" << sizeof(b) << endl;

    long c;
    cout << "c的长度为:" << sizeof(c) << endl;

    long long d;
    cout << "d的长度为：" << sizeof(d) << endl;

    cin.get();


    // 无符号整形
    short a1 = 32768;
    cout <<"a1 = "<< a1<<endl;
    cout << "a1的长度为"<<sizeof a1<<endl;


    unsigned short a2 = 32768;
    cout << "a2 = " << a2 << endl;
    cout << "a2的长度为：" << sizeof a2 << endl;


    // char
    char ch = 65;
    cout << "65对应的字符为：" << ch << endl;

    char ch2 = ch + 1;
    cout << "66对应的字符为：" << ch2 << endl;

    // bool
    bool bl = true;
    cout << "bl = " << bl << endl;
    cout << "bool类型长度为：" << sizeof bl << endl;




    return 0;

    

}
