//
// Created by LENOVO on 2023/8/29.
//

#include "include.h"


int count;


int main(int argc,char const *argv[]){

    create();
    enque(5);
    return 0;
}
void create(){

    head = nullptr;
    tail = nullptr;

}

// 进队
void enque(int data){
    if (head == nullptr){
        head = new node;
        head->data= data;
        head->pre = nullptr;
        tail = head;
    } else{
        tmp = new node;
        tmp->data = data;
        tmp->next = tail;
        tail = tmp;
    }
}

// 出队
int deque(){
    int returnData = 0;
    if (head == nullptr){
        printf("ERROR: Deque from empty queue.\n");
        exit(1);
    }
    else {

       returnData =  head->data;

        if (head->pre == nullptr)
            head = nullptr;
        else
            head = head->pre;
        head->next = nullptr;
    }
    return returnData;
}

int size(){
    return count;
}

