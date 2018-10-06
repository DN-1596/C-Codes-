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

void preordertraversal(BstNode *root) {
    if (root == NULL) return ;
    cout<<root->data<<" ";
    if (root->left != NULL) preordertraversal(root->left);
    if (root->right != NULL) preordertraversal(root->right);
}


void inordertraversal(BstNode *root) {
    if (root == NULL) return ;
    if (root->left != NULL) inordertraversal(root->left);
    cout<<root->data<<" ";
    if (root->right != NULL) inordertraversal(root->right);
}
void postordertraversal(BstNode *root) {
    if (root == NULL) return ;
    if (root->left != NULL) postordertraversal(root->left);
    if (root->right != NULL) postordertraversal(root->right);
    cout<<root->data<<" ";
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
	// Depth-First traversal techniques 
	cout<<"Pre-order traversal: ";
	preordertraversal(root);
	cout<<endl;
	cout<<"Inorder traversal: ";
	inordertraversal(root);
	cout<<endl;
	cout<<"Postorder traversal: ";
	postordertraversal(root);
	cout<<endl;
	return 0;
}