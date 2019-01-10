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

struct node* buildTree(char in[], char post[], int inStrt,int inEnd, int* pIndex, unordered_map<char, int>& mp) 
{ 
    if (inStrt > inEnd) 
        return NULL; 
    int curr = post[*pIndex]; 
    node* node = newNode(curr); 
    (*pIndex)--; 
    if (inStrt == inEnd) 
        return node;   
    int iIndex = mp[curr]; 
    node->right = buildTree(in, post, iIndex + 1, inEnd, pIndex, mp); 
    node->left  = buildTree(in, post, inStrt,iIndex - 1, pIndex, mp); 
    return node; 
} 
struct node* buldTreeWrap(char in[], char post[], int len){
    unordered_map<char, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
    int index = len - 1;
    return buildTree(in, post, 0, len - 1,&index, mp);
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
    char post[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
  
    struct node* root = buldTreeWrap(in, post, len);
    cout<<"Inorder traversal is :";
    inorder(root);
    return 0;
}

