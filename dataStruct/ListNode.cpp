

#include <stdio.h>
#include <stdlib.h>
// 链表的实现及其操作

// 定义链表-单链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* reverseList(ListNode* head) {

        ListNode* newHead =nullptr;
        //ListNode*  =head;
        ListNode* temp = nullptr;


        if(head ==nullptr || head->next == nullptr){

            return head;
        }

        while(head){

            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

    // 尾插法建立单链表
    ListNode* InsertList(ListNode* head){

        ListNode* r= head;
        ListNode* s= head;

        while (head){

            r->next= s;
            r=s;
        }
        r->next= nullptr;
        return head;

    }


