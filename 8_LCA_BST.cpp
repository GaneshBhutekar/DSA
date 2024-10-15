#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};


// input in the binary search tree
Node* insertBST(Node* &root,int data){
    if(root == NULL){
        // we came where to put the data.
        root = new Node(data);
        return root;
    }

    // traverse their 
    if (root->data > data){
        root ->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;


}


void print_tree(Node* root){
    if (root ==NULL){
        return;
    }
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
            if (demo ->right){
                q.push(demo->right);
            }
        }
    }

}

int LCA(Node* root,int n1,int n2){
    if (root == NULL){
        return -1;
    }

    if (root->data > n1 && root->data > n2){
        // it means both are on left side move to left then 
        return LCA(root->left,n1,n2);
    }
    else if (root->data < n1 && root->data < n2){
        return LCA(root->right,n1,n2);
    }

    // check that both are seperated or not
    else{
        return root->data;
    }


}


int iterative_LCA(Node* root,int n1,int n2){
    Node* temp = root;

    while(temp != NULL){

        if (root->data > n1 && root->data > n2){
            // moove left because they are small
            temp = temp->left;
        }
        else if (root->data < n1 && root->data < n2){
            temp = temp -> right;
        }
        else{
            return root->data;
        }
    }

    return -1;
}
int main(){
    Node* root = NULL;
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    // 10 8 15 7 9 13 17 6 12 14 16 19 18
    while(data != -1){
        insertBST(root,data);
        cin>>data;
    }

    print_tree(root);

    cout<<"choose two nodes sp that we will give the lowest common ancestor"<<endl;
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;

    int ans = iterative_LCA(root,n1,n2);
    cout<<"LCA of given node is "<<ans<<endl;



}