#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // For dynamic memory allocation

int main() {
    int n;
    long startTime, endTime, executionTime;
    char filepath[] = "/Users/dennissesalgado/Documents/GitHub/CCDSALG/MCO1/data/random100.txt";

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

    readFile(records, filepath);

    printf("\nSorting...\n");
    startTime = currentTimeMillis();
    // insertionSort(records, n); 
    // selectionSort(records, n); 
    // mergeSort(records, p, r);  
    // customSort
    endTime = currentTimeMillis();
    executionTime = endTime - startTime;
    printf("Execution Time: %ld ms\n", executionTime);


    // to print records
    printf("Printing records:\n");
    printRecord(records, n); 


    free(records);  // Free allocated memory

    return 0;
}


