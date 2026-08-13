#include <stdio.h>
#include<stdlib.h>
int main() {
    FILE *fp;
    int arr[100], n, i;
    int smallest, secondSmallest;
    int largest, secondLargest;

    fp = fopen("daaprog.txt", "r");

    if (fp == NULL) {
        printf("File not found!\n");
        return 1;
    }

    while(fscanf(fp, "%d", &arr[n])==1)
    {
        n++;
    }

    if (n < 2) {
        printf("Need at least 2 elements.\n");
        return 1;
    }

    fclose(fp);

    if (arr[0] < arr[1]) {
        smallest = arr[0];
        secondSmallest = arr[1];

        largest = arr[1];
        secondLargest = arr[0];
    } else {
        smallest = arr[1];
        secondSmallest = arr[0];

        largest = arr[0];
        secondLargest = arr[1];
    }

    for (i = 2; i < n; i++) {

        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest = %d\n", secondSmallest);
    printf("Second Largest = %d\n", secondLargest);

    return 0;
}