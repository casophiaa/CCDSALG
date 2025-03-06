#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

int counter=0;

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


void insertionSort(Record *arr, int n){
    // TODO: Implement this sorting algorithm here.
    int i,j;
    Record key;
    counter = 0;                                            counter++;

    for (i=1; i<n; i++){                                        counter++;
        key = arr[i];                                           counter++;
        j= i-1;                                                 counter++;
       while (j >= 0 && arr[j].idNumber > key.idNumber) {       counter++;
            arr[j + 1] = arr[j];                                counter++;
            j--;                                                counter++;
        }                                                       counter++;
        arr[j + 1] = key;                                       counter++;
    }                                                           counter++;
    //printRecord(arr, n);                                      counter++;
}

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

    //printRecord(arr, n);
}



void merge(Record *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Record *L = (Record *)malloc(n1 * sizeof(Record));
    Record *R = (Record *)malloc(n2 * sizeof(Record));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i].idNumber <= R[j].idNumber)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(Record *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#define BUCKET_SIZE 10  // Define the number of buckets

void bucketSort(Record *arr, int n) {
    int minID = arr[0].idNumber, maxID = arr[0].idNumber;
    
    for (int i = 1; i < n; i++) {
        if (arr[i].idNumber < minID) minID = arr[i].idNumber;
        if (arr[i].idNumber > maxID) maxID = arr[i].idNumber;
    }

    int range = (maxID - minID) / BUCKET_SIZE + 1;
    Record *buckets[BUCKET_SIZE];
    int bucketCount[BUCKET_SIZE] = {0};

    for (int i = 0; i < BUCKET_SIZE; i++)
        buckets[i] = (Record *)malloc(n * sizeof(Record));

    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i].idNumber - minID) / range;
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    for (int i = 0, k = 0; i < BUCKET_SIZE; i++) {
        if (bucketCount[i] > 0) {
            mergeSort(buckets[i], 0, bucketCount[i] - 1);  // Use Merge Sort to sort each bucket
            for (int j = 0; j < bucketCount[i]; j++)
                arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}











#endif