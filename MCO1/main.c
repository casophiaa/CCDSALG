#include "record.c"
#include "sortingalgorithms.c"
#include "filereader.c"
#include "timer.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ITERATIONS 5  // Number of times each sorting algorithm will run

// Function to check if records are sorted
int isSorted(Record *records, int n) {
    for (int i = 1; i < n; i++) {
        if (records[i - 1].idNumber > records[i].idNumber) {
            return 0;
        }
    }
    return 1;
}

void printRecords(Record *records, int n) {
    printf("\nSorted Records:\n");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", records[i].idNumber, records[i].name);
    }
    printf("-----------------------------\n");
}



int main() {
    int n, choice;
    long startTime, endTime, executionTime, totalTime;
    char filepath[] = "/Users/sophiaorencia/Desktop/MCO1/data/random25000.txt"; // Change file location

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

    // User chooses sorting algorithm
    printf("Choose a sorting algorithm:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Bucket Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            totalTime = 0;
            printf("\nSorting with Insertion Sort...\n\n");
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
            break;

        case 2:
            totalTime = 0;
            printf("\nSorting with Selection Sort...\n\n");
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
            break;

        case 3:
            totalTime = 0;
            printf("\nSorting with Merge Sort...\n\n");
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
            break;

            case 4:
            totalTime = 0;
            printf("\nSorting with Bucket Sort...\n\n");
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
            break;
    

        default:
            printf("Invalid choice. Exiting program.\n");
            free(records);
            return 1;
    }

    printf("\n\033[1mAverage Execution Time: %ld ms\033[0m\n", totalTime / ITERATIONS);
    printf("\n-----------------------------------------------------\n");


    // Post-Sorting Verification
    if (isSorted(records, n)) {
        printf("\033[1;32mSorting Verified: Data is in correct order!\033[0m\n\n");

        // Ask user if they want to see sorted data
        char viewChoice;
        printf("Do you want to view the sorted records? (y/n): ");
        scanf(" %c", &viewChoice);

        if (viewChoice == 'y' || viewChoice == 'Y') {
            printRecords(records, n);
        }
    } else {
        printf("\033[1;31mSorting Failed: Data is NOT in correct order!\033[0m\n\n");
    }

    free(records);

    return 0;
}
