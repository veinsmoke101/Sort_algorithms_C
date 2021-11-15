#include <stdio.h>
#include <stdlib.h>

//Quick Sort
void quickSort(int * , int , int);
int partition(int *,int , int);

//Insertion Sort
void insertionSort(int * ,int );

//Selection Sort
void selectionSort(int * , int);

// useful functions
void swap(int * ,int * );




int main()
{

    int arr[] = {33, 18, 59, 9, 14},i;
    int length = 5;



    quickSort(arr,0,length - 1); // change this declaration to test the sort algo you want

    printf("sorted array %d : \n",length);
        for (i = 0; i < length; i++)
        printf("%d ", arr[i]);



    return 0;
}





void selectionSort(int * arr,int length){

    int i, j, current_min_idx;

    for (i = 0; i < length-1; i++)
    {
        current_min_idx = i; // select
        for (j = i+1; j < length; j++)
            if (arr[j] < arr[current_min_idx])
                current_min_idx = j;

        swap(&arr[i],&arr[current_min_idx]);

    }
}

void swap(int * A,int * B){

    int temp;
    temp = *A;
    *A = *B;
    *B = temp;

}

void insertionSort(int * arr,int length){
        int i, j, ins_key;

    for (i = 1; i < length; i++) {
    ins_key = arr[i]; // select element to insert
    j = i - 1;

    // find right insertion place
    while (j >= 0 && arr[j] > ins_key)
    {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = ins_key; // insert
    }
}


void quickSort(int * arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); // do the same for left side
        quickSort(arr, pi + 1, high);// do the right for left side
    }
}

int partition (int * arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
