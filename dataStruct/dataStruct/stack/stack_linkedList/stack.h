//
// Created by LENOVO on 2023/8/16.
//

#ifndef __STACK__
#define __STACK__


#define T Stack_T
typedef struct stackLinkedList{

    int val;
    struct stackLinkedList *next;
    int count;
    struct stackLinkedList *head;

} ListStack;

extern ListStack Stack_init(void);
extern int Stack_size(ListStack *stack);
extern int Stack_empty(ListStack *stack);
extern void Stack_push(ListStack *stack, int val);
extern void *Stack_pop(ListStack *stack);
extern void Stack_print(ListStack *stack);

#endif
