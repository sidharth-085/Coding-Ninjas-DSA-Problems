int allIndexes (int *arr, int size, int n, int *output) {
    
    if (size==0) {
        return 0;
    }

    int ans = allIndexes (arr, size-1, n, output);

    if (arr[size-1]==n) {
        output[ans] = size-1 ;
        return ans + 1;
    }

    else {
        return ans;
    }

}