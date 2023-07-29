#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Generate Huffman tree and assign codes to characters
void generateCodes(Node* root, string code, unordered_map<char, string> &codes) {
    if (root == nullptr)
        return;

    if (root->data != '\0') {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Build Huffman tree and return the root node
Node* buildHuffmanTree(const string& text) {
    // Calculate frequency of each character
    unordered_map<char, int> freq;
    for (int i=0; i<text.size(); i++) {
        freq[text[i]]++;
    }

    // Create a priority queue to store nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    unordered_map<char, int>::iterator it; 
    for (it = freq.begin(); it != freq.end(); it++) {
        Node* leaf = new Node(it->first, it->second);
        pq.push(leaf);
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
    // Return the root node of the Huffman tree
    return pq.top();
}

// Compress the given text using Huffman coding
string compress(const string& text) {
    // Build Huffman tree
    Node* root = buildHuffmanTree(text);

    // Generate Huffman codes for each character
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    // Compress the text using the generated Huffman codes
    string compressedText;
    for (int i=0; i<text.size(); i++) {
        compressedText = compressedText + codes[text[i]];
    }

    return compressedText;
}

// Decompress the given text using Huffman coding
string decompress(const string& compressedText, Node* root) {
    string decompressedText;
    Node* currentNode = root;

    for (int i=0; i<compressedText.size(); i++) {
        if (compressedText[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (currentNode->data != '\0') {
            decompressedText = decompressedText + currentNode->data;
            currentNode = root;
        }
    }

    return decompressedText;
}

int main() {
    string text = "ABCDDBCAYYYZZ";

    // Compress the text
    string compressedText = compress(text);
    cout << "Compressed text: " << compressedText << endl;

    // Decompress the text
    Node* root = buildHuffmanTree(text);
    string decompressedText = decompress(compressedText, root);
    cout << "Decompressed text: " << decompressedText << endl;

    return 0;
}
