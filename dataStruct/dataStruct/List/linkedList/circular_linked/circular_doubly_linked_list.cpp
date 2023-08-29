//
// Created by LENOVO on 2023/8/28.
//

#include <assert.h>  /// to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <inttypes.h>  /// to provide a set of integer types with universally consistent definitions that are operating system-independent
#include <stdio.h>     /// for IO operations
#include <stdlib.h>

typedef struct node{
    struct node *prev,*next;
    int value;
} ListNode;

ListNode *create_node(int data){

    ListNode *new_list = (ListNode *) malloc(sizeof(ListNode));

    new_list->value = data;
    new_list->next = new_list;
    new_list->prev = new_list;

    return new_list;

}

ListNode *insert_at_head(ListNode *head,int data){

    if (head = nullptr){

        head  = create_node(data);
        return  head;
    }
    else {

        ListNode *temp;
        ListNode *new_node = create_node(data);
        temp = head->prev;
        new_node->next = head;
        head->prev = new_node;
        new_node->prev = temp;
        temp->next = new_node;
        head = new_node;
        return head;
    }

}


ListNode *insert_at_tail(ListNode *head,int data){

    if (head == NULL)
    {
        head = create_node(data);
        return head;
    }

    else{

        ListNode *temp1,*temp2;
        ListNode *new_node = create_node(data);
        temp1 = head;
        temp2 = head->prev;
        new_node->prev = temp2;
        new_node->next = temp1;
        temp1->prev = new_node;
        temp2->next = new_node;

        return  head;

    }

}

ListNode *delete_from_tail(ListNode *head){

    if (head == nullptr){

        printf("The list is empty\n");
        return head;
    }

    ListNode *temp1,*temp2;
    temp1 = head;
    temp2 = temp1->prev;

    if (temp1 == temp2){
        free(temp2);
        head = nullptr;
        return  head;
    }
    (temp2->prev)->next = temp1;
    temp1->prev = temp2->prev;
    free(temp2);
    return head;
}

int getSize(ListNode *head){

    if (!head){

        return 0;
    }
    int  size = 1 ;
   ListNode *temp = head->next;
    while (temp !=head){
        temp = temp->next;
        size++;
    }
    return size;
}

void display_list(ListNode *head)
{
    printf("\nContents of your linked list: ");
    ListNode *temp;
    temp = head;
    if (head != nullptr)
    {
        while (temp->next != head)
        {
            printf("%" PRIu64 " <-> ", temp->value);
            temp = temp->next;
        }
        if (temp->next == head)
        {
            printf("%" PRIu64, temp->value);
        }
    }
    else
    {
        printf("The list is empty");
    }
    printf("\n");
}

int get(ListNode *list, const int index)
{
    if (list == NULL || index < 0)
    {
        exit(EXIT_FAILURE);
    }
    ListNode *temp = list;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->value;
}





