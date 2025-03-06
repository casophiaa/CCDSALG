#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // For dynamic memory allocation

#define ITERATIONS 5  // Number of times each sorting algorithm will run

int main() {
    int n;
    long startTime, endTime, executionTime;
    char filepath[] = "/Users/dennissesalgado/Documents/GitHub/CCDSALG/MCO1/data/random100.txt"; //change file location

    FILE *fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    fscanf(fp, "%d", &n);  // Read number of records
    fclose(fp);

    if (n <= 0) {
        printf("Error: Invalid number of records.\n");
        return 1;
    }

    Record *records = (Record *)malloc(n * sizeof(Record));
    if (records == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

/*
OG SELECTION SORT CODE
printf("\nSorting...\n");
    startTime = currentTimeMillis();
    //insertionSort(records, n); 
    selectionSort(records, n); 
    // mergeSort(records, p, r);  
    // customSort
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Execution Time: %ld ms\n", executionTime);
*/

    long totalTime = 0;


    // Insertion Sort
    totalTime = 0;
    printf("\nSorting with Insertion Sort...\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath); // Reload original data
        startTime = currentTimeMillis();
        insertionSort(records, n);
        endTime = currentTimeMillis();
        totalTime += (endTime - startTime);
    }
    printf("Insertion Sort Average Execution Time: %ld ms\n", totalTime / ITERATIONS);
   
    // Selection Sort
    totalTime = 0;
    printf("\nSorting with Selection Sort...\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath); // Reload original data
        startTime = currentTimeMillis();
        selectionSort(records, n);
        endTime = currentTimeMillis();
        totalTime += (endTime - startTime);
    }
    printf("Selection Sort Average Execution Time: %ld ms\n", totalTime / ITERATIONS);

    
    // Merge Sort
    totalTime = 0;
    printf("\nSorting with Merge Sort...\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath); // Reload original data
        startTime = currentTimeMillis();
        mergeSort(records, 0, n - 1);
        endTime = currentTimeMillis();
        totalTime += (endTime - startTime);
    }
    printf("Merge Sort Average Execution Time: %ld ms\n", totalTime / ITERATIONS);

    
    // Bucket Sort
    totalTime = 0;
    printf("\nSorting with Bucket Sort...\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath); // Reload original data
        startTime = currentTimeMillis();
        bucketSort(records, n);
        endTime = currentTimeMillis();
        totalTime += (endTime - startTime);
    }
    printf("Bucket Sort Average Execution Time: %ld ms\n", totalTime / ITERATIONS);

    printf("Frequency Count: %d", counter);

    free(records);  // Free allocated memory

    return 0;
}
