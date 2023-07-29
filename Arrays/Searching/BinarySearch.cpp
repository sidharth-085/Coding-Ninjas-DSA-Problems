#include <iostream>
using namespace std;

int binarySearch(int *input, int size, int val) {
    int start = 0;
    int end = size-1;

    while (start <= end) {
        int mid = (start + end)/2;
        if (val == input[mid]) {
            return mid;
        }
        else if (val < input[mid]) {
            end = mid -1;
        }
        else {
            start = mid+1;
        }
    }
    return -1;
}

int main() {

}