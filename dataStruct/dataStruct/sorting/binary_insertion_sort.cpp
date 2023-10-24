// 二分法
#include <cstdio>
#include "cstdlib"

using namespace std;

void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int *arr, int key, int low, int high)
{
    if (low >= high)
        return (key > arr[low]) ? (low + 1) : low;
    int mid = low + (high - 1) / 2;
    if (arr[mid] == key)
        return mid + 1;
    else if (arr[mid] > key)
        return binarySearch(arr, key, low, mid - 1);
    else
        return binarySearch(arr, key, mid + 1, high);
}

void insertionSort(int *arr, int size)
{
    int i, j, key, index;
    for (i = 0; i < size; i++)
    {
        j = i - 1;
        key = arr[i];
        index = binarySearch(arr, key, 0, j);

        while (j >= index)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}