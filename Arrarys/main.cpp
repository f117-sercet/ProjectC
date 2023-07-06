#include <iostream>
using namespace std;
int main() {
    cout << "Hello, World!" <<endl;

    // 数组定义: 数据类型 数组名[元素个数];
/**
 * 数组初始化：
 对数组做初始化，要使用花括号{}括起来的数值序列；
如果做了初始化，数组定义时的元素个数可以省略，编译器可以根据初始化列表自动推断出来；
初始值的个数，不能超过指定的元素个数；
初始值的个数，如果小于元素个数，那么会用列表中的值初始化靠前的元素；剩余元素用默认值填充，整型的默认值就是0；
如果没有做初始化，数组中元素的值都是未定义的；这一点和普通的局部变量一致；

 */
 // 选择排序
    int arr[] = {5, 9, 2, 7, 4, 3, 12, 6, 1, 5, 7};

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <size ; ++i) {

        for (int j =i+1; j <size; ++j) {
            if (arr[j] < arr[i]){

                int temp = arr[i];
                arr[i] = arr[j];
                arr[i] = temp;
        }
    }
    }
    // 输出
    for (int num:arr)
        cout << num << "\t";
    cin.get();



    // 冒泡排序
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j < size-i-j; ++j) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

            }
        }
    }

}
