//
// Created by LENOVO on 2023/10/12.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void display(const int *arr,int n){

    for (int i = 0; i < n; ++i) {
        printf("%d",arr[i]);
    }
    printf("\n");
}

void swap(int *first,int *second){

    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int *arr,int size){

    for (int i = 0; i < size-1; ++i){

        bool  swapped = false;
        for (int j = 0; j< size-1; ++j){

            if (arr[j]>arr[j+1]){

                swap(&arr[j],&arr[j+1]);
            }
        }
        if (!swapped){

            break;
        }
    }

}



