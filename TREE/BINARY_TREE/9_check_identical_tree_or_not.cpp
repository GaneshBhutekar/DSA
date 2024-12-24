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


bool identical_or_not(ListNode* r1,ListNode*r2){
    // level order approach 

    if (r1 == NULL && r2 == NULL){
        return true;
    }

    if (r2 == NULL || r1 == NULL){
        return false;
    }
    queue<ListNode*> q1;
    queue<ListNode*> q2;

    if (r1->data == r2->data){ // this is redundant 
        q1.push(r1);
        q2.push(r2);


    }
    else{
        return false;
    }
    
    while(!q1.empty() && !q2.empty()){
        ListNode* demo1 = q1.front();
        ListNode* demo2 = q2.front();
        q1.pop();
        q2.pop();

        // checkl thay left one are  null or not.
        if (demo1->left != NULL && demo2 -> left != NULL){
            if (demo1->left ->data == demo2->left ->data ){
                q1.push(demo1->left);
                q2.push(demo2->left);
            }
            else{
                return false;
            }
        }
        else if (demo1->left != demo2->left){
            return false;
        }

        if (demo1->right != NULL && demo2 -> right != NULL){
            if (demo1->right ->data == demo2->right ->data ){
                q1.push(demo1->right);
                q2.push(demo2->right);
            }
            else{
                return false;
            }
        }
        else if (demo1->right != demo2->right){
            return false;
        }


    }
    return true;


}



bool identical_or_not2(ListNode* r1,ListNode* r2){

    // pre order approach
    if (r1 == NULL && r2 == NULL){
        return true;
    }
    if (r1 == NULL || r2 == NULL){
        return false;
    }

    // check for the data.
    if (r1->data != r2->data){
        return false;
    }

    bool status1 = identical_or_not2(r1->left,r2->left);

    bool status2 = identical_or_not2(r1->right, r2 ->right);

    return status1&&status2;
    
}
int main(){
    // 1 2 4 -1 -1 5 6 -1 -1 -1 3 4 -1 -1 -1

    // 1 2 4 -1 5 -1 -1 -1 3 -1 -1 
    ListNode* root1 = NULL;

    cout<<"enter the data for tree1 "<<endl;
    buildtree(root1);
    print_tree(root1);

    cout<<"enter the data for tree2"<<endl;
    ListNode* root2 = NULL;
    buildtree(root2);
    print_tree(root2);


    if (identical_or_not2(root1,root2)){
        cout<<"yes both are identical trees"<<endl;

    }
    else{
        cout<<"not they are not identical"<<endl;
    }


}