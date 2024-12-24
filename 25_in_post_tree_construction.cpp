#include<iostream>
#include<map>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this ->data = data;
        left = NULL;
        right = NULL;
    }
};


// construct the tree 

ListNode* solve(int post[],int in[],int &index,int start,int end,int n, map<int,int> &mp){

    // base case
    if (index < 0 || start > end){
        return NULL;
    }

    // element 
    int element = post[index--];
    // pahla jo hain vo node bana do
    ListNode* root = new Node(element);

    // find the position pf the element in in
    int position = mp[element];

    // now check it has left and roght

    root->right = solve(post,in,index,position+1,end,n,mp);

    root->left  = solve(post,in,index,start,position-1,n,mp);

    return root;

}




ListNode* buildTree(int n , int in[],int post[]){
    // traversal toh post se hoga
    // check ki right main node hain aur left main hain voh in karega.

    int index = n-1;

    map<int,int> mp;
    for(int i =0;i<n;i++){
        mp[in[i]] = i;
    }
    return solve(post,in,index,0,n-1,n,mp);

}
void print_tree(ListNode* root){

    if (root == NULL) return;
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
int main(){

    // postorder
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};

    // in
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};

    int n = 8;

    ListNode* root = buildTree(n,in,post);

    print_tree(root);




}