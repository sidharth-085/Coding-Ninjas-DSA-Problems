#include <iostream>
using namespace std;

template <typename T> 
class TreeNode {
    public:
    T data;
    vector<TreeNode<int>*> children;
    TreeNode(T data) {
        this->data = data;
    }
};

// Method 1

pair<TreeNode<int>*, TreeNode<int>*> getSecondLargestNodeHelper(TreeNode<int>* root) {
    if (root == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    pair<TreeNode<int>*, TreeNode<int>*> ans(root, nullptr);

    for (int i = 0; i < root->children.size(); i++) {
        pair<TreeNode<int>*, TreeNode<int>*> childAns = getSecondLargestNodeHelper(root->children[i]);

        if (childAns.first->data > ans.first->data) {
            if (childAns.second == nullptr) {
                ans.second = ans.first;
                ans.first = childAns.first;
            } else {
                if (childAns.second->data > ans.first->data) {
                    ans.second = childAns.second;
                    ans.first = childAns.first;
                } else {
                    ans.second = ans.first;
                    ans.first = childAns.first;
                }
            }
        } else {
            if (ans.first->data != childAns.first->data && (ans.second == nullptr || childAns.first->data > ans.second->data)) {
                ans.second = childAns.first;
            }
        }
    }

    return ans;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    return getSecondLargestNodeHelper(root).second;
}

// Method 2

void secondMaxDataNode(TreeNode<int> *root, TreeNode<int>* &largest, TreeNode<int>* &secondLargest) {
    if (root==NULL) {
        return;
    }
    if (largest==NULL) {
        largest = root;
    }
    else if (root->data > largest->data) {
        secondLargest = largest;
        largest = root;
    }
    else if (secondLargest==NULL && root->data < largest->data) {
        secondLargest = root;
    }
    else if (root->data < largest->data && root->data > secondLargest->data) {
        secondLargest = root;
    }
    for (int i=0; i<root->children.size(); i++) {
        secondMaxDataNode(root->children[i], largest, secondLargest);
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    TreeNode<int> *largest = NULL;
    TreeNode<int> *secondLargest = NULL;
    secondMaxDataNode(root, largest, secondLargest);
    return secondLargest;
}