//
// Created by LENOVO on 2023/8/17.
//

#include  <stdio.h>
#include <conio.h>
#include  <stdlib.h>
#define  NULL  0


typedef struct node {
    int data;
    struct node *next;

} ListNode;

ListNode  *first = NULL;
ListNode  *last=NULL ;

void create() {

    int i,n;

    printf("Enter the number of nodes required:\n") ;
    scanf("%d",&n) ;

    for(i=1; i<n; i++){

       ListNode *pnode=( ListNode *)malloc(sizeof(ListNode*)) ;

        if (pnode == NULL){
            printf("Memory overflow. Unable to create.\n") ;
            return ;
        }
        //
        //scanf("%d",&pnode->data);
        scanf("%d",&pnode->data);
        scanf("%d",&(pnode->data));

        //scanf("%d",(*pnode).data);
        if(first==NULL)
            first=last=pnode ;
        else
        {
            last->next=pnode ;
            last=pnode ;    /* last keeps track of last node */
        }

        last->next=first ;

        // 循环链表
    }

    }


}



