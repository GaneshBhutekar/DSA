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
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};


// input in the binary search tree
ListNode* insertBST(ListNode* &root,int data){
    if(root == NULL){
        // we came where to put the data.
        root = new Node(data);
        return root;
    }

    // traverse their 
    if (root->data > data){
        root ->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
    }
    return root;


}


void print_tree(ListNode* root){
    if (root ==NULL){
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
            if (demo ->right){
                q.push(demo->right);
            }
        }
    }

}





pair<int,int> predecessorSuccessor(ListNode* root,int key){
    // just find the key
    ListNode* temp = root;

    // start to find the key 
    int prec = -1;
    int suc = -1;
    while(temp != NULL && temp->data != key){
        if (temp->data > key){
            // we have to go left and we goiinf left mean curr node is bigger right now so may be it will be succ
            suc = temp->data;
            temp = temp->left;
        }
        else{
            // we have to go right so the curr value will be smallest at this moment and for future moment so mark it as [pred]
            prec = temp->data;
            temp = temp->right;
        }
    }

    // we got the temp check it whether the temp is null or not
    if (temp == NULL){
        return {-1,-1};
    }

    // now find the pred (one smaller in BST)
    // pred is always left side larger value or if it is null then another smaller which will be his parent  from where it turn right.

    ListNode* P = temp->left;
    while(P != NULL){
        // travere till we get most biggest value in right side of the temp.
        prec = P->data;
        P=P->right;

    }

    // and we have predecessor now!!

    //now find the sucessor it will be next of temp in inorder traversal we can found it by most smallest in right side of the temp 
    // OR from where it turn left last time because if there is not larger value than the next larger value will be that element 
    // from where it turn left last time
    ListNode* S = temp->right;
    while(S != NULL){
        suc = S->data;

        // smallest value from right.
        S= S->left;
    }


    // we have both now return it 
    return {prec,suc};

}
int main(){
    Node *root = NULL;
    cout<<"enter the numbers "<<endl;
    // 4 2 5 1 3 5
    // 5 3 7 2 4 6 8 1
    // 10 5 12 3 7 11 13 2 4 6 8 15 1 9 14
    int data;
    cin>>data;
    while(data != -1){
        insertBST(root,data);
        cin>>data;
    }

    print_tree(root);
    cout<<"enter the key here"<<endl;
    int key;
    cin>>key;
    pair<int,int> ans = predecessorSuccessor(root,key);
    cout<<"predecessor "<<ans.first<<" succsessor "<<ans.second<<" for "<<key<<endl;

}