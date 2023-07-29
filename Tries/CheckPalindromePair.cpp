#include <vector>
#include <string>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode** children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode* root;

    bool add(TrieNode* root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != nullptr) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    bool isPalindromeHelper(string word, int start, int end) {
        if (start > end) {
            return true;
        }
        if (word[start] != word[end]) {
            return false;
        }
        int ans = isPalindromeHelper(word, start+1, end-1);
        return ans;
    }

    bool isWordPalindrome(string word) {
        int start = 0;
        int end = word.size() - 1;
        return isPalindromeHelper(word, start, end);
    }

    string reverseString(string word) {
        string reverse = "";
        for (int i=word.size()-1; i>=0; i--) {
            reverse = reverse + word[i];
        }
        return reverse;
    }

    bool checkRemainingBranchesInTrie(TrieNode *root, string word) {
        /*
        *
        * This function recursively explores all the branches from the root
        * while keeping track of the characters in the 'word' and checks
        * each word whenever the terminating condition is true.
        *
        * If the word is a palindrome, we return true and stop exploring the
        * other branches. If it is otherwise, we keep on checking the remaining
        * branches.
        *
        * Once all the branches are explored, and we don't find any branch or
        * word that makes itself a palindrome, we return false at last.
        *   
        */
        if (root->isTerminal) {
            if (isWordPalindrome(word)) {
                return true;
            }             
        }
        for (int i=0; i<26; i++) {
            TrieNode *childNode = root->children[i];
            if (childNode != NULL) {
                string forward = word + childNode->data; 
                if (checkRemainingBranchesInTrie(childNode, forward)) {
                    return true;
                }               
            }           
        }
        return false;
    }

    bool doesPairExistsFor(TrieNode *root, string word, int startIndex) {
        if (word.empty()) {
            return false;
        }

        if (startIndex == word.size()) {
            if (root->isTerminal) {
            /*
            * When there exists an exact match of the word we are
            * searching for in the Trie, irrespective of the trie
            * extends further in the same path.
            */
                return true;
            }
            /*
            * When trie extends further, there doesn't exist an exact
            * match of the string we are looking for.
            * However, it may happen that any of the branch
            * extending from root may form a palindrome.
            */
            return checkRemainingBranchesInTrie(root, "");
        }

        int index = word[startIndex] - 'a';
        TrieNode *child = root->children[index];

        if (child == NULL) {
            /*
            * This means that, down the line in the characters that we are
            * looking for against the word in the trie, the character doesn't
            * exist in the trie. This character can be anywhere in the range [0
            * - (word length-1)]
            */
            if (root->isTerminal) {
                return isWordPalindrome(word.substr(startIndex));
            }
            return false;
        }

        return doesPairExistsFor(child, word, startIndex+1);
    }

    bool isPalindromePairHelper(TrieNode *root, vector<string> words) {
        if (words.empty()) {
            return false;
        }
        for (int i=0; i<words.size(); i++) {
            bool ans = doesPairExistsFor(root, words[i], 0);
            if (ans) {
                return true;
            }
        }
        return false;
    } 

public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    bool isPalindromePair(vector<string> words) {
        for (int i=0; i<words.size(); i++) {
            string reversedWord = reverseString(words[i]);
            add(reversedWord);
        }
        bool ans = isPalindromePairHelper(root, words);
        return ans;
    }
};

/*

Here's a detailed explanation of how the function works:

Reverse the Words:

The function starts by iterating over each word in the input vector words.
For each word, it calls the reverseString function to obtain its reverse.
The reversed word is then added to the trie using the add function.

-> Check for Palindrome Pairs:

After adding all the reversed words to the trie, the function calls the isPalindromePairHelper function to check for palindrome pairs.

-> isPalindromePairHelper Function:

This function takes two parameters: a pointer to the current TrieNode (root) and the vector of words (words).
It iterates over each word in the words vector.
For each word, it calls the doesPairExistsFor function to check if there exists a pair in the trie such that their concatenation forms a palindrome.
If such a pair is found, the function returns true, indicating the existence of a palindrome pair.

-> doesPairExistsFor Function:

This function takes three parameters: a pointer to the current TrieNode (root), the word being checked (word), and the index of the character being processed in word (startIndex).
The function checks if the word is empty, which would indicate that the end of the word has been reached. If so, it returns false.
If the startIndex is equal to the length of word, it means that the trie path matches the word exactly.
If the root node is marked as a terminal node (indicating the end of a word) at this point, it returns true.
Otherwise, it calls the checkRemainingBranchesInTrie function to check if any remaining branches in the trie can form a palindrome.
If the above conditions are not met, the function continues checking the remaining characters in word.
It calculates the index of the next character to process.
If the child node corresponding to the character exists in the trie, it recursively calls itself with the child node, the word, and an incremented startIndex.
If the child node doesn't exist, it checks if the current root node is marked as a terminal node. If so, it checks if the remaining portion of word forms a palindrome by calling isWordPalindrome.
The function returns the result obtained from the recursive calls or checks.

-> checkRemainingBranchesInTrie Function:

This function recursively explores all the branches from the current root node while keeping track of the characters in word.
It checks each word whenever it encounters a terminal node in the trie.
If the word is a palindrome, it returns true and stops exploring other branches.
If the word is not a palindrome, it continues exploring the remaining branches.
Once all the branches are explored, and no branch or word forms a palindrome, it returns false.

-> Final Result:

The isPalindromePairHelper function returns true if any palindrome pair is found during the iteration over words.
The isPalindromePair function returns this result as its final output.
In summary, the isPalindromePair function checks for palindrome pairs by reversing each word, adding

*/