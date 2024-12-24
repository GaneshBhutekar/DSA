#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// build tree through level order way.

class node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    node(int data){
        this-> data = data;
        this-> right = NULL;
        this-> left = NULL;

    }
};

void tree_build_level_order(ListNode* &root){
    queue<ListNode*> q;
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return;
    }
    root = new node(data);

    q.push(root);

    while(!q.empty()){
        ListNode* demo = q.front();

        // now push the left one
        cout<<"enter the left node for "<<demo->data <<endl;
        cin>>data;
        if (data != -1){
            demo->left = new node(data);
            q.push(demo->left);
        }

        cout<<"enter the right node for "<<demo-> data <<endl;
        cin>> data;
        if (data != -1){
            demo->right = new node(data);
            q.push(demo->right);
        }

        // pop the front element
        q.pop();


    }
    
} 

void level_order_traversal(ListNode*root){
    if (root== NULL){
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
            if (demo->left != NULL){
                q.push(demo->left);
            }
            if (demo->right != NULL){
                q.push(demo->right);
            }
        }
    }
}
int main(){
    ListNode* root = NULL;
    tree_build_level_order(root);
    level_order_traversal(root);
    
}