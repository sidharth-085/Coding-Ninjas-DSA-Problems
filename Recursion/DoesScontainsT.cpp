#include <iostream>
#include <cstring>
using namespace std;

bool doesScontainsT(char large[] , char small[]) {
    if (strlen(large) == 0) {
        return false;
    }

    if (strlen(small) == 0) {
        return true;
    }

    if (large[0] != small[0]) {
        return doesScontainsT(large+1, small);
    }

    return doesScontainsT(large+1, small+1);
}