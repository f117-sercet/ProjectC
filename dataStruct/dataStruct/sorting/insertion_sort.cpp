// 插入排序

#include "assert.h "
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void insertionSort(int *arr,int size){
    for (int i = 0; i < size; ++i) {
        int j = i-1;
        int key= arr[i];
        while(j >=0 && key<arr[j]){

            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}

static void test()
{
    const int size = rand() % 500; /* random array size */
    int *arr = (int *)calloc(size, sizeof(int));

    /* generate size random numbers from -50 to 49 */
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 100) - 50; /* signed random numbers */
    }
    insertionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}
int main(int argc, const char *argv[])
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}