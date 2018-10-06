// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
	int data; 
	BstNode* left;
	BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// To insert data in BST, returns address of root node 
BstNode* Insert(BstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int findmin(BstNode *root) {
    if (root == NULL ) return -1;
    BstNode *temp; 
    temp = root ;
    while(temp->left != NULL) {
        temp= temp->left;
    }
    return temp->data;
}
int findheight(BstNode *root) {
    if (root == NULL) {
        return -1; // return 0 if you wanna count no. of nodes
    }
    int leftheight = findheight(root->left);
    int rightheight = findheight(root->right);
    return max(leftheight,rightheight)+1;
}
int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);
	// Ask user to enter a number.  
	if(Search(root,25) == true) cout<<25<<": Found\n";
	else cout<<"Not Found\n";
	int x = findmin(root);
	cout<<"Min value: "<<x<<endl;
    x = findheight(root);
	cout<<"Height of the tree: "<<x<<endl;
	return 0;
}