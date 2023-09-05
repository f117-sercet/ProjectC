
#include <cstdio>
#include <cstdlib>

struct AvlNode
{
    int key;
    struct AvlNode *left;
    struct  AvlNode *right;
    int height;
};
typedef struct AVLnode avlNode;

int max(int a,int b);

AvlNode *newNode(int key);

int nodeHeight(AvlNode *node);

int heightDiff(avlNode *node);

AvlNode *minNode(AvlNode *node);

void printAVL(AvlNode *node, int level);

avlNode *rightRotate(avlNode *z);

avlNode *leftRotate(avlNode *z);

avlNode *LeftRightRotate(avlNode *z);

avlNode *RightLeftRotate(avlNode *z);

avlNode *insert(avlNode *node, int key);

avlNode *deleteNode (avlNode *node, int queryNum);

avlNode *findNode(avlNode *node, int queryNum);

void printPreOrder(avlNode *node);

void printInOrder(avlNode *node);

void printPostOrder(avlNode *node);

