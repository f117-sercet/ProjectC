//
// Created by LENOVO on 2023/9/3.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *par;
    struct node *left;
    struct node *right;
    int color;
} Node;


Node *newNode(int val,Node *par)
{
Node *node = new Node;
 node->val =val;
 node->par = par;
 node->left = NULL;
 node->right = nullptr;
 node->color = 1;
}

int isLeafNode(Node *node)
{

}