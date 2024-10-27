/** lab05.c
 * ===========================================================
 * Name: CS229
 * Section:
 * Project: Linear vs Binary Search (List ADT w/Array)
 * ===========================================================
 */
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "functs.h"

int main() {

    // Allocate mem for the array and also setup timing variables
    unsigned long long int *array = malloc(MAX_SIZE * sizeof(unsigned long long));
    struct timespec startn, finishn, delta;

    // Initialize the array with sorted values
    for (unsigned long long int i = 0; i < MAX_SIZE; i++) {
        array[i] = i;
    }
    
    // Testing Linear Search
    printf("  Search        n        time  \n");
    printf("--------------------------------\n");
    for (unsigned long long int i = MAX_SIZE / 10; i <= MAX_SIZE; i+=MAX_SIZE / 10) {
        clock_gettime(CLOCK_REALTIME, &startn); // get a time hack prior to search
        linear_search(array, i, i * .99); // running the search with the item to find near the end
        clock_gettime(CLOCK_REALTIME, &finishn); // time hack after search
        sub_timespec(startn, finishn, &delta);  // do the math on the time
        printf("  linear %10ld  %d.%.9ld\n", (long int)i, (int)delta.tv_sec, delta.tv_nsec);
    }

    // Testing Binary Search 
    printf("  Search        n        time  \n");
    printf("--------------------------------\n");
    for (unsigned long long int i = MAX_SIZE / 10; i <= MAX_SIZE; i+=MAX_SIZE / 10) {
        clock_gettime(CLOCK_REALTIME, &startn); // get a time hack prior to search
        binary_search(array, 0, i, i * .99); // get a time hack prior to search
        clock_gettime(CLOCK_REALTIME, &finishn); // time hack after search
        sub_timespec(startn, finishn, &delta); // do the math on the time
        printf("  binary %10ld  %d.%.9ld\n", (long int)i, (int)delta.tv_sec, delta.tv_nsec);
    }

    return 0;
}
