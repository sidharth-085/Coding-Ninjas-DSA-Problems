int sum1(int *arr, int size) {
  if (size==0) {
    return 0;
  }
  if (size==1) {
    return arr[0];
  }
  return arr[size-1] + sum1(arr, size-1);
}

int sum2(int *arr, int size) {
  if (size==0) {
    return 0;
  }
  if (size==1) {
    return arr[0];
  }
  return arr[0] + sum2(arr+1, size-1);
}