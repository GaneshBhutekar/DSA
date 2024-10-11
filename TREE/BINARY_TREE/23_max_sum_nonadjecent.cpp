#include<iostream>
#include<queue>
#include<algorithm>
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

pair<int,int> solve(Node* root){
    if (root == NULL){
        return {0,0};

    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    // included current node vallue
    // excluded current node value and maximum sum

    int include = root->data+left.second+right.second;
    int exclude = max(left.first,left.second) + max(right.first,right.second);

    // put this value again in pair.
    return {include,exclude};
}

int getMaxSum(Node* root){
    pair<int,int> pr = solve(root);
    return max(pr.first,pr.second);

}
int main(){
    Node* root = NULL;
    buildtree(root);
    print_tree(root);
    int ans = getMaxSum(root);
    cout<<"answer is "<<ans<<endl;
    // 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
}