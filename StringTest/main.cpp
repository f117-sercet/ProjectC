#include <iostream>
using namespace std;

int main() {
    //std::cout << "Hello, World!" << std::endl;
    //return 0;

    /**
     * 默认初始化，空字符串
     */
     string s1;

    // 用另一个字符串变量
    string s2 = s1;

    // 用一个字符串字面值，做拷贝初始化
    string s3 = "Hello World!";

    // 用一个字符串字面值，做拷贝初始化
    string s4 ("Hello World!");

    // 定义字符和重复的次数，做直接初始化，
    string s5(8,'h');

    /**
     * 1.	默认初始化，得到的就是一个空字符串
     * 2.	拷贝初始化，用赋值运算符（等号“=”）表示；
     * 可以使用另一个string对象，也可以使用字符串字面值常量；
     * 3.	直接初始化，用括号表示；可以在括号中传入一个字符串，也可以传入字符和重复的次数
     */

    // 处理字符串中的字符
    string str = "hello world";

    // 获取第三个字符
    cout << " str[2] ="<< str[2] <<endl;

    // 将第一个字符改为 'H'
      str[0] = 'H';

  // 将最后一个字符改为 'D',
  str[str.size()-1] = 'D';

  cout << "str = " << str <<endl;

  /**
   * 	string内字符的索引，也是从0开始
   * 	string同样有一个成员函数size，可以获取字符串的长度
   * 	索引最大值为 (字符串长度 - 1)，不能越界访问；如果直接越界访问并赋值，有可能导致非常严重的后果，出现安全问题；
   * 	如果希望遍历字符串的元素，也可以使用普通for循环和范围for循环，依次获取每个字符
   */

  // 遍历字符串，将小写字母变成大写
    for (int i = 0; i < str.size()-1; ++i) {

        str[i] = toupper(str[i]);
    }
}
