#include <algorithm>
using namespace std;

int maximumProfit(int budget[], int size) {
    sort(budget, budget+size);

    int maxProfit = 0;
    for (int i=0; i<size; i++) {
        int currentPrice = budget[i];
        int currentProfit = currentPrice*(size-i);
        if (maxProfit < currentProfit) {
            maxProfit = currentProfit;
        }
    }
    return maxProfit;
}