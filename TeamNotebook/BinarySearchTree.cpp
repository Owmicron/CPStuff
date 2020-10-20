#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
struct node {
    int key;
    node *left;
    node *right;
};
node *getnewnode(int val){
    node *newnode = new node();
    newnode->key = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void inorder (node *root){
    if(root!=NULL){
        inorder (root->left);
        cout<<root->key<<endl;
        inorder(root->right);
    }

}
node *ins (node *root, int val){
    if(root==NULL){
        return getnewnode (val);
    }
    if(val < root->key){
        root -> left = ins(root->left,val);
    }
    else if(val > root->key){
        root -> right = ins(root->right,val);
    }
    return root;
}
char type[30];
int q[30],n;
int main(){
    node *root;
    root = NULL;
    root = getnewnode(1);
    ins(root,7);
    ins(root,5);
    ins(root,8);
    ins(root,10);
    inorder(root);

}
