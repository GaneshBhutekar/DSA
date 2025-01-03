#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this ->data = data;
        this ->right = NULL;
        this->left = NULL;
    }
};

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

    cout<<"for right "<<endl;
    root->right = buildtree(root->right);

    return root;

}

void print_tree(ListNode* root){
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


ListNode* preceder(ListNode* curr){
    ListNode* prec = curr->left;
    // here we are not repeating to the curr it means just check node before the null
    while(prec->right != NULL){
        prec=prec->right;
    }
    return prec;
}

void flatten(ListNode* &root){
    if (root == NULL){
        return;
    }

    ListNode* curr = root;
    while(curr != NULL){
        if (curr ->left == NULL){
            curr=curr->right;
        }
        else{
            // there will be prec which next right is null because we don't need to traverse again to curr
            ListNode* prec = preceder(curr);
            prec->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
        }
    }
}


int main(){
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    // 1 2 4 8 -1 -1 9 11 -1 -1 12 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 10 -1 -1 

    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    flatten(root);

    print_tree(root);
    
}