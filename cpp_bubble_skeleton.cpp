//
// template C++ code for doing bubblesort, W. Bethel, SFSU, 2/2023
//
// Robel Kasahun Ayelew
// 2253-CSC-656-01, Coding Project #1
// 02/10/2025
// Sort an array a of size n = 10 random integers in ascending order using Bubble Sort algorithm.
//

// Function Prototypes
/**
 * prints an array of size n
 * @param array is the collection of integers to be printed out
 * @param n size of the array
 */
void print_array(int* array, const int n);

/**
 * sorts a given array of size n in ascending order
 * using Bubble Sort algorithm
 *
 * @param array is the collection of integer of size n
 *              that will be sorted in ascending order
 *
 * @param n is the size of the array
 */
void sort(int* array, const int n);

/**
 * swaps the values of a and b
 * @param a is the first integer number to be swapped
 * @param b is the second intger number to be swapped
 */
void swap(int& a, int& b);

/**
 * inner loop that do swapping and comparing values
 */
int innerLoop(const int i, int* array, const int n);

#include <iostream>
#include <unistd.h>

int main(int ac, char* av[]) {
    int a[] = {-2, -1, 0, 64, 24, 88, 41, 22, 65, 31};
    int n = sizeof(a) / sizeof(int);

    std::cout << " a before sort " << std::endl;

    // print out the contents of a before the sort
    // insert your code here
    print_array(a, n);

    // do the sort into ascending order. 
    sort(a, n);
    // insert your code here
    std::cout << "\n a after sort " << std::endl;
    print_array(a, n);


    // print out the contents of a after the sort
    // insert your code here
}
// EOF

// Function Definitions
/**
 * prints an array of size n
 * @param array is the collection of integers to be printed out
 * @param n size of the array
 */
void print_array(int* array, const int n) {
    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * swaps the values of a and b
 * @param a is the first integer number to be swapped
 * @param b is the second intger number to be swapped
 */
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * sorts a given array of size n in ascending order
 * using Bubble Sort algorithm
 *
 * @param array is the collection of integer of size n
 *              that will be sorted in ascending order
 *
 * @param n is the size of the array
 */
void sort(int* array, const int n) {
    for (int i = 0; i < n; i++) {
        int result = innerLoop(i, array, n);
        if (result == 1) {
            std::cout << "\nChange were made on loop #" << (i) << std::endl;
        }
        else {
            std::cout << "\nChange were not made on loop #" << (i) << std::endl;
        }
        print_array(array, n);
    }
}

/**
 * Swaps and compares values of the array
 */
int innerLoop(const int i, int* array, const int n) {
    int swaps_counter = 0;
    for (int j = i + 1; j < n; j++) {
        if (array[i] >= array[j]) {
            swap(array[i], array[j]);
            // change made to the array
            ++swaps_counter;
        }
    }

    // returns 1 if changes were made
    // Otherwise, it returns 0
    return (swaps_counter > 0) ? 1 : 0;
}