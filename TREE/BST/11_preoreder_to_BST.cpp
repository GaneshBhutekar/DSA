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
        right = NULL;
        this->data = data;
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
        ListNode* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}
ListNode* construct(vector<int> &preorder,int &index,int n,int max){

    if(index >= n){
        return NULL;
    }

    // check that the current node is fitted at this range or not
    if(preorder[index] > max){
        return NULL;
    }

    // create the node here
    ListNode* root = new Node(preorder[index]);

    // move to the left 
    index++;
    root->left = construct(preorder,index,n,preorder[index-1]); // maximum range updatted
    root->right = construct(preorder,index,n,max); // minimum range updated

    return root;
}

ListNode* makeTree(vector<int> preorder){
    int index =0;
    int n = preorder.size();
    // pair<int,int> range= {INT_MIN,INT_MAX};
    ListNode* root = construct(preorder,index,n,INT_MAX);
    return root;
}
int main(){
    vector<int> preorder = {20,10,5,15,13,35,30,42};
    ListNode* root = makeTree(preorder);
    print(root);


}