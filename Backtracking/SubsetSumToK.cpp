#include <iostream>
using namespace std;

void findSubsets(vector<int>& nums, int k, vector<int>& currentSet, int currentIndex, int currentSum) {
    if (currentSum == k) {
        // Subset found with sum equal to target
        for (int num : currentSet) {
            cout << num << " ";
        }
        cout << endl;
    }

    if (currentIndex == nums.size() || currentSum > k) {
        return;
    }

    // Include the current element in the subset
    currentSet.push_back(nums[currentIndex]);
    findSubsets(nums, k, currentSet, currentIndex + 1, currentSum + nums[currentIndex]);

    // Exclude the current element from the subset
    // backtrack
    currentSet.pop_back();
    findSubsets(nums, k, currentSet, currentIndex + 1, currentSum);
}

void subsetsWithSumK(vector<int>& nums, int k) {
    vector<int> currentSet;
    findSubsets(nums, k, currentSet, 0, 0);
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i=0; i<testCase; i++) {
        int size;
        cin >> size;

        int k;
        cin >> k;

        vector<int> vec;
        for (int i=0; i<size; i++) {
            int var;
            cin >> var;
            vec.push_back(var);
        }

        subsetsWithSumK(vec, k);
    }

}