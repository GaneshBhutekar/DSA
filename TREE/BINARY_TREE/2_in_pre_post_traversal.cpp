#include<iostream>
#include<vector>
using namespace std;

// class to create the node
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this ->left=NULL;
        this-> right = NULL;

    }
};


node* build_tree(node * &root){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }

    root = new node(data);

    // insert to left 
    cout<<"left one"<<endl;
    root->left = build_tree(root->left);
    // insert to right.
    cout<<"right one"<<endl;
    root->right = build_tree(root->right);

    return root;

}



void inorder_traverse(node*root){
    if (root == NULL){
        return;
    }

    // left first 
    inorder_traverse(root->left);


    // then node one
    cout<<root->data<<" ";

    // right at last

    inorder_traverse(root->right);

}


void preorder_traversal(node* root){
    if (root == NULL){
        return;
    }

    // node one
    cout<<root->data<<" ";

    // then traverse to left
    preorder_traversal(root->left);

    // then to the right

    preorder_traversal(root->right);

}

void postorder_traversal(node* root){
    if (root == NULL){
        return;
    }

    // left first 
    postorder_traversal(root->left);

    // then to the right.
    postorder_traversal(root->right);

    // then print current node
    cout<<root->data<<" ";
}
int main(){

    // 1 2 4 -1 -1 6 -1 -1 3 -1 5 -1 -1
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    build_tree(root);

    cout<<"inorder traversal "<<endl;
    inorder_traverse(root); // correct by my self.
    cout<<endl;

    cout<<"preorder traversal"<<endl;
    preorder_traversal(root);

    cout<<endl;
    cout<<"postorder traversal"<<endl;
    postorder_traversal(root);

}