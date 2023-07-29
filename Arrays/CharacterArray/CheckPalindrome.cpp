#include <cstring>
bool checkPalindrome(char str[]) {
    int len = strlen(str);
     char newStr[len+1];
     for (int i=len-1; i>=0; i--) {
         newStr[len-1-i] = str[i];
     }
     newStr[len] = '\0';
     if (!strcmp(str, newStr)) {
         return true;
     }
     return false;
}
