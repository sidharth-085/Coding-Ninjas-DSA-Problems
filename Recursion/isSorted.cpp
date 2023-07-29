bool isSorted1(int *arr, int size) {

    if (size==0 or size==1) {
        return true;
    }

    if (arr[0] > arr[1]) { // comparing new array's first and second elements.
        return false;
    }

    bool ans = isSorted1(arr+1, size-1);
    // if smaller array is sorted, then complete array is sorted
     // else whole array is unsorted
     return ans;
}

bool isSorted2(int *arr, int size) {
    if (size==0 or size==1) {
        return true;
    }
    bool ans = isSorted2(arr+1, size-1);
    if (!ans) return false;
    if (arr[0] > arr[1]) return true;
    else return false;
}
