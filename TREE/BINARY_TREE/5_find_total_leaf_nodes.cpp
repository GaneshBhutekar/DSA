#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this -> data = data;
        this -> right = NULL;
        this ->left = NULL;

    }
};


node* buildtree(node* root){

    int data;
    cout<<"enter the element"<<endl;
    cin>> data;

    if (data == -1){
        return NULL;

    }

    root = new node(data);

    // for the left .
    cout<<"for left "<<endl;
    root ->left = buildtree(root->left);

    // for the right.
    cout<<"for right "<<endl;
    root->right = buildtree(root -> right);
    return root;

}


void level_order(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* current = q.front();
        q.pop();
        if (current == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<current->data <<" ";
            if (current->left != NULL){
                q.push(current->left);
            }
            if(current->right != NULL){
                q.push(current->right);
            }
        }

    }

}

// now check how many node are child - recurssion.
int child_nodes(node* root){

    // this is post order way u can do it by pre order and inroder too.

    if (root == NULL){
        return 0;
    }
    if(root ->left == NULL && root ->right == NULL){
        return 1;
    }


    // traverse to the left and traverse to right
    return child_nodes(root->left) + child_nodes(root->right);
    
}
int main(){
    // 20 10 5 -1 -1 15 13 -1 -1 -1 35 30 -1 -1 42 -1 -1
    node* root = NULL;
    root = buildtree(root);
    level_order(root);
    int ans = child_nodes(root);
    cout<<"total leaf node are "<<ans<<endl;

}