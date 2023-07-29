#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int size, int sum) { // it only count the number of pairs
	int count = 0;
	unordered_map<int, int> freq;		
	for (int i=0; i<size; i++) {
		int complement = sum - arr[i];
		if (freq.count(complement)>0) {
			count = count + freq[complement];
		}
		freq[arr[i]]++;
	}
	return count;
}

vector<vector<int>> pairSum(vector<int>& arr, int sum) { // it returns the correct number of pairs.
    vector<vector<int>> ans;
	unordered_map<int, int> freq;		
	for (int i=0; i<arr.size(); i++) {
		int complement = sum - arr[i];
		for (int j=0; j<freq[complement]; j++) {
            ans.push_back({min(arr[i], complement), max(arr[i], complement)});
        }
		freq[arr[i]]++;
	}
    sort(ans.begin(), ans.end());
	return ans;
}