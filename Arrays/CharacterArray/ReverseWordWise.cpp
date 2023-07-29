#include <cstring>
void stringReverse(int start, int end, char *input) {
    while (start<=end) {
        char temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}
void reverseStringWordWise(char input[]) {
    int size = strlen(input);
    int start = 0;
    int end = size-1;
    stringReverse(start, end, input);
    for (int i=0; i<=size; i++) {
        if (input[i]==' ' or input[i]=='\0') {
            stringReverse(start, i-1, input);
            start = i+1;
        }
    }
}