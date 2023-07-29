#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    if (str[0]==')') {
        return false;
    }
    stack <char> Stack;
    for (int i=0; i<str.size(); i++) {
        if (str[i]=='(') {
            Stack.push(str[i]);
        }
        else if (str[i]==')') {
            if (Stack.top()=='(' or Stack.empty()) {
                Stack.pop();
            }
            else {
                return false; // it means Stack.top()==')' and it does not closes the bracket.
            }
        }
    }
    return Stack.empty();
}

int main() {

}