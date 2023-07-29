#include <iostream>
#include <vector>
using namespace std;

template <typename T> // Tree Node using Template for different data types.
class TreeNode {
    public:
    T data;
    vector<TreeNode*> children;
    // vector<TreeNode<T>* 

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i=0; i<root->children.size(); i++) {
            delete children[i];
        }  
    }
};

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter the Root Data : ";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int num;
    cout << "Enter the number of children of " << rootData << ": ";
    cin >> num;
    // Recursive Calls for other Child trees.
    for (int i=0; i<num; i++) {
        TreeNode<int> *newRoot = takeInput();
        root->children.push_back(newRoot);
    }
    return root;
}

// For Example:
//                       1
//           2           3           4
//         5    6      7    8          9

void printTree(TreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    cout << root->data << ": ";
    for (int i=0; i<root->children.size(); i++) {
        cout << root->children[i]->data << " ";
    } 
    cout << endl;

    // Recursive Calls for other Child trees.
    for (int i=0; i<root->children.size(); i++) {
        printTree(root->children[i]);
    }   
}

/*
Output: 

1:2 3 4 
2:5 6 
5:
6:
3:7 8 
7:
8:
4:9 

*/

void deleteTree(TreeNode<int> *root) {
    for (int i=0; i<root->children.size(); i++) {
        deleteTree(root->children[i]);
    } 
    delete root;
}

int main() {
    TreeNode<int> *root = takeInput();
    printTree(root);
    delete root; // both will delete the given tree.
    // deleteTree(root);
}

