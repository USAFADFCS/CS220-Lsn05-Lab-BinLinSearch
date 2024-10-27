/** functs.h
 * ===========================================================
 * Name: CS220
 * Section:
 * Project: Linear vs Binary Search (List ADT w/Array)
 * ===========================================================
 */

#define MAX_SIZE 2000000
enum { NS_PER_SECOND = 1000000000 };

/**
* @brief linear search of the given aray for the value
* @param n size of the array
* @param x value to search for
* @return index of item found
*/
int linearSearch(unsigned long long int arr[], unsigned long long int n, unsigned long long int x);

/**
* @brief binary search of the given aray for the value
* @param l left bound of the array
* @param r right bound of the array
* @return index of item found
*/
int binarySearch(unsigned long long int arr[], unsigned long long int l, unsigned long long int r, unsigned long long int x);

/**
* @brief does some math on the time hacks to give number of seconds and nanoseconds
* @param t1 first time hack
* @param t2 second time hack
*/
void subTimespec(struct timespec t1, struct timespec t2, struct timespec* td);
