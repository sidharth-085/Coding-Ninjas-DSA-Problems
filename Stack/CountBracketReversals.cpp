#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string str) {
    if (str.size()%2!=0) {
        return -1;
    }
    stack<int> input;
    for (int i=0; i<str.size(); i++) {
        if (str[i]=='{') {
            input.push(str[i]);
        }
        else {
            if (input.empty()) {
                input.push(str[i]);
            }
            else {
                if (input.top()=='{') {
                    input.pop();
                }
                else {
                    input.push(str[i]);
                }
            }
        }
    }
    int count = 0;
    while (!input.empty()) {
        char c1 = input.top();
        input.pop();
        char c2 = input.top();
        input.pop();
        if (c1==c2) {
            count++;
        }
        else if (c1=='{' and c2=='}'){
            count = count + 2;
        }
    }
    return count;
}

#include <string>
#include <algorithm>

bool isSymmetric(const std::string& substring) {
    int halfLength = substring.length() / 2;

    for (int i = 0; i < halfLength; i++) {
        if ((substring[i] != '<' && substring[i] != '?') ||
            (substring[i + halfLength] != '>' && substring[i + halfLength] != '?')) {
            return false;
        }
    }

    return true;
}

int solution(string& S) {
    int longestLength = 0;

    for (int i = 0; i < S.length(); i++) {
        for (int j = i + 1; j <= S.length(); j++) {
            std::string substring = S.substr(i, j - i);

            if (isSymmetric(substring)) {
                int length = j - i;
                longestLength = std::max(longestLength, length);
            }
        }
    }

    return longestLength;
}

#include <string>
#include <algorithm>

int longestSymmetricSubstring(string str, char center) {
    int N = str.size();
    int left = 0, right = 0;
    int maxSymmetricLength = 0;

    while (right < N) {
        if (str[left] == str[right] || str[left] == '?' || str[right] == '?') {
            left--;
            right++;
        } else {
            break;
        }
    }

    while (left >= 0 && right < N) {
        if ((str[left] == str[right] || str[left] == '?' || str[right] == '?') &&
            (str[left] == center || str[right] == center || str[left] == '?' || str[right] == '?')) {
            maxSymmetricLength += 2;
            left--;
            right++;
        } else {
            break;
        }
    }

    return maxSymmetricLength;
}

int solution(string& S) {
    int N = S.size();
    int maxSymmetricLength = 0;

    for (int i = 0; i < N - 1; i++) {
        maxSymmetricLength = max(maxSymmetricLength, longestSymmetricSubstring(S.substr(i, 2), '<'));
        maxSymmetricLength = max(maxSymmetricLength, longestSymmetricSubstring(S.substr(i, 2), '>'));
    }

    return maxSymmetricLength;
}


int main() {

}