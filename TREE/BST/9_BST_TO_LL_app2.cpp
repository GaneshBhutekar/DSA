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
        right = NULL;
        left = NULL;

    }

};






void print(Node* root){
    if (root == NULL){
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
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}
Node* insert(Node* & root,int data){
    if (root == NULL){
        root = new Node(data);
        return root;
    }

    // just check that element is greater or not
    if (root->data > data){
        root->left = insert(root->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }

    return root;

}

void insertTree(Node* &root){
    int data;
    cout<<"enter the dta"<<endl;
    cin>>data;
    while(data != -1){
        insert(root,data);
        cin>>data;
    }

}

void inorder(Node* root,vector<Node*> &nodes){
    if (root == nullptr){
        return;
    }

    // left as possible
    inorder(root->left,nodes);
    nodes.push_back(root);
    inorder(root->right,nodes);
}

Node* BST_LL(Node* root){
    vector<Node*> nodes;
    //now update this nodes vector by inorder
    inorder(root,nodes);
    int n = nodes.size();
    for(int i =0;i<n-1;i++){
        nodes[i]->right = nodes[i+1];
        nodes[i]->left = NULL;
    }

    // handling the last case
    nodes[n-1]->right = NULL;
    nodes[n-1]->left = NULL;

    return nodes[0];
}

void print_ll(Node* head){
    while(head!= NULL){
        if (head->left){
            cout<<"nahi hua abhi bhi"<<endl;
        }
        cout<<head->data<<" ";
        head = head->right;
        
    }
    cout<<endl;
}
int main(){
    Node* root = NULL;
    insertTree(root);
    print(root);
    Node* head = BST_LL(root);
    print_ll(head);

    // 10 5 15 3 7 11 21 4 16 -1
}
