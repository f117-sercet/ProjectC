#include <iostream>
#include <vector>
#include <array>
using namespace std;
int main() {
    cout << "Hello, World!" << endl;

    /***
     * vector:
     * 对数组功能进行扩展的一个标准类库，就是 ”容器“ vector,vector“容纳”着一堆数据对象，其实就是一组类型相同的数据对象的集合。
     *vector是标准库的一部分。要想使用vector，必须在程序中包含<vector>头文件，并使用std命名空间
     */

    /***
     * 基本用法：
     * vector其实是C++中的一个“类模板”，
     * 是用来创建类的“模子”。
     * 所以在使用时还必须提供具体的类型信息，也就是说，这个容器中到底要容纳什么类型的数据对象；
     * 具体的形式是在vector后面跟一个尖括号<>，里面填入具体类型信息。
     */
     // 默认初始化，不含任何参数
     vector<int> v1;

     // 列表初始化
     vector<char> v2 = {'a','b','c','d'};

     // 省略等号的初始化
     vector<short> v3{1,2,3,4,4};

    // 只定义长度，元素初值默认初始化，容器中有5个0
    vector<int> v4(5);

    // 定义长度和初始值，容器中有5个100
    vector<long> v5(5, 100);
    cout<< "v5.capacity()"<< v5.size()<< endl;

    /*****
     * vector内元素的索引，也是从0开始；
     * vector索引最大值为 (vector长度 - 1)，不能越界访问；
     * 如果直接越界访问并赋值，有可能导致非常严重的后果，出现安全问题
     * 遍历所有元素
     * vector中有一个可以调用的函数size()，只要调用它就能直接得到vector的长度（即元素个数）
     * 调用的方式是一个vector对象后面跟上一个点，再跟上size()。这种基于对象来调用的函数叫做“成员函数”。
     */
    for (int i = 0; i < v5.size(); ++i) {

        cout<<v5[i]<<'\t';
    }
    /*********另外的循环**************/
    for (int num: v5)
    {
        cout << num << "\t";
    }

    cin.get();

    /** vector 与数组的区别
     * 数组是更加底层的数据类型；长度固定，功能较少，安全性没有保证；但性能更好，运行更高效；
     * vector是模板类，是数组的上层抽象；长度不定，功能强大；缺点是运行效率较低；
     * 除了vector之外，C++ 11 还新增了一个array模板类，它跟数组更加类似，长度是固定的，但更加方便、更加安全。
     * 所以在实际应用中，一般推荐对于固定长度的数组使用array，不固定长度的数组使用vector。
     *
     */
}