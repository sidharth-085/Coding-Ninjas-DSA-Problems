#include <cstring>
void trimSpaces(char input[]) {
    int size = strlen(input);
    char str[size+1];
    int j = 0;
    for (int i=0; i<size; i++) {
        if (input[i]!=' ') {
            str[j++] = input[i];
        }
    }
    str[j] = '\0';
    strcpy(input, str);
}