#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this->data = data;
        right = NULL;
        left = NULL;

    }

};






void print(ListNode* root){
    if (root == NULL){
        return;

    }

    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        ListNode* demo = q.front();
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
ListNode* insert(ListNode* & root,int data){
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

void insertTree(ListNode* &root){
    int data;
    cout<<"enter the dta"<<endl;
    cin>>data;
    while(data != -1){
        insert(root,data);
        cin>>data;
    }

}

void inorder(ListNode* root,vector<ListNode*> &nodes){
    if (root == nullptr){
        return;
    }

    // left as possible
    inorder(root->left,nodes);
    nodes.push_back(root);
    inorder(root->right,nodes);
}

ListNode* BST_LL(ListNode* root){
    vector<ListNode*> nodes;
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

void print_ll(ListNode* head){
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
    ListNode* root = NULL;
    insertTree(root);
    print(root);
    ListNode* head = BST_LL(root);
    print_ll(head);

    // 10 5 15 3 7 11 21 4 16 -1
}
