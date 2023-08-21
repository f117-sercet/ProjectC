//
// Created by LENOVO on 2023/8/15.
//

#ifndef __LIST__
#define __LIST__
#define L List_T
#include <string.h>;

typedef  struct ListNode
{
    int val;
    struct ListNode  *next;
} ListNode ;

extern ListNode List_init(void);
extern ListNode List_push(ListNode list, int val);
extern int List_length(ListNode *list);
extern void **List_toArray(ListNode *list);
extern ListNode List_append(ListNode *list, ListNode tail);
extern ListNode List_list(ListNode *list, int val, ...);
/* TODO */
extern ListNode List_copy(ListNode *list);
extern int List_pop(ListNode *list);

#undef L
#endif