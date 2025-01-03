#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

ListNode* construct(vector<int> &preorder,vector<int> &inorder,int start,int end,int &index){
    if (start>end){
        return NULL;
    }

    // find the node in inorder 
    int i = start;
    int element = preorder[index];
    while(inorder[i] != element && i<= end){
        i++;
    }

    // we got the value it means from left of this value will be smaller element and in the right there will be larger 
    ListNode* root = new Node(element);

    // move to the left space
    index++;
    root->left = construct(preorder,inorder,start,i-1,index);
    // move to the right
    root->right = construct(preorder,inorder,i+1,end,index);

    return root;

}

ListNode* BSt(vector<int> preorder){
    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());
    // now with the help of inorder
    int n = inorder.size();
    int index = 0;
    ListNode* root = construct(preorder,inorder,0,n-1,index);
    return root;
}
int main(){
    vector<int> preorder  = {20,10,5,15,13,35,30,42,100};
    ListNode* root = BSt(preorder);
    print(root);

}