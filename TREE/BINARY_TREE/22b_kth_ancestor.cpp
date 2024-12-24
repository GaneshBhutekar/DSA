#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
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

ListNode* solve(ListNode* root, int &k,int node){
    if (root == NULL){
        return  NULL;
    }

    // when we found the node
    if (root -> data == node){
        return root;
    }

    ListNode* left = solve(root->left,k,node);
    ListNode* right = solve(root->right,k,node);

    if (left != NULL && right == NULL){
        k--;
        if (k<=0){
            k = INT_MAX;
            return root;
        }
        return left;
    }

    if (left == NULL && right != NULL) {
        k--;
        if (k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }

    return NULL;
}

int KthAncestor(ListNode* root,int k, int node){
    ListNode* ans = solve(root,k,node);

    // there is consition if ans is same as node so it did not find the ancestor at k position.
    if (ans == NULL && ans->data == node){
        return -1;
    }
    return ans->data;
}

int main(){
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    cout<<"enter k and node value"<<endl;
    int k,node;
    cin>>k;
    cin>>node;
    int ans = KthAncestor(root,k,node);
    cout<<"answer is "<<ans<<endl;

}