#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
};

node* newNode(int i) {
    node* Node = new node();
    Node->data = i;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

void findMinMax(node* root, int *min, int *max, int hd){
    if(root == NULL)
        return;
        
    if(hd<*min)
        *min=hd;
    if(hd>*max)
        *max=hd;
    if(root->left)
        findMinMax(root->left,min,max,hd-1);
    if(root->right)
        findMinMax(root->right,min,max,hd+1);
}

void printCurrentLine(node* root,int line_no,int h){
    if(root==NULL) return;
    
    if(h==line_no)
        cout<<root->data<<" ";
    
    printCurrentLine(root->left, line_no, h-1);
    printCurrentLine(root->right, line_no, h+1);
}

void verticalOrder(node* root) {
    int min =0, max = 0;
    findMinMax(root,&min,&max,0);
    
    for(int line_no = min ; line_no<= max; line_no++){
        printCurrentLine(root,line_no,0);
        cout<<endl;
    }
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right= newNode(8);
    root->left->left->right->right= newNode(9);
    root->left->left->right->right->right= newNode(10);
    root->left->left->right->right->right->right= newNode(11);
    root->left->left->right->right->right->right->right= newNode(12);
    root->left->left->right->right->right->right->right->right= newNode(13);
    root->left->left->right->right->right->right->right->right->right= newNode(14);
    root->right->right = newNode(7);
    root->right->left= newNode(6);
 
    cout << "Vertical order traversal is \n";
    verticalOrder(root);
 
    return 0;
}
