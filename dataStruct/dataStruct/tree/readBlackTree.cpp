//
// Created by LENOVO on 2023/9/3.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *par;
    struct node *left;
    struct node *right;
    int color;
} Node;


Node *newNode(int val, Node *par) {
    Node *node = new Node;
    node->val = val;
    node->par = par;
    node->left = NULL;
    node->right = nullptr;
    node->color = 1;
}

int isLeafNode(Node *node) {
    if (node->left == nullptr && node->right == nullptr)
        return 1;
    return 0;
}

// 左旋树

Node *leftRotate(Node *node) {
    Node *parent = node->par;
    Node *grandParent = parent->par;

    parent->right = node->left;
    if (node->left != NULL) {
        node->left->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->left = parent;
    if (grandParent != NULL) {
        if (grandParent->right == parent) {
            grandParent->right = node;
        } else {
            grandParent->left = node;
        }
    }
    return node;
}

// Right Rotate
Node *rightRotate(Node *node) {
    Node *parent = node->par;
    Node *grandParent = parent->par;

    parent->right = node->left;
    if (node->left != NULL) {
        node->left->par = parent;
    }
    node->par = grandParent;
    parent->par = node;
    node->left = parent;
    if (grandParent != nullptr) {
        if (grandParent->right == parent) {
            grandParent->right = node;
        } else {
            grandParent->left = node;
        }
    }
    return node;
}

void checkNode(Node *node) {
    if (node == nullptr || node->par == nullptr) {


        return;
    }
    Node *child = node;
    // 如果是一个黑色节点或者他的父节点是一个黑色节点
    if (node->color == 0 || (node->par)->color == 0) {
        return;
    }

    // Both parent and child are red
    // Check For Uncle
    Node *parent = node->par;
    Node *grandParent = parent->par;

    // If grandParent is NULL, then parent is the root.
    // Just make the root black.

    if (grandParent == nullptr) {
        parent->color = 0;
        return;
    }

    // 祖父和儿子都是红的
    if (grandParent->right != nullptr && (grandParent->right)->color == 1
        && grandParent->left != nullptr && (grandParent->left)->color == 1) {
        (grandParent->right)->color = 0;
        (grandParent->left)->color = 0;
        grandParent->color = 1;

        return;
    } else {
        // 左旋
        Node *greatGrandParent = grandParent->par;

        if (grandParent->right == parent) {



            // 右边的情况
            if (grandParent->right == node) {
                grandParent->right = parent->left;

                if (parent->left != nullptr) {
                    (parent->left)->par = grandParent;
                }
                parent->left = grandParent;
                grandParent->par = parent;

                //Attach to existing Tree
                parent->par = greatGrandParent;
                if (greatGrandParent != nullptr) {
                    if (greatGrandParent->left != nullptr
                        && greatGrandParent->left == grandParent) {

                        greatGrandParent->left = parent;
                    } else {
                        greatGrandParent->right = parent;
                    }
                }
                // 改变颜色
                parent->color = 0;
                grandParent->color = 1;

            } else {
                // 右子树左子树情况
                //儿子左旋
                parent->left = child->right;
                if (child->right != nullptr) {
                    (child->right)->par = parent;
                }
                child->right = parent;
                parent->par = child;

                // 第二步:儿子 和祖父旋转
                grandParent->right = child->left;
                if (child->left != nullptr) {
                    (child->left)->par = grandParent;
                }
                child->left = grandParent;
                grandParent->par = child;

                // Attach to the existing tree
                child->par = greatGrandParent;
                if (greatGrandParent != nullptr) {
                    if (greatGrandParent->left != nullptr &&
                        greatGrandParent->left == grandParent) {
                        greatGrandParent->left = child;
                    } else {
                        grandParent->right = child;
                    }
                }
                // 改变颜色
                child->color = 0;
                grandParent->color = 1;
            }
        } else {
            //left Case
            // Left Left Case

            if (parent->left == node) {

                grandParent->left = parent->right;
                if (parent->right != nullptr) {
                    (parent->right)->par = grandParent;
                }
                parent->par = greatGrandParent;
                grandParent->par = parent;

                // Attach to existing trees

                parent->par = greatGrandParent;
                if (greatGrandParent != nullptr) {
                    if (greatGrandParent->left != nullptr
                        && grandParent->left == grandParent) {
                        grandParent->left = parent;
                    } else {
                        greatGrandParent->right = parent;
                    }
                }

                // 换色
                parent->color = 0;
                grandParent->color = 1;
            } else {
                // Left Right Case

                // First step->Parent Child Rotation
                parent->right = child->left;


            }
        }
    }
}

void insertNode(int val, Node **root) {

    Node *buffRoot = *root;
    while (buffRoot) {

        if (buffRoot->val > val) {

            if (buffRoot->val > val) {

                if (buffRoot->left != nullptr) {
                    buffRoot = buffRoot->left;

                } else {
                    Node *toInsert = newNode(val, buffRoot);
                    buffRoot->left = toInsert;
                    buffRoot = toInsert;

                    break;
                }

            } else {
                if (buffRoot->right != nullptr) {

                    buffRoot = buffRoot->right;
                } else {

                    Node *toInsert = newNode(val, buffRoot);
                    buffRoot->right = toInsert;
                    buffRoot = toInsert;

                    break;
                }
            }
        }
        while (buffRoot != *root) {
            checkNode(buffRoot);
            if (buffRoot->par == nullptr) {

                *root = buffRoot;
                break;
            }
            buffRoot = buffRoot->par;

            if (buffRoot == *root) {
                buffRoot->color = 0;
            }
        }
    }
}

void checkForCase2(Node *toDelete, int deletes, int fromDirection, Node **root) {
    if (toDelete == (*root)) {
        (*root)->color = 0;
        return;
    }

    if (!deletes && toDelete->color == 1) {
        if (!fromDirection) {
            if (toDelete->right != NULL) {
                toDelete->right->color = 1;
            }
        } else {
            if (toDelete->left != NULL) {
                toDelete->left->color = 1;
            }
        }
        toDelete->color = 0;
        return;
    }

    Node *sibling;
    Node *parent = toDelete->par;
    int locateChild = 0;

    if (parent->right == toDelete) {

        sibling = parent->left;
        locateChild = 1;

    } else {
        sibling = parent->right;
    }

    if ((sibling->right != nullptr && sibling->right->color == 1)
        || (sibling->left != nullptr && sibling->left->color == 1)) {

        if (sibling->right != nullptr && sibling->right->color == 1) {
            if (locateChild == 1) {

                int parColor = parent->color;
                sibling = leftRotate(sibling->right);
                parent = rightRotate(sibling);

                if (parent->par == nullptr) {

                    *root = parent;
                }

                parent->color = parColor;
                parent->left->color = 0;

                if (deletes) {
                    if (toDelete->left != nullptr) {

                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }

            } else {
                int parColor = parent->color;

                parent = leftRotate(sibling);

                if (parent->par == nullptr) {
                    *root = parent;
                }


                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                if (deletes) {

                    if (toDelete->right != nullptr) {

                        toDelete->right->par = parent->left;
                    }

                    parent->left->left = toDelete->left;
                    free(toDelete);
                }
            }
        } else {

            if (locateChild == 0) {
                int parColor = parent->color;

                sibling = rightRotate(sibling->left);
                parent = leftRotate(sibling);

                if (parent->par == nullptr) {

                    *root = parent;
                }
                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color = 0;

                if (deletes) {
                    if (toDelete->right != nullptr) {

                        toDelete->right->par = parent->left;
                    }
                    parent->left->left = toDelete->right;
                    free(toDelete);
                }
            } else {
                int parColor = parent->color;
                parent = rightRotate(sibling);

                if (parent->par == nullptr) {
                    *root = parent;
                }


                parent->color = parColor;
                parent->left->color = 0;
                parent->right->color;

                if (deletes) {
                    if (toDelete->left != nullptr) {
                        toDelete->left->par = parent->right;
                    }
                    parent->right->right = toDelete->left;
                    free(toDelete);
                }
            }
        }
    } else if (sibling->color == 0) {

        sibling->color = 1;

        if (deletes) {


            if (locateChild) {
                toDelete->par->right = toDelete->left;

                if (toDelete->left != nullptr) {
                    toDelete->left->par = toDelete->par;
                }
            } else {
                toDelete->par->left = toDelete->right;

                if (toDelete->right != nullptr) {
                    toDelete->right->par = toDelete->par;
                }
            }
        } else {
            if (locateChild) {
                toDelete->par->right = toDelete->left;
                if (toDelete->left != nullptr) {

                    toDelete->left->par = toDelete->par;
                }
                parent = rightRotate(sibling);

                if (parent->par == nullptr) {

                    *root = parent;
                }
                parent->color = 0;
                parent->right->color = 1;
                checkForCase2(parent->right, 0, 1, root);
            } else {


                // 左旋
                toDelete->par->left = toDelete->right;

                if (toDelete->right != nullptr) {
                    toDelete->right->par = toDelete->par;
                }
                parent = leftRotate(sibling);

                if (parent->par == nullptr) {
                    *root = parent;
                }
                printf("\nroot - %d - %d\n", parent->val, parent->left->val);
                parent->color = 0;
                parent->left->color = 1;
                checkForCase2(parent->left, 0, 0, root);
            }
        }
    }
}







