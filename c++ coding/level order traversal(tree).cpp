#include <bits/stdc++.h>
using namespace std;
class node {
    public :
    int data;
    node* left, *right;
};

node* createNode(int i){
    node* Node = new node();
    Node->data = i;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

int height(node* root) {
    if(root == NULL){
        return 0;
    }
        else {
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(lheight > rheight){
            return 1+lheight;
        }
        else{
            return 1+rheight;
        }
    }
}

void printCurrentLevel(node* root, int level) {
    if(root == NULL)
        return;
    if(level == 1){
        cout<< root->data<< " ";
        return;
    }else {
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void printLevelOrder(node* root) {
    if(root==NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        cout<<root->data;
        return;
    }
    else{
        int h = height(root);
        for(int i=1; i<=h; i++) {
            printCurrentLevel(root,i);
        }
    }
}

int main() {
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right= createNode(6);
    root->right->left = createNode(8);
    root->left->left->left = createNode(5);
    root->left->right->left=createNode(7);
    
    printLevelOrder(root);
	return 0;
}
