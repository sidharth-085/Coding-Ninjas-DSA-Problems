#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkRedundantBrackets(string str) {
    stack<char> input;
    int count = 0;
    for (int i=0; i<str.size(); i++) {
        if (str[i]==')') {
            while (input.top()!='(') {
                input.pop();
                count++;
            }
            input.pop();
            if (count==0 or count==1) {
                return true;
            }
            else {
                count = 0;
            }
        }
        else {
            input.push(str[i]);
        }
    }
    return false;
}

int main() {

}