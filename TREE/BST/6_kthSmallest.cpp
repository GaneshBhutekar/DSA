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


int solve(Node* root,int &k){
    if (root == NULL){
        return -1;
    }

    // go left as possible
    int num1 = solve(root->left,k);
    k--;

    if (k==0){
        return root->data;
    }
    if (k<=0){
        return num1;
    }
    int num2 = solve(root->right,k);
    if (num1 != -1){
        return num1;
    }
    else{
        return num2;
    }
}

int kthsmallest(Node* root,int k){
    int ans = solve(root,k);
    return ans;
}

int main(){
    Node* root = NULL;
    // 5 4 8 2 6 10 3 7
    cout<<"insert the data"<<endl;
    int data;
    cin>>data;
    while(data != -1){
        insertBST(root,data);
        cin>>data;
    }
    print_tree(root);
    int k;
    cout<<"enter the kth smallest value you want"<<endl;
    cin>>k;
    cout<<"kth smallest value is "<<kthsmallest(root,k)<<endl;

}