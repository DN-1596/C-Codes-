// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 
#include<iostream>
#include<queue>
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

void levelordertraversal(BstNode *root) {
    if (root == NULL) return;
    queue<BstNode *> Q; 
    Q.push(root);
    while(!Q.empty()){
        BstNode* temp = Q.front(); //execution of the current level
        cout<<temp->data<<endl;
        if (temp->left != NULL) Q.push(temp->left); // saving the children for the next level
        if (temp->right != NULL) Q.push(temp->right);
        Q.pop();     
    }
}

int main() {
	BstNode* root = NULL;  // Creating an empty tree
	/*Code to test the logic*/
	root = Insert(root,6);	
	root = Insert(root,4);	
	root = Insert(root,2);
	root = Insert(root,1);
	root = Insert(root,3);
	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,7);
	root = Insert(root,9);
	root = Insert(root,8);
	root = Insert(root,11);
	// Level order traversal  
	levelordertraversal(root);
	return 0;
}