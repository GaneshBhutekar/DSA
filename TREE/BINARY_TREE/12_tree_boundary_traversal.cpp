#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this -> data = data;
        this -> right = NULL;
        this -> left = NULL;

    }
};

ListNode* buildtree(ListNode* &root){
    int data;
    cout<<"enter the data "<<endl;
    cin>> data;

    if (data == -1){
        return NULL;
    }

    root = new Node(data);

    // to the left
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);
    return root;

}
void print_array(vector<int> arr){
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

void print(ListNode* root){
    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        ListNode* temp  = q.front();
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

void left_nodes(ListNode* root,vector<int> &ans){
    if (root == NULL){
        return;
    }
    if (root ->left == NULL && root -> right == NULL){
        return;
    }

    ans.push_back(root->data);
    if (root -> left == NULL){
        left_nodes(root->right,ans);
        
    }

    else{
        left_nodes(root->left,ans);
    }
    
    return;



}

void right_nodes(ListNode* root,stack<int> &st){
    if (root == NULL){
        return;
    }
    if (root ->left == NULL && root -> right == NULL){
        return;
    }
    // cout<<root->data<<endl;
    st.push(root->data);
    if (root->right != NULL){
        right_nodes(root->right, st);
    }
    else{
        right_nodes(root->left,st);
    }
}


void leaf_nodes(ListNode* root, vector<int> & ans){
    if (root == NULL){
        return;
    }

    if (root->left == NULL && root ->right== NULL){
        ans.push_back(root->data);
        return;
    }

    // for the left
    leaf_nodes(root->left,ans);
    // for right
    leaf_nodes(root->right,ans);
    

}


vector<int> boundary(ListNode* root){
    vector<int> ans;
    ans.push_back(root->data);

    if (root->left == NULL && root->right == NULL){
        return ans;
    }
    // add left node first
    left_nodes(root->left,ans);
    // add leaf nodes then
    leaf_nodes(root,ans);
    stack<int> st;
    right_nodes(root->right,st);
    // put reversly all element into array
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;

}

int main(){
    ListNode* root = NULL;
    buildtree(root);
    print(root);
    // 1 2 -1 3 4 -1 6 -1 -1 5 -1 -1 -1
    // 1 2 4 -1 7 9 -1 -1 10 -1 -1 5 -1 -1 3 6 -1 8 18 -1 -1 19 -1 -1 -1
    vector<int> ans = boundary(root);
    cout<<"boundary of the given tree is "<<endl;
    print_array(ans);


}