#ifndef SORTINGALGORITHMS_C
#define SORTINGALGORITHMS_C

#include <stdio.h>
#include <stdlib.h>
#include "record.c"

/*
* You may declare additional variables and helper functions
* as needed by the sorting algorithms here.
*/

long counter = 0;

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
    counter = 0;                                                counter++;

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
    int n1 = mid - left + 1;                                            counter++;
    int n2 = right - mid;                                               counter++;

    Record *L = (Record *)malloc(n1 * sizeof(Record));                  counter++;
    Record *R = (Record *)malloc(n2 * sizeof(Record));                  counter++;

    for (i = 0; i < n1; i++) {                                          counter++; 
        L[i] = arr[left + i];                                           counter++; 
    }
    for (j = 0; j < n2; j++) {                                          counter++; 
        R[j] = arr[mid + 1 + j];                                        counter++; 
    }

    i = 0;                                                              counter++; 
    j = 0;                                                              counter++; 
    k = left;                                                           counter++;

    while (i < n1 && j < n2) {                                          counter++;
        if (L[i].idNumber <= R[j].idNumber) {                           counter++;
            arr[k++] = L[i++];                                          counter++;
        } else {
            arr[k++] = R[j++];                                          counter++;
        }
    }

    while (i < n1) {                                                    counter++;
        arr[k++] = L[i++];                                              counter++;
    }

    while (j < n2) {                                                    counter++;
        arr[k++] = R[j++];                                              counter++;
    }

    free(L);                                                            counter++; 
    free(R);                                                            counter++;
}

void mergeSort(Record *arr, int left, int right) {
    if (left < right) {                                                 counter++;
        int mid = left + (right - left) / 2;                            counter++;

        mergeSort(arr, left, mid);                                      counter++;
        mergeSort(arr, mid + 1, right);                                 counter++;

        merge(arr, left, mid, right);                                   counter++;
    }
}

#define BUCKET_SIZE 10  // Define the number of buckets

void bucketSort(Record *arr, int n) {
    int minID = arr[0].idNumber;                                        counter++;
    int maxID = arr[0].idNumber;                                        counter++;

    for (int i = 1; i < n; i++) {                                       counter++;
        if (arr[i].idNumber < minID) {                                  counter++;
            minID = arr[i].idNumber;                                    counter++;
        }
        if (arr[i].idNumber > maxID) {                                  counter++;
            maxID = arr[i].idNumber;                                    counter++;
        }
    }

    int range = (maxID - minID) / BUCKET_SIZE + 1;                      counter += 2;

    Record *buckets[BUCKET_SIZE];                                       counter++;
    int bucketCount[BUCKET_SIZE] = {0};                                 counter++;

    for (int i = 0; i < BUCKET_SIZE; i++) {                             counter++;
        buckets[i] = (Record *)malloc(n * sizeof(Record));              counter++;
    }

    for (int i = 0; i < n; i++) {                                       counter++;
        int bucketIndex = (arr[i].idNumber - minID) / range;            counter++;
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];      counter++;
    }

    for (int i = 0, k = 0; i < BUCKET_SIZE; i++) {                      counter++;
        if (bucketCount[i] > 0) {                                       counter++;
            mergeSort(buckets[i], 0, bucketCount[i] - 1);               counter++;
            for (int j = 0; j < bucketCount[i]; j++) {                  counter++;
                arr[k++] = buckets[i][j];                               counter++;
            }
        }
        free(buckets[i]);                                               counter++;
    }
}










#endif