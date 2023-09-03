//
// Created by LENOVO on 2023/9/3.
//



#include <cstring>

void getNext(int *pInt, char *p);

// 设定 s 是目标串， p 是模式串
int KMPFind(char* s, char* p) {
    int sLen = strlen(s);   // 目标串的长度
    int pLen = strlen(p);   // 模式串的长度
    int i = 0;              // 指向目标串的下标
    int j = 0;              // 指向模式串的下标
    // 定义next数组
    int *next = new int [pLen];
    getNext(next, p);
    while (i < sLen && j < pLen) {
        // 当字符相等时，指针后移，匹配下一个字符
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        }
            // 如果 j!=-1 并且s[i] != p[j]，则表示字符匹配失败
            // 此时指针 i 不回溯，j 则重置为next[j]
        else {
            j = next[j];
        }
    }
    // 如果匹配成功，则返回模式串 p 的第一个字符在目标串中出现的位置
    if (j == pLen) {
        return i - j;
    }
        // 如果匹配失败，则返回-1
    else{
        return -1;
    }


}
void getNext(char* p, int next[]) {
    int pLen = strlen(p);   // 取到子串的长度 pLen
    next[0] = -1;           // next[0]初始化为-1, 表示子串已经滑动到头
    int k = -1;             // p[k]表示前缀子串
    int j = 0;              // p[j]表示后缀子串
    // 遍历子串
    while (j < pLen - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k;
            ++j;
            next[j] = k;
        }
        else {
            k = next[k];
        }
    }
}


