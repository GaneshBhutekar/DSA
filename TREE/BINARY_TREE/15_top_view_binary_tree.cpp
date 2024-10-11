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
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildtree(Node* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }
    

    root= new Node(data);

    cout<<"for left"<<endl;
    root->left = buildtree(root->left);
    cout<<"for right"<<endl;
    root->right = buildtree(root->right);
    return root;
}

void print_tree(Node* root){
    if (root == NULL){
        return;

    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* demo = q.front();
        q.pop();
        if (demo==NULL){
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


vector<int> top_view(Node* root){
    vector<int> ans;

    // create the data structure
    map<int,int> store;
    // initialize the queue 
    queue<pair<int,Node*>> q;

    // push the root
    q.push({0,root});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        // add this to store.
        int index = p.first;
        int data = p.second->data;
        if (!store[index]){
            store[index] = data;
        }

        // add leftf and right  to the queue
        if (p.second ->left != NULL){
            q.push({index-1,p.second->left});
        }
        if (p.second->right != NULL){
            q.push({index+1,p.second->right});
        }
    }
    for(auto i:store){
        ans.push_back(i.second);
    }
    return ans;
}
int main(){

    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node* root = NULL;
    buildtree(root);
    print_tree(root);
    vector<int> ans = top_view(root);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

}