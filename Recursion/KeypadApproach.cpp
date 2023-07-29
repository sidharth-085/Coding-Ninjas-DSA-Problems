#include <iostream>
#include <string>
using namespace std;

string str[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypad(int num, string output = "") { // Method 1
    if (num==0) {
        cout << output << endl;
    }
    int x = num%10;
    for (int i=0; i<str[x].size(); i++) {
        printKeypad(num/10, str[x][i] + output);
    }
}

int keypad(int num, string output[]) { // Method 2
    if (num == 0 or num==1) {
        output[0] = "";
        return 1;
    }
    int size = keypad(num / 10, output);
    int lastDigit = num % 10;
    for (int i=1; i<str[lastDigit].size(); i++) {
        for (int j=0; j<size; j++) {
            output[i*size+j] = output[j];
        }
    }
    for (int i=0; i<str[lastDigit].size(); i++) {
        for (int j=0; j<size; j++) {
            output[i*size+j] = output[i*size+j] + str[lastDigit][i];
        }
    }
    return size*str[lastDigit].size();
}
