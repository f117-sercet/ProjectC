//
// Created by LENOVO on 2023/8/16.
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stack>
//#include <queue>

struct Node {

    int data;
    struct Node *next;
    struct Node *pre;

} stackNode ;

void initStack();

void push(void *object);

void *pop();

int size();

int isEmpty();

void *top();


