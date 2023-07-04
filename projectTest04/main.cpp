#include <iostream>
#include "math.h"
using namespace std;
int main() {
    std::cout << "Hello, 你好" << std::endl;

    unsigned s = 32767;
     cout << " s+1 = " << s+1<< endl;
    short s2 =s+1;
    cout << " s2 = " << s2 << endl;

    //复合语句：
    int i= 0;
    while (i< 5){
        int a =i;
        ++i;
        cout << " a = " << a << endl;
    }

    // for循环
    // 范围for循环
    for (int num : {3, 6, 8, 10})
    {
        cout << "序列中现在的数据是：" << num << endl;
    }


    // 数组
    int a1[10];
    const int n=4; // 常量

    return 0;


}
