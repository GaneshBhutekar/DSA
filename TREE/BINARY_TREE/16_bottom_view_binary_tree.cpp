#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this ->left = NULL;
    }
};

ListNode* buildtree(ListNode*& root){
    int data;
    cout<<"enter the element: "<<endl;
    cin>>data; 
    if (data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);

    return root;

    
}


void print_tree(ListNode* root){
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

vector<int> bottom_view(ListNode* root){
    vector<int> ans;
    // to store
    map<int,int> store;
    // queue
    queue<pair<int,ListNode*>> q;

    q.push({0,root});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        // push it to the store
        int index = p.first;
        int data = p.second->data;

        store[index] = data;

        if (p.second->left){
            q.push({index-1,p.second->left});
        }
        if (p.second->right){
            q.push({index+1,p.second->right});
        }
    }

    for(auto i : store){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){
    // 20 8 5 -1 -1 3 10 -1 -1 -1 22 4 -1 14 -1 -1 25 -1 -1
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    vector<int>  ans = bottom_view(root);
    for(int i:ans){
        cout<<i<<" ";

    }
    cout<<endl;

}