#include<iostream>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;

class node{
    public: 
    int data;
    node* right;
    node* left;
    node(int data){
        this->data  = data;
        this -> right = NULL;
        this -> left = NULL;
    }
};

node* create_tree(node* root){
    int data;
    cout<<"enter the data "<<endl;
    cin>> data;
    
    if (data == -1){

        return NULL;
    }

    root = new node(data);
    cout<<"for left "<<endl;
    root->left = create_tree(root->left);
    cout<<"for right "<<endl;
    root->right = create_tree(root->right);

    return root;

}


int solve(node* root,bool &status){
    if (root == NULL){
        return 0;
    }

    int left = solve(root->left,status);
    int right = solve(root->right,status);

    int sum = abs(right-left);
    if (sum > 1){
        status = false;
    }

    if (left > right){
        return left +1;
    }
    else{
        return right +1;
    }

    

}

bool balance_tree(node* root){
    bool status = true;
    solve(root,status);
    return status;
}
void print_tree(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp  = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
        }
        }

        else{
            cout<<temp->data << " ";
            if (temp->left != NULL){
                q.push(temp-> left);
            }
            if (temp->right != NULL){
                q.push(temp->right);
            }
        }

    }
}
int main(){
    // 1 2 4 -1 -1 5 6 -1 -1 -1 3 4 -1 -1 -1

    // 1 2 4 -1 5 -1 -1 -1 3 -1 -1 
    node* root = NULL;
    root = create_tree(root);
    print_tree(root);

    if (balance_tree(root)){
        cout<<"YES it is balanced tree"<<endl;
    }
    else{
        cout<<"NO it is not balanced tree"<<endl;
    }
}