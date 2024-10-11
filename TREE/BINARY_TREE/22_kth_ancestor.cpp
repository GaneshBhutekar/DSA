#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

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

    cout<<"for right "<<endl;
    root->right = buildtree(root->right);

    return root;

}

void print_tree(Node* root){
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


void solve(Node* root, int node,bool &found,vector<int> &ancestors){
    if (root == NULL){
        return;
    }

    
    if (root->data == node){
        found = true;
        return;
    }
    if (found == false){
        solve(root->left,node,found,ancestors);
    }
    if (found == false){
        solve(root->right,node,found,ancestors);
    }

    if (found == true)
    {
        cout<<"value is "<<root->data<<endl;
        ancestors.push_back(root->data);
    }


}

int KthAncestor(Node* root , int k,int node){
    if (k == 0){
        return -1;
    }
    bool found = false;
    vector<int> ancestors;
    solve(root,node,found,ancestors);
    int ans=-1;
    if (ancestors.size() >= k){
        ans = ancestors[k-1];

    }
    return ans;

}
int main(){
    Node* root = NULL;
    int k ;
    int node;
    buildtree(root);
    print_tree(root);
    cout<<"enter the k value"<<endl;
    cin>>k;
    cout<<"enter the node "<<endl;
    cin>>node;
    int ans = KthAncestor(root,k,node);
    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    // 1 2 -1 -1 3 -1 -1
    cout<<"answer is "<<ans<<endl;
}