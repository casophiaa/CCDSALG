#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/


void printRecord(Record *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].idNumber, arr[i].name);
    }
}

void swap (Record *arr, int i, int j){
    Record temp = arr[i];                                            
    arr[i] = arr[j];                                                    
    arr[j] = temp;    

}



// void insertionSort(Record *arr, int n)
// {
//     // TODO: Implement this sorting algorithm here.






// }

//first index is set as min then compared to other indices; if min is bigger than curr i then swap
void selectionSort(Record *arr, int n) {
    // TODO: Implement this sorting algorithm here.
    int i, j, min;
    for (i=0; i < n; i++){
        min=i;
        for (j=i+1; j<n; j++){
            if (arr[j].idNumber < arr[min].idNumber)
            swap(arr, j, min);
        }
    }

    printRecord(arr, n);
}



// void mergeSort(Record *arr, int p, int r)
// {
//     // TODO: Implement this sorting algorithm here.






// }

/*
* Define AT LEAST ONE more sorting algorithm here, apart from the
* ones given above. Make sure that the method accepts an array of
* record structures.
*/











#endif