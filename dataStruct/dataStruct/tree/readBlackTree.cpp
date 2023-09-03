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
    if (node->left == nullptr && node->right == nullptr)
        return 1;
    return 0;
}

// 左旋树

Node *leftRotate(Node *node)
{
    Node *parent = node->par;
    Node *grandParent = parent->par;
    parent->right = node->left;

    if (node->left!= nullptr){
        node->left->par = parent;
    }

}




