#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this ->left = NULL;
        this -> right = NULL;
    }
};

void print_array(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

Node* buildtree(Node* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }

    root = new Node(data);
    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root ->right = buildtree(root->right);

    return root;
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
            if (demo -> right){
                q.push(demo->right);
            }
        }
    }
}
// DSA
// Project
// Open Source
// 
void find_address(Node* root,int value,Node* &address,vector<int> &container){

    if (root == NULL){
        return;
    }
    if (root->data == value){
        address = root;
        container.push_back(root->data);
        return;
    }
    if (address == NULL){
    find_address(root->left,value,address,container);
    }
    if (address == NULL){
    find_address(root->right,value,address,container);
    }
    if (address != NULL){
    container.push_back(root->data);
    }
    return;
   
}
int find_common(vector<int> n1,vector<int> n2){
    int i = n1.size()-1;
    int j= n2.size() -1;
    int common = n1[i];
    while(i >=0 && j>= 0){
        if (n1[i] != n2[j]){
            return common;
        }
        common = n1[i];
        i--;
        j--;
    }
    return common;
}

Node* lca(Node* root ,int n1,int n2){

    Node* n1_address = NULL;
    Node* n2_address = NULL;
    vector<int> for_n1;
    vector<int> for_n2;
    find_address(root,n1,n1_address,for_n1);
    find_address(root,n2,n2_address,for_n2);
    print_array(for_n1);
    print_array(for_n2);
    int val = find_common(for_n1,for_n2);
    Node* final_address = NULL;
    vector<int> d;  // here for finding final value address , instead we store elements in NOdes data type
    find_address(root,val,final_address,d);
    // now common value both of them which come first
    return final_address;



}
int main(){
    Node* root = NULL;
    buildtree(root);
    print_tree(root);
    // 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 -1 10 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 -1 
    int n1= 7;
    int n2 = 7;
    Node* ans = lca(root,n1,n2);
    cout<<"answer is "<<endl;
    cout<<ans->data<<endl;
}