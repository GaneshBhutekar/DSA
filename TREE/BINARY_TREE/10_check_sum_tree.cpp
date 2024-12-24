#include<iostream>

#include<queue>
using namespace std;


class node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    node(int data){
        this->data = data;
        this -> right = NULL;
        this -> left = NULL;

    }

    
};

ListNode* buildtree(ListNode* &root){
    int data;
    cout<<"enter data "<<endl;
    cin>>data;

    if (data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"for left "<<endl;
    root->left = buildtree(root->left);
    cout<<"for right "<<endl;
    root->right = buildtree(root->right);

    return root;
}


void print_tree(node * root){
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
            cout<<demo ->data<<" ";
            if (demo->left != NULL){
                q.push(demo->left);
            }
            if (demo->right != NULL){
                q.push(demo->right);
            }
        }
    }
}


// we can do this using pair also .
int check_sum(node * root,bool &status ){
    if (root == NULL){
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL){
        return root->data;
    }



    int from_left = check_sum(root->left,status);
    int from_right = check_sum(root -> right,status);

    if (from_left + from_right != root->data){
        status = false;
    }

    return from_left+from_right+root->data;
}

bool sum_tree(ListNode* root){
    bool status = true;
    check_sum(root,status);
    return status;
}
int main(){
    ListNode* root = NULL;

    // 100 20 -1 20 -1 -1 60 10 -1 -1 10 -1 -1

    // 40 20 -1 20 -1 -1 30 10 -1 -1 20 -1 -1 

    buildtree(root);
    print_tree(root);
    cout<<"yaha pe pahuch gaya "<<endl;

    if (sum_tree(root)){
        cout<<"yes every node  is equal to their side total "<<endl;
    }
    else{
        cout<<"no it is not"<<endl;
    }

}