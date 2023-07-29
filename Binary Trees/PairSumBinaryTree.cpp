#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

void treeToVector(BinaryTreeNode<int> *root, vector<int> &output) {
    if (root==NULL) {
        return;
    }
    output.push_back(root->data);
    treeToVector(root->left, output);
    treeToVector(root->right, output);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if (root==NULL) {
        return;
    }
    vector<int> vec;
    treeToVector(root, vec);
    sort(vec.begin(), vec.end());

    int i = 0; 
    int j = vec.size() - 1;
    while (i<j) {
        if (vec[i] + vec[j] == sum) {
            cout << vec[i] << " " << vec[j] << endl;
            i++;
            j--;
        }
        else if (vec[i] + vec[j] < sum) {
            i++;
        }
        else {
            j--;
        }
    }
}