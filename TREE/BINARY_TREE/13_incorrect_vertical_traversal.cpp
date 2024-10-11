#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this ->data = data;
        this ->right = NULL;
        this -> left = NULL;
    }
};

class stacks{
    public:
    stack<int> st;
    void add(int data){
        st.push(data);
    }

    int top(){
        return st.top();
    }

    void pop(){
        st.pop();
    }

    bool isempty(){
        if (st.empty()){
            return true;
        }
        else{
            return false;
        }
    }

};


Node* buildtree(Node* &root){
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


void print(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp  = q.front();
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












int count_nodes(Node* root){
    //in order way

    if (root == NULL ){
        return 0;
    }
    int count = count_nodes(root->left)+ count_nodes(root ->right);

    return 1+ count;

}

int left_nodes(Node* root){
    if (root == NULL){
        return 0;
    }
    int count = left_nodes(root->left);

    return count+1;
}

int right_nodes(Node* root){
    if (root == NULL){
        return 0;
    }
    int count = right_nodes(root->right);
    return count+1;
}

void RLN_traversal(Node* root , int root_index,vector<stacks> &all_stacks){
    if (root == NULL){
        return;
    }

    // move totally right
    RLN_traversal(root->right,root_index+1,all_stacks);

    // move totally left
    RLN_traversal(root->left,root_index-1,all_stacks);

    // push the element into right position
    all_stacks[root_index].add(root->data);
    return;



}

void push_all(vector<int> &ans,vector<stacks> all_stacks,int n){
    for(int i=0;i<n;i++){
        while(!all_stacks[i].isempty()){
            ans.push_back(all_stacks[i].top());
            all_stacks[i].pop();
        }
    }
}
vector<int> vertical_traversal(Node* root){

    vector<int> ans;
    if (root ->left ==  NULL && root -> right == NULL){
        ans.push_back(root->data);
        return ans;
    }

    // find total number of node

    int nodes = count_nodes(root);
// find total number of node from outside
    int outside_nodes = left_nodes(root);

    // root index will be 
    int root_index = outside_nodes -1;

    outside_nodes += right_nodes(root->right);
    
    // create vector<stacks> of size outside_nodes

    vector<stacks> all_stacks(outside_nodes);

    RLN_traversal(root,root_index,all_stacks);

    // final thing push all element in to ans
    push_all(ans,all_stacks,outside_nodes);

    return ans;


}
int main(){
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1 
    // 1 2 4 -1 5 -1 6 -1 -1 10 -1 -1 3 9 -1 -1 10 -1 -1

    Node* root = NULL;
    buildtree(root);
    print(root);

    vector<int> ans = vertical_traversal(root);
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

}