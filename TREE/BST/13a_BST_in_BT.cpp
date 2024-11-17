#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};


// input in the binary search tree
Node* Tree(Node* root){
    int data;
    cout<<"enter data"<<endl;
    cin>>data;
    if (data == -1){
        return NULL;
    }
    root= new Node(data);

    // mobve left
    cout<<"left"<<endl;
    root->left = Tree(root->left);
    cout<<"right"<<endl;
    root->right = Tree(root->right);

    return root;
}


void print_tree(Node* root){
    if (root ==NULL){
        return;
    }
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
            if (demo ->right){
                q.push(demo->right);
            }
        }
    }

}

// MYAPPROACH .............

int solve(Node* root,int &smallest,int &largest,int &Largest_size){
    if (root==NULL){
        smallest = -1;
        largest = -1;
        return 0;
    }

    int left_size = solve(root->left,smallest,largest,Largest_size);
    // if left is true than check for this root and right
    int left_largest = largest;
    int right_size = solve(root->right,smallest,largest,Largest_size);
    int right_smallest = smallest;
    
    // update the smallest and the largest.
    if(smallest == -1 || smallest > root->data){
        smallest = root->data;
    }
    if (largest == -1 || largest < root->data){
        largest = root->data;
    }
    // if this current root is valid for bst than it is countable
    if ((root->data >= left_largest || left_largest == -1 )&& (root->data <= right_smallest || right_smallest == -1)){
        // update the largest_size continuously
        Largest_size = max(right_size+left_size+1,Largest_size);
        return right_size + left_size + 1;
    }

    else if (root->data >= left_largest || left_largest == -1){
        Largest_size = max(left_size+1,Largest_size);
        return 0;
    }
    else if (root->data <= right_smallest || right_smallest == -1){
        Largest_size = max(right_size+1,Largest_size);
    }
    
    return 0;


    
}
/// check for the correct BST
int validBst(Node* root){
    int smallest = -1; // represent that it is null
    int largest = -1;
    // and return the size if size is -1 it means till now from below there is no BST at all.
    int Largest_size = 0;
    solve(root,smallest,largest,Largest_size);
    return Largest_size;

}

int main(){
    Node* root = NULL;
    root= Tree(root);

    print_tree(root);
    // 1 2 4 -1 7 -1 -1 -1 7 3 -1 -1 6 4 0 -1 -1 5 -1 -1 10 -1 -1
    // 6 5 2 -1 -1 5 -1 -1 8 7 -1 -1 -1
    // 6 7 8 -1 -1 5 -1 -1 3 4 -1 -1 -1


    int ans = validBst(root);
    cout<<"biggest Bst exist of size "<<ans<<endl;

}