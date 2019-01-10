#include <bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data){
    struct node* newnode= new node;
    newnode->data= data;
    newnode->left =NULL;
    newnode->right= NULL;
    return newnode;
}
int max (char arr[], int strt, int end) 
{ 
    int i, max = arr[strt], maxind = strt; 
    for(i = strt+1; i <= end; i++) 
    { 
        if(arr[i] > max) 
        { 
            max = arr[i]; 
            maxind = i; 
        } 
    } 
    return maxind; 
}
struct node* buildTree (char inorder[], int start, int end) 
{ 
    if (start > end) 
        return NULL;
    int i = max (inorder, start, end); 
    struct node *root = newNode(inorder[i]); 
    if (start == end) 
        return root; 
    root->left  = buildTree (inorder, start, i-1); 
    root->right = buildTree (inorder, i+1, end); 
  
    return root; 
} 

 
void inorder(struct node* root){
    if(root){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }       
    return;
}

int main() {
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    int len = sizeof(in) / sizeof(in[0]); 
  
    struct node* root = buildTree(in, 0, len);
    cout<<"Inorder traversal is :";
    inorder(root);
    return 0;
}

