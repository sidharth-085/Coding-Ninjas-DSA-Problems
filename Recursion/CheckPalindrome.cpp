#include <cstring>
bool checkSmallPalindrome(char *input, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (input[start] != input[end]) {
        return false;
    }
    return checkSmallPalindrome(input, start+1, end-1);
}

bool checkPalindrome(char input[]) {
    return checkSmallPalindrome(input, 0, strlen(input)-1);
}