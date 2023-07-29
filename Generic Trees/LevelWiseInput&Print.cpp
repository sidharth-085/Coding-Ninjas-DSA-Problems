#include <iostream>
#include <vector>
#include <queue>
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
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the root data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue <TreeNode<int>*> *newNodes = new queue <TreeNode<int>*>();
    // MADE A QUEUE OF TYPE TREENODE POINTERS WHICH STORES TREENODES AND POPS.

    newNodes->push(root); // Enters first TreeNode i.e. root node in queue.
    while (!newNodes->empty()) {
        TreeNode<int> *front = newNodes->front();
        newNodes->pop();
        
        int childNum;
        cout << "Enter number of children for " << front->data << " : ";
        cin >> childNum;
        for (int i=0; i<childNum; i++) {
            int childData;
            cout << "Enter data for " << (i+1) << "th Children of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            newNodes->push(childNode); 
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root) {
    queue <TreeNode<int>*> *newNodes = new queue <TreeNode<int>*>();
    newNodes->push(root);
    while (!newNodes->empty()) {
        TreeNode<int> *front = newNodes->front();
        newNodes->pop();
        cout << front->data << " : ";
        if (front->children.size()==0) {
            cout << "0";
        }
        for (int i=0; i<front->children.size(); i++) {
            if (i==front->children.size()-1) {
                cout << front->children[i]->data;
            }
            else {
                cout << front->children[i]->data << ",";
            }
            newNodes->push(front->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter the root data : ";
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue <TreeNode<int>*> *newNodes = new queue <TreeNode<int>*>();
    // MADE A QUEUE OF TYPE TREENODE POINTERS WHICH STORES TREENODES AND POPS.

    newNodes->push(root); // Enters first TreeNode i.e. root node in queue.
    while (!newNodes->empty()) {
        TreeNode<int> *front = newNodes->front();
        newNodes->pop();
        int childNum;
        cout << "Enter number of children for " << front->data << " : ";
        cin >> childNum;
        for (int i=0; i<childNum; i++) {
            int childData;
            cout << "Enter data for " << (i+1) << "th Children of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            front->children.push_back(childNode);
            newNodes->push(childNode); 
        }
    }
    return root;
}

void printLevelWise(TreeNode<int> *root) {
    queue <TreeNode<int>*> *newNodes = new queue <TreeNode<int>*>();
    newNodes->push(root);
    while (!newNodes->empty()) {
        TreeNode<int> *front = newNodes->front();
        newNodes->pop();
        cout << front->data << " : ";
        for (int i=0; i<front->children.size(); i++) {
            if (i==front->children.size()-1) {
                cout << front->children[i]->data;
            }
            else {
                cout << front->children[i]->data << ",";
            }
            newNodes->push(front->children[i]);
        }
        cout << endl;
    }
}

int main() {
    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    free(root);
}