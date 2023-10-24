// 选择排序
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}


void selectionSort(int *arr,int size){

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(arr + i, arr + min_index);
        }
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
    selectionSort(arr, size);
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
    free(arr);
}

/** Driver Code */
int main(int argc, const char *argv[])
{
    /* Intializes random number generator */
    srand(time(NULL));
    test();
    return 0;
}