#include<iostream>
#include<queue>
#include<stack>
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

void solve(Node* root, vector<int> &path,int & count,int k){
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
    // for left
    solve(root->left,path,count,k);

    // for right
    solve(root->right,path,count,k);

    // size of the path
    int n = path.size();
    int sum = 0;
    for(int i =n-1;i>=0;i--){
        sum += path[i];
        if (sum == k){
            count++;           
        }
    }
    path.pop_back();
    
}

int sumK(Node* root,int k){
    vector<int> path;
    int count=0;
    solve(root,path,count,k);
    return count;
    
}
int main(){
    Node* root = NULL;
    buildtree(root);
    print_tree(root);
    int k;
    cout<<"enter the value of k"<<endl;
    cin>>k;
    // 8 4 3 3 -1 -1 -2 -1 -1 2 -1 1 -1 -1 5 -1 2 -1 -1
    // 3 4 1 -1 -1 1 -1 -1 2 0 -1 -1 3 -1 -1 
    int count = sumK(root,k);
    cout<<"total brach which sum is k "<<count<<endl;
}