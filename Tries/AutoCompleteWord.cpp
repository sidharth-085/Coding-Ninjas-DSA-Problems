#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

    public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
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
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }
    
    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void autoCompleteHelper(TrieNode* root, string pattern, string output) {
        if (root == NULL) {
            return;
        }

        // Step 1: Check if pattern is empty
        if (pattern.size() == 0) {
            if (root->isTerminal) {
                // Step 2: Found a word that matches the pattern, print it
                cout << output << endl;
            }

            // Step 3: Explore all children nodes recursively
            for (int i = 0; i < 26; i++) {
                TrieNode* childNode = root->children[i];
                if (childNode != NULL) {
                    string newOutput = output + childNode->data;
                    autoCompleteHelper(childNode, pattern, newOutput);
                }
            }
            return;
        }
        
        // Step 4: Get the index of the next character in the pattern
        int index = pattern[0] - 'a';

        // Step 5: Append the current character to the output
        output = output + pattern[0];

        // Step 6: Recursively call autoCompleteHelper with the child node corresponding to the next character
        TrieNode* childNode = root->children[index];
        autoCompleteHelper(childNode, pattern.substr(1), output);
    }

    void autoComplete(vector<string> input, string pattern) {
        for (int i = 0; i < input.size(); i++) {
            insertWord(input[i]);
        }
        string output = "";
        autoCompleteHelper(root, pattern, output);
    }

};