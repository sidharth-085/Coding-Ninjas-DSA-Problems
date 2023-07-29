#include <iostream>
using namespace std;

int maxMoneyLooted(int *money, int numOfHouses) { // Brute Force Approach
    if (numOfHouses <= 0) {
		return 0;
	}	

	int option1 = maxMoneyLooted(money + 2, numOfHouses-2) + money[0];
	int option2 = maxMoneyLooted(money + 1, numOfHouses-1);

    // int option1 = maxMoneyLooted(money, numOfHouses-2) + money[numOfHouses-1];
	// int option2 = maxMoneyLooted(money, numOfHouses-1);

	return max(option1, option2);
}

int maxMoneyLootedHelper(int *money, int numOfHouses, vector<int> &ans) { // MEMOIZATION APPROACH
    if (numOfHouses <= 0) {
		return 0;
    }

    if (ans[numOfHouses] != -1) {
        return ans[numOfHouses];
    } 

    int option1 = maxMoneyLootedHelper(money + 2, numOfHouses-2, ans) + money[0];
	int option2 = maxMoneyLootedHelper(money + 1, numOfHouses-1, ans);

    // int option1 = maxMoneyLootedHelper(money, numOfHouses-2, ans) + money[numOfHouses-1];
	// int option2 = maxMoneyLootedHelper(money, numOfHouses-1, ans);

    ans[numOfHouses] = max(option1, option2);
	return max(option1, option2);
}

int maxMoneyLootedUsingMemoization(int *money, int numOfHouses) { // MEMOIZATION APPROACH
    vector<int> ans(numOfHouses+1, -1);
    return maxMoneyLootedHelper(money, numOfHouses, ans);
}

int maxMoneyLootedUsingDP(int *money, int numOfHouses) { // DP APPROACH
    vector<int> ans(numOfHouses+1, 0);
    ans[0] = 0;
    ans[1] = money[0];
    for (int i=2; i<numOfHouses+1; i++) {
        int option1 = ans[i - 2] + money[i-1];
        int option2 = ans[i - 1];
        ans[i] = max(option1, option2);
    }
    return ans[numOfHouses];
}