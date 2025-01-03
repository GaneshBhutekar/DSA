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


ListNode* preceder(ListNode* current){
    ListNode* prec = current->left;
    while(prec->right != NULL && prec->right != current){
        prec = prec ->right;
    }
    return prec;
}
void Morris_Traverse(ListNode* root){
    if (root == NULL){
        return;
    }
    ListNode* current = root;
    while(current != NULL){
        if (current ->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }
        else{
            // iska matlab current ka left hain
            // precedence nikal bc.
            ListNode* prec = preceder(current);
            if (prec->right == current){
                prec->right = NULL;
                // cout<<current->data<<" "; // ye jab inorder ke liyte
                current = current ->right;
            }
            else{
                prec->right = current;
                cout<<current->data<<" "; //ye jb pre order ke liye
                current = current->left;
            }

        }
    }
    cout<<endl;
}


int main(){
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    // 1 2 4 8 -1 -1 9 11 -1 -1 12 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 10 -1 -1 
    cout<<"morris traversal "<<endl;
    Morris_Traverse(root);
}