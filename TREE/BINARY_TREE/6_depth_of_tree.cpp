#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->right = NULL;
        this ->left = NULL;

    }


};

node* buildtree(node* &root){
    int data;
    cout<<"insert the data "<<endl;
    cin>>data;

    if (data ==-1){
        return NULL;
    }

    root = new node(data);

    cout<<"to the left "<<endl;
    root->left = buildtree(root->left);

    cout<<"to the right "<<endl;
    root->right = buildtree(root->right);
    return root;

}


void print_tree(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* demo = q.front();
        q.pop();
        if (demo == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<demo->data<<" ";
            if (demo->left != NULL){
                q.push(demo->left);
            }
            if (demo->right != NULL){
                q.push(demo->right);
            }
        }
    }
}

void solve(node*root , int &height,int cnt){

    if (root == NULL){
        return;
    }
    if (root->right == NULL && root->left == NULL){
        if (cnt> height){
            height = cnt;
        }
        return;
    }

    solve(root->left,height,cnt+1);

    solve(root->right,height,cnt+1);

    return;
         
}


int solve2(node* root){
    if (root== NULL){
        return 0;
    }

    int from_left = solve2(root->left);
    int from_right = solve2(root->right);


    if (from_left > from_right){
        return from_left+ 1;
    }
    else{
        return 1+ from_right;
    }
}


int find_depth(node* root ){
    int max_height = 0;
    int cnt =1;

    solve(root,max_height,cnt);
    return max_height;

}
int main(){
    node* root = NULL;
    buildtree(root);
    print_tree(root);

    int ans = solve2(root);
    // 1 2 4 -1 -1 5 6 -1 -1 -1 3 4 -1 -1 -1
    cout<<"most depth of the tree is "<< ans <<endl;
    


}