#include <iostream>
#include <string>
using namespace std;

int subsequencesOfString(string str, string* output) {
    if (str.size() == 0) {
        output[0] = "";
        return 1; // returning 1 for one subsequence (2^0 = 1).
    }
    int ans = subsequencesOfString(str.substr(1), output);
    for (int i = 0; i < ans; i++) {
        output[i + ans] = str[0] + output[i];
    }
    return 2 * ans;
}

void subsequencesOfString(string str, string output) {
    if (str.size()==0) {
        cout << output << endl;
        return;
    }
    subsequencesOfString(str.substr(1), output);
    subsequencesOfString(str.substr(1), output + str[0]);
    return;
}

int main() {
    // Method 1: 

    cout << "Method 1" << endl;

    string str = "abcd";
    int strSize = pow(2, str.size());
    string *output = new string[strSize];
    int size = subsequencesOfString(str, output);
    for (int i=0; i<size; i++) {
        cout << output[i] << endl;
    }
    delete [] output;

    // Method 2:

    cout << "Method 2" << endl;

    string str1 = "abcd";
    string output = "";
    subsequencesOfString(str1, output);
}