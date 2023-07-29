#include <string>
#include <iostream>
using namespace std;

// Method 1 returning output array of Codes

int getCodes(string input, string output[]) {
    if (input.size() == 0) {
        output[0] = "";
        return 1;
    }
    int first = input[0]-48;
    char firstChar = first + 'a' -1;
    char secondChar = '\0';
    string output1[500];
    int size1 = getCodes(input.substr(1), output1);
    string output2[500];
    int size2 = 0;
    if (input[1]!='\0') {
        int second = 10*first + (input[1] - 48);
        if (second >= 10 and second <= 26) {
            secondChar = second + 'a' -1;
            size2 = getCodes(input.substr(2), output2);
        }
    }
    int k=0;
    for (int i=0; i<size1; i++) {
        output[k] = firstChar + output1[i];
        k++;
    }
    for (int i=0; i<size2; i++) {
        output[k] = secondChar + output2[i];
        k++;
    }
    return k;
}

// Method 2 printing the codes from function itself.

void helper(string input, string output) {
    if (input.size()==0) {
        cout << output << endl;
        return;
    }

    int first = input[0] - 48;
    char firstChar = first + 'a' - 1;
    helper(input.substr(1), output+firstChar);

    int second = 10*first + (input[1]-48);
    if (second >= 10 and second <= 26) {
        char secondChar = second + 'a' - 1;
        helper(input.substr(2), output+secondChar);
    }
    return;
}

void printAllPossibleCodes(string input) {
    helper(input, "");
}