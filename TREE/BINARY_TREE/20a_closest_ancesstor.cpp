#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
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

ListNode* buildtree(ListNode* &root){
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

void print_tree(ListNode* root){
    if (root == NULL) return;
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
void find_address(ListNode* root,int value,ListNode* &address,vector<int> &container){

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

ListNode* lca(ListNode* root ,int n1,int n2){

    ListNode* n1_address = NULL;
    ListNode* n2_address = NULL;
    vector<int> for_n1;
    vector<int> for_n2;
    find_address(root,n1,n1_address,for_n1);
    find_address(root,n2,n2_address,for_n2);
    print_array(for_n1);
    print_array(for_n2);
    int val = find_common(for_n1,for_n2);
    ListNode* final_address = NULL;
    vector<int> d;  // here for finding final value address , instead we store elements in NOdes data type
    find_address(root,val,final_address,d);
    // now common value both of them which come first
    return final_address;



}
int main(){
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    // 1 2 4 8 13 -1 -1 14 -1 -1 9 -1 -1 5 -1 10 11 -1 -1 12 -1 -1 3 6 -1 -1 7 -1 -1 
    int n1= 7;
    int n2 = 7;
    ListNode* ans = lca(root,n1,n2);
    cout<<"answer is "<<endl;
    cout<<ans->data<<endl;
}