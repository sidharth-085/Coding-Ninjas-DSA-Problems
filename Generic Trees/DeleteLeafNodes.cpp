#include <iostream>
#include <vector>
using namespace std;

/*

template <typename T> 
class TreeNode {
    public:
    T data;
    vector<TreeNode<int>*> children;
    TreeNode(T data) {
        this->data = data;
    }
};

TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
	if (root==NULL) {
		return NULL;
	}
    if (root->children.size()==0) {
        delete root;
        return NULL;
    }
    for (int i=0; i<root->children.size(); i++) {
        root->children[i] = removeLeafNodes(root->children[i]);        
    }
    return root;
}

*/

template <typename T>
class TreeNode {
	TreeNode<T>** children;
	int childCount;
    	int maxChildCount;
	public:
		T data;
		
		TreeNode(T data) {
			this->data = data;
			childCount = 0;
			children = new TreeNode<T>*[10];
		   	maxChildCount = 10;
        }	

		int numChildren() {
			return childCount;
		}

		void addChild(TreeNode<T>* child) {
			children[childCount] = child;
			childCount++;
            if(childCount == maxChildCount) {
	            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
        	    for(int i = 0; i < maxChildCount; i++) {
	                childrenNew[i] = children[i];
        	     }
	        	 maxChildCount *= 2;
        	        children = childrenNew;
	        }
		}

		TreeNode<T>* getChild(int index) {
			return children[index];
		}

		void setChild(int index, TreeNode<T>* child) {
			children[index] = child;
		}
    
    void removeChild(int i) {
        for(int j = i + 1; j < childCount; j++) {
            children[j - 1] = children[j];
        }
        childCount--;
    }
};

// METHOD 1

TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if (root == NULL || root->numChildren() == 0) {
        return NULL;
    }
    for (int i = root->numChildren() - 1; i >= 0; i--) {
        TreeNode<int>* child = root->getChild(i);
        if (child->numChildren() == 0) {
            root->removeChild(i);
        }
    }
    for (int i = 0; i < root->numChildren(); i++) {
        TreeNode<int>* modifiedChild = removeLeafNodes(root->getChild(i));
        root->setChild(i, modifiedChild);
    }
    return root;
}

// METHOD 2

TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if (root==NULL || root->numChildren() == 0) {
        return NULL;
    }  
    vector<int> vec;
    for (int i=0; i<root->numChildren(); i++) {
        TreeNode<int> *children = root->getChild(i);
        if (children->numChildren() == 0) {
            vec.push_back(i);
        }         
    }
    for (int i=vec.size()-1; i>=0; i--) {
        root->removeChild(vec[i]);                       
    }
    for (int i=0; i<root->numChildren(); i++) {
        TreeNode<int> *child = removeLeafNodes(root->getChild(i));
                   
    }
    return root;
}