#include <stdlib.h> 
#include <stdio.h> 
#include <iostream> 
#include <stack> 

using namespace std; 

/* A binary tree node has data, left child and right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* Helper function that allocates a new node with the given data and 
NULL left and right pointers.*/
struct node* newNode(int data) 
{ 
	struct node* node = new struct node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

void Preorder(node *root) 
{ 
	if (root == NULL) 
	return; 
	stack<node *> nodeStack; 
	nodeStack.push(root); 

	/* Pop all items one by one. Do following for every popped item 
	a) print it 
	b) push its right child 
	c) push its left child 
	Note that right child is pushed first so that left is processed first */
	while (nodeStack.empty() == false) 
	{ 

		struct node *node = nodeStack.top(); 
		cout<<node->data<<" "; 
		nodeStack.pop(); 
		if (node->right) 
			nodeStack.push(node->right); 
		if (node->left) 
			nodeStack.push(node->left); 
	} 
} 

int main() 
{ 
struct node *root = newNode(10); 
root->left	 = newNode(8); 
root->right	 = newNode(2); 
root->left->left = newNode(3); 
root->left->right = newNode(5); 
root->right->left = newNode(2); 
cout<<"preorder is: ";
Preorder(root); 
return 0; 
} 

