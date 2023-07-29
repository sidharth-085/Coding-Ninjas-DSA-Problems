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

    bool searchWord(TrieNode *root, string word) {
        if (word.empty()) {
            return true;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL) {
            // Node for the current character doesn't exist, word is not present
            return false;
        }

        // Recursively search for the remaining characters of the word
        bool ans = searchWord(root->children[index], word.substr(1));
        return ans;
    }

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
            } 
            else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } 
        else {
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

    bool search(string word) {
        bool ans = searchWord(root, word);
        return ans;
    }

    bool patternMatching(vector<string> words, string pattern) {
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                insertWord(words[i].substr(j));
            }
        }
        return search(pattern);
    }
};