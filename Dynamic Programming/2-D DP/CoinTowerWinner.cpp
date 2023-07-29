#include <iostream>
#include <string>
using namespace std;

// Brute Force Approach
bool isWinning(int coins, int x, int y) {
    if (coins == 0) {
        return false; // Base case: No coins remaining, current player loses
    }

    // Try all possible moves and check if any leads to a losing position for the opponent
    if (coins - 1 >= 0 && isWinning(coins - 1, x, y) == false) {
        return true; // If at least one move leads to a losing position for the opponent, current player wins
    }

    if (coins - x >= 0 && isWinning(coins - x, x, y) == false) {
        return true;
    }

    if (coins - y >= 0 && isWinning(coins - y, x, y) == false) {
        return true;
    }

    return false; // If none of the moves lead to a losing position for the opponent, current player loses
}

string findWinnerBF(int coins, int x, int y) {
    if (isWinning(coins, x, y)) {
        return "Beerus"; // If Beerus can win from the given state, return "Beerus"
    }
    return "Whis"; // Otherwise, return "Whis"
}

// Memoization Approach
bool isWinningMemo(int coins, int x, int y, vector<bool> &ans) {
    if (coins == 0) {
        return false; // Base case: No coins remaining, current player loses
    }

    if (ans[coins] != false) {
        return ans[coins]; // If the result is already memoized, return it
    }

    // Try all possible moves and check if any leads to a losing position for the opponent
    if (coins - 1 >= 0 && isWinningMemo(coins - 1, x, y, ans) == false) {
        ans[coins] = true; // Memoize the result and return true
        return true;
    }

    if (coins - x >= 0 && isWinningMemo(coins - x, x, y, ans) == false) {
        ans[coins] = true;
        return true;
    }

    if (coins - y >= 0 && isWinningMemo(coins - y, x, y, ans) == false) {
        ans[coins] = true;
        return true;
    }

    ans[coins] = false; // Memoize the result and return false
    return false;
}

string findWinnerMemo(int coins, int x, int y) {
    vector<bool> ans(coins+1, false); // Create a memoization vector to store results for each subproblem
    // we can use unordered_map also.

    if (isWinningMemo(coins, x, y, ans)) {
        return "Beerus"; // If Beerus can win from the given state, return "Beerus"
    }
    return "Whis"; // Otherwise, return "Whis"
}
 
string findWinnerDP(int coins, int x, int y) { // Dp Approach
    vector<bool> ans(coins+1, false);
    // Create a memoization vector to store results for each subproblem

    for (int i=1; i<coins+1; i++) {
        if (i-1 >= 0 && ans[i-1] == false) { // if isWinning for coins - 1 is false, player wins.
            ans[i] = true;
        }
        else if (i-x >= 0 && ans[i-x] == false) { // if isWinning for coins - x is false, player wins.
            ans[i] = true;
        }
        else if(i-y >= 0 && ans[i-y] == false) { // if isWinning for coins - y is false, player wins.
            ans[i] = true;
        }
        else {
            ans[i] = false; // if isWinning is true, then player loses.
        }
    }

    int finalAns = ans[coins];
    if (finalAns) { // if finalAns is true, beerus wins.
        return "Beerus";
    }
    return "Whis"; // else Whis wins.
}