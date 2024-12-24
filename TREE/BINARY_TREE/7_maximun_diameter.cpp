#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// here node is 1 unit of the diameter.
class node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    node(int data){
        this->data = data;
        this-> right = NULL;
        this -> left = NULL;

    }


};

ListNode* buildtree(ListNode*& root){
    int data;
    cout<<"enter the data "<<endl;
    cin>>data;

    if (data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"LEFT"<<endl;
    root->left = buildtree(root->left);
    cout<<"RIGHT"<<endl;
    root->right = buildtree(root->right);

    return root;
    
}

void print_tree(ListNode* root){
    queue<ListNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        ListNode* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp ->data<<" ";
            if (temp->left != NULL){
                q.push(temp->left);
            }
            if (temp -> right != NULL){
                q.push(temp->right);
            }
        }
    }
}

int solve(ListNode* root, int & large_diameter){

    if (root == NULL){
        return 0;
    }

    int for_left = solve(root->left,large_diameter);

    int for_right = solve(root->right,large_diameter);

    
    // before returning something check that current diameter is greater or not
    int curr = for_left + for_right + 1 ;// 1 for this curr node
    if (large_diameter < curr){
        large_diameter = curr;
    }
    
    if (for_left > for_right){
        return 1+ for_left;

    }
    else{
        return 1+for_right;
    }
}

int find_diameter(ListNode* root){
    int large_diameter = 0;
    solve(root,large_diameter);
    return large_diameter;
    
}



int main(){
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3 8 -1 9 -1 -1 6 -1 -1 

    // 1 2 4 -1 -1 5 7 -1 -1 -1 
    ListNode* root = NULL;
    buildtree(root);
    print_tree(root);
    int ans = find_diameter(root);
    cout<<"largest diameter for this tree is "<<ans<<endl;

}