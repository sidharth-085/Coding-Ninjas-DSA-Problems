#include <iostream>
using namespace std;

int fibonacciBF(int n) { // brute force method
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }

    int a = fibonacciBF(n-1);
    int b = fibonacciBF(n-2);

    return a + b;
}

int fibonacciMemoizationHelper(int n, int *arr) {
    if (n==0) {
        return 0;
    }
    if (n==1) {
        return 1;
    }

    if (arr[n] != -1) {
        return arr[n];
    }

    int a = fibonacciMemoizationHelper(n-1, arr);
    int b = fibonacciMemoizationHelper(n-2, arr);

    arr[n] = a + b;
    return arr[n];
}

int fibonacciMemoization(int n) {
    int *arr = new int[n+1];

    for (int i=0; i<n+1; i++) {
        arr[i] = -1;
    }

    return fibonacciMemoizationHelper(n, arr);
}

int fibonacciUsingDP(int n) {
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for (int i=2; i<n+1; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

/*

The code you provided includes three different implementations of the Fibonacci sequence: 
brute force method, memoization, and dynamic programming (DP). Here's an overview of each 
implementation:

-> Brute Force Method:

This implementation uses a recursive approach to calculate the Fibonacci number.

It checks for the base cases (n = 0 and n = 1) and returns the corresponding Fibonacci 
numbers.

For other values of n, it recursively calculates the (n-1)th and (n-2)th Fibonacci numbers 
and returns their sum.

This method has exponential time complexity since it recalculates Fibonacci numbers 
multiple times.

-> Memoization:

The memoization technique optimizes the brute force method by storing previously 
calculated Fibonacci numbers in an array.

The fibonacciMemoizationHelper function takes an additional arr parameter, which is an 
array to store the Fibonacci numbers.

Before calculating the Fibonacci number for a particular value of n, it checks if the 
number already exists in the arr array.

If it does, the stored value is returned; otherwise, the Fibonacci number is calculated 
recursively and stored in the array before returning it.

This approach significantly reduces the number of redundant calculations and improves the 
time complexity to linear (O(n)).

-> Dynamic Programming (DP):

The DP approach also optimizes the Fibonacci calculation by utilizing an array to store 
previously computed Fibonacci numbers.

In the fibonacciUsingDP function, an array arr is initialized with the base cases 
(Fibonacci numbers for n = 0 and n = 1).

Starting from the third index (n = 2), it iteratively calculates the Fibonacci numbers 
by summing up the two previous Fibonacci numbers.

Finally, it returns the Fibonacci number at the nth index of the array.

This approach also has a linear time complexity (O(n)).

It's worth noting that the brute force method is the least efficient among the three 
implementations, while memoization and dynamic programming offer significant performance
improvements by avoiding redundant calculations.

*/