#include <iostream>
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

// 1. BUILD TREE: FROM PREORDER AND INORDER

// PreOrder: Root : Left : Right
// InOrder: Left : Root : Right

BinaryTreeNode<int>* buildTree1(int *preOrder, int preLength, int *inOrder, int inLength) {
    if (preLength==0 || inLength==0) {
        return NULL;
    }
    int rootData = preOrder[0];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int rootIndex = 0;
    while (inOrder[rootIndex] != rootData) {
        rootIndex++;
    }
    // preLength = root + left + right => right = preLength - left - 1
    // inLength = left + root + right => right = inLength - left - 1
	// preLength = inLength in all cases.
    root->left = buildTree1(preOrder + 1, rootIndex, inOrder, rootIndex);
    root->right = buildTree1(preOrder + 1 + rootIndex, preLength - rootIndex - 1, 
                            inOrder + rootIndex + 1, inLength - rootIndex - 1);
    
    return root;
}

// 2. BUILD TREE: FROM POSTORDER AND INORDER

// PostOrder: Left : Right : Root
// InOrder: Left : Root : Right

BinaryTreeNode<int>* buildTree2(int *postOrder, int postLength, int *inOrder, int inLength) {
    if (postLength==0 || inLength==0) {
        return NULL;
    }
    int rootData = postOrder[postLength-1];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    int rootIndex = 0;
    while (inOrder[rootIndex] != rootData) {
        rootIndex++;
    }            
    // postLength = root + left + right => right = postLength - left - 1
    // inLength = left + root + right => right = inLength - left - 1
	// postLength = inLength in all cases.
    root->left = buildTree2(postOrder, rootIndex, inOrder, rootIndex);
    root->right = buildTree2(postOrder + rootIndex, postLength - rootIndex - 1, 
                            inOrder + rootIndex + 1, postLength - rootIndex - 1);
    return root;
}