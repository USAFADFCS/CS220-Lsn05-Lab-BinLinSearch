/** functs.c
 * ===========================================================
 * Name: CS220
 * Section:
 * Project: Linear vs Binary Search (List ADT w/Array)
 * ===========================================================
 */
#include <stdio.h>
#include <sys/time.h>
#include "functs.h"

 int linear_search(unsigned long long int arr[], unsigned long long int n, unsigned long long int x) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;  // element not found
}

int binary_search(unsigned long long int arr[], unsigned long long int l, unsigned long long int r, unsigned long long int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;  // To avoid overflow 

        if (arr[m] == x) 
            return m; 

        if (arr[m] < x) 
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;  // element not found
}
    
void sub_timespec(struct timespec t1, struct timespec t2, struct timespec *td) {
    td->tv_nsec = t2.tv_nsec - t1.tv_nsec;
    td->tv_sec  = t2.tv_sec - t1.tv_sec;
    if (td->tv_sec > 0 && td->tv_nsec < 0)
    {
        td->tv_nsec += NS_PER_SECOND;
        td->tv_sec--;
    }
    else if (td->tv_sec < 0 && td->tv_nsec > 0)
    {
        td->tv_nsec -= NS_PER_SECOND;
        td->tv_sec++;
    }
}