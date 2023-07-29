#include <cstring>
void replaceCharacter(char input[], char c1, char c2) {
    int len = strlen(input);
    for (int i=0; i<len; i++) {
        if (input[i]==c1) {
            input[i] = c2;
        }
    }
}