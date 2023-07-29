#include <iostream>
using namespace std;

/*int partitionArray(int arr[], int si, int ei) { // taking more time than second one.
	int count = 0;
	for (int i=si+1; i<=ei; i++) {
		if (arr[si] > arr[i]) {
			count++;
		}
	}
	swap(arr[si], arr[si+count]);
	int partitionIndex = si+count;
	int i = si; 
	int j = ei;
	while (i<=partitionIndex-1 and j>=partitionIndex+1) {
		if (arr[i] > arr[partitionIndex] and arr[j] < arr[partitionIndex]) {
			swap(arr[i], arr[j]);
			i++; 
			j--;
		}
		else if (arr[i] < arr[partitionIndex]) {
			i++;
		}
		else if (arr[j] > arr[partitionIndex]) {
			j--;
		}
	}
	return partitionIndex;
} */
class Node {
	public:
	int *data;
	Node *next;

	Node (int data) {
		this->data = new int;
		*(this->data) = data;
		next = NULL;
	}

};
int partitionArray(int arr[], int si, int ei) { // more faster option.
	int pivot = arr[ei];
	int i = si;
	for (int j = si; j <= ei; j++) {
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]); // it finds which element is smaller than pivot.
			i++;                  // then it swaps the smaller element with starting
		}                         // elements of array.
	}
	swap(arr[i], pivot); // here it swaps the pivot with that position where partition index lies.
	return i;
}


void quickSort(int arr[], int si, int ei) {
	if (si>=ei) {
		return;
	}
	int indexOfPartition = partitionArray(arr, si, ei);
	quickSort(arr, si, indexOfPartition-1);
	quickSort(arr, indexOfPartition+1, ei);
}