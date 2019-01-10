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

struct node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map<char, int>& mp){
    static int preIndex = 0; 
      if (inStrt > inEnd) 
        return NULL; 
    char curr = pre[preIndex++]; 
    struct node* tNode = newNode(curr); 
    if (inStrt == inEnd) 
        return tNode; 
    int inIndex = mp[curr]; 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp); 
  
    return tNode;

}
struct node* buldTreeWrap(char in[], char pre[], int len){
    unordered_map<char, int> mp; 
    for (int i = 0; i < len; i++) 
        mp[in[i]] = i; 
  
    return buildTree(in, pre, 0, len - 1, mp);
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
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
  
    struct node* root = buldTreeWrap(in, pre, len);
    cout<<"Inorder traversal is :";
    inorder(root);
    return 0;
}

