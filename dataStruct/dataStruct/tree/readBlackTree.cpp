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
    if (node->left != NULL)
    {
        node->left->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->left = parent;
    if (grandParent != NULL)
    {
        if (grandParent->right == parent)
        {
            grandParent->right = node;
        }
        else
        {
            grandParent->left = node;
        }
    }
    return node;
}

// Right Rotate
Node *rightRotate(Node *node)
{
    Node *parent = node->par;
    Node *grandParent = parent->par;

    parent->right = node->left;
    if (node->left != NULL)
    {
        node->left->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->left = parent;
    if (grandParent != nullptr)
    {
        if (grandParent->right == parent)
        {
            grandParent->right = node;
        }
        else
        {
            grandParent->left = node;
        }
    }
    return node;
}
void checkNode(Node *node)
{
    if ((node == nullptr || node->par == nullptr)) {


        return;
    }
    Node *child = node;
    // 如果是一个黑色节点或者他的父节点是一个黑色节点
    if (node->color == 0 || (node->par)->color == 0)
    {
        return;
    }

    // Both parent and child are red
    // Check For Uncle
    Node *parent = node->par;
    Node *grandParent = parent->par;

    // If grandParent is NULL, then parent is the root.
    // Just make the root black.

    if (grandParent == nullptr){
        parent->color =0;
        return;
    }


}




