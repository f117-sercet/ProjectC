#include "list.h"
#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


#define ListNode ListNode

ListNode List_init(void ){

    ListNode* list;
   list = (ListNode*) malloc(sizeof (ListNode));
   list->next = NULL;
    return *list;
}


// 新增节点
ListNode List_push(ListNode list, int val){

    ListNode * newSort = (ListNode*) malloc(sizeof (ListNode));
    newSort->val = val;
    newSort->next = list.next;
    return *newSort;

}

// 长度
int List_length(ListNode *list){
    
    int n;
   while(list){
       n++;
      list= list->next;
   }
    return n - 1;
    
}

void **List_toArray(ListNode *list)
{
    int i, n = List_length(list) + 1;
    void **array = (void **)malloc((n + 1) * sizeof(*array));

    for (i = 0; i < n; i++)
    {
        array[i] = (void *) list->val;
        list = list->next;
    }
    array[i] = NULL;
    return array;
}


