
#include "stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


ListStack  Stack_init(void){

    ListStack *stack;
    stack = (ListStack*) malloc(sizeof (ListStack*));
    stack->count = 0;
    stack->head = NULL;
    return *stack;
}

int Stack_empty(ListStack *stack){

    assert(stack);

    return stack->count = 0;

}

int Stack_size(ListStack *stack){

    assert(stack);
    return stack->count;

}

void Stack_push(ListStack *stack,int val){

     ListStack *Node;

    assert(stack);
    Node->val = val;
    Node->next = stack->head;
    stack->head = Node;
    stack->count++;

}

void *Stack_pop(ListStack *stack){

    ListStack *Node;
    assert(stack);
    assert(stack->count> 0 );
    Node = stack->head;
    stack->head = Node->next;
    stack->count--;
    free(Node);
}

void Stack_print(ListStack *stack){

    assert(stack);

    int i,size =Stack_size( stack);
    ListStack *current_elem = stack->head;

    printf("Stack [Top --- Bottom]: ");

    for (int j = 0; j < size; ++j) {
        printf("%p ", (int *)current_elem->val);
        current_elem = current_elem->next;
    }
    printf("\n");
}
