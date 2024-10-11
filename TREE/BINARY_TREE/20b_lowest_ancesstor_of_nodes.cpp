#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* buildtree(Node* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;

    if (data == -1){
        return NULL;
    }
    root = new Node(data);
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);

    cout<<"for right "<<endl;
    root->right = buildtree(root->right);

    return root;

}

void print_tree(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* demo = q.front();
        q.pop();
        if (demo == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<demo->data<<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}

Node* lca(Node* root , int n1 , int n2){
    if (root == NULL){
        return NULL;
    }


    // if left is null and right is null
    Node* left = lca(root->left,n1,n2);
    Node* right = lca(root->right,n1,n2);

    if (root->data == n1 || root->data == n2){
        return root;
    }
    else if (left== NULL && right == NULL){
        return NULL;
    }

    else if (left != NULL && right == NULL){
        return left;
    }
    else if (left == NULL && right != NULL){
        return right;
    }
    else{
        return root; // where both left and right is not null
    }

}
int main(){
    Node* root = NULL;
    buildtree(root);
    print_tree(root);
    // 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 -1 10 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 -1
    int n1 = 9;
    int n2 = 14;
    Node* ans = lca(root,n1,n2);
    cout<<"coomon closest ancestor "<<ans->data<<endl;
}