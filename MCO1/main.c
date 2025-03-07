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
    char filepath[] = "/Users/sophiaorencia/Desktop/MCO1/data/random100.txt"; // Change file location

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

    long totalTime;

    // Insertion Sort
    totalTime = 0;
    printf("\nSorting with Insertion Sort...\n\n");
    printf("\nINSERTION SORT\n\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath);
        counter = 0;
        startTime = currentTimeMillis();
        insertionSort(records, n);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        totalTime += executionTime;
        printf("Iteration %d: Execution Time = %ld ms, Operation Count = %ld\n", i + 1, executionTime, counter);
    }
    printf("\n\033[1mAverage Execution Time: %ld ms\033[0m\n", totalTime / ITERATIONS);
    printf("\n-----------------------------------------------------\n");


    // Selection Sort
    totalTime = 0;
    printf("\nSorting with Selection Sort...\n\n");
    printf("\nSELECTION SORT\n\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath);
        counter = 0;
        startTime = currentTimeMillis();
        selectionSort(records, n);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        totalTime += executionTime;
        printf("Iteration %d: Execution Time = %ld ms, Operation Count = %ld\n", i + 1, executionTime, counter);
    }
    printf("\n\033[1mAverage Execution Time: %ld ms\033[0m\n", totalTime / ITERATIONS);
    printf("\n-----------------------------------------------------\n");


    // Merge Sort
    totalTime = 0;
    printf("\nSorting with Merge Sort...\n\n");
    printf("\nMERGE SORT\n\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath);
        counter = 0;
        startTime = currentTimeMillis();
        mergeSort(records, 0, n - 1);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        totalTime += executionTime;
        printf("Iteration %d: Execution Time = %ld ms, Operation Count = %ld\n", i + 1, executionTime, counter);
    }
    printf("\n\033[1mAverage Execution Time: %ld ms\033[0m\n", totalTime / ITERATIONS);
    printf("\n-----------------------------------------------------\n");

    // Bucket Sort
    totalTime = 0;
    printf("\nSorting with Bucket Sort...\n\n");
    printf("\nBUCKET SORT\n\n");
    for (int i = 0; i < ITERATIONS; i++) {
        readFile(records, filepath);
        counter = 0;
        startTime = currentTimeMillis();
        bucketSort(records, n);
        endTime = currentTimeMillis();
        executionTime = endTime - startTime;
        totalTime += executionTime;
        printf("Iteration %d: Execution Time = %ld ms, Operation Count = %ld\n", i + 1, executionTime, counter);
    }
    printf("\n\033[1mAverage Execution Time: %ld ms\033[0m\n", totalTime / ITERATIONS);
    printf("\n-----------------------------------------------------\n");

    free(records);  // Free allocated memory

    return 0;
}
