#include <iostream>
#include "math.h"
using namespace std;
int main() {
    std::cout << "Hello, ���" << std::endl;

    unsigned s = 32767;
     cout << " s+1 = " << s+1<< endl;
    short s2 =s+1;
    cout << " s2 = " << s2 << endl;

    //������䣺
    int i= 0;
    while (i< 5){
        int a =i;
        ++i;
        cout << " a = " << a << endl;
    }

    // forѭ��
    // ��Χforѭ��
    for (int num : {3, 6, 8, 10})
    {
        cout << "���������ڵ������ǣ�" << num << endl;
    }


    // ����
    int a1[10];
    const int n=4; // ����

    return 0;


}
