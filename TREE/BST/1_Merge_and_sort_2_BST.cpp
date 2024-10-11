#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this ->data = data;
        left = NULL;
        right = NULL;
    }
};


Node* buildtree(Node* root){

    int data;
    cout<<"enter the element"<<endl;
    cin>> data;

    if (data == -1){
        return NULL;
    }

    root = new Node(data);

    // for the left .
    cout<<"for left "<<endl;
    root ->left = buildtree(root->left);

    // for the right.
    cout<<"for right "<<endl;
    root->right = buildtree(root -> right);
    return root;

}

void sort_merge(Node* root,vector<int> &r){
    if (root == NULL){
        return;
    }

    // go to left 
    sort_merge(root->left,r);
    // cout<<root1->data<<" ";
    r.push_back(root->data);
    sort_merge(root->right,r);
        
    return;
}


vector<int> solve(vector<int> r1,vector<int> r2){
    vector<int> ans ;
    int n1 = r1.size();
    int n2 = r2.size();
    int i=0;
    int j=0;
    while(i < n1 && j < n2 ){
        if (r1[i]  <= r2[j]){
            ans.push_back(r1[i]);
            i++;

        }
        else{
            ans.push_back(r2[j]);
            j++;
        }
    }

    // r1 left 
    while(i<n1){
        ans.push_back(r1[i]);
        i++;
    }

    // r2 left
    while(j<n2){
        ans.push_back(r2[j]);
        j++;
    }

    return ans;
}
vector<int> merge(Node* root1,Node* root2){
    vector<int> r1;
    vector<int> r2;

    // for tree 1
    sort_merge(root1,r1);
    sort_merge(root2,r2);

    // now they are sorted 
    vector<int> ans = solve(r1,r2);

    return ans;


}

void print_tree(Node* root){

    if (root == NULL) return;
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



int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    
    cout<<"enter for tree 1"<<endl;
    // 5 3 2 -1 -1 4 -1 -1 6 -1 -1 
    root1 = buildtree(root1);

    print_tree(root1);

    cout<<"enter for tree 2 "<<endl;
    // 2 1 -1 -1 3 -1 7 6 -1 -1 -1
    root2 = buildtree(root2);
    print_tree(root2);

    vector<int> ans =  merge(root1,root2);

    for( int i : ans){
        cout<<i<<" ";

    }
    cout<<endl;

}