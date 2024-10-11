#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
        this ->data = data;
        this -> right = NULL;
        this -> left = NULL;
    }
};


Node* inserting(Node* root,int data){
    if (root == NULL){
        root = new Node(data);
        return root;
    }


    if (root ->data > data){
        root ->left = inserting(root->left,data);
    }
    else{
        root ->right = inserting(root->right,data);
    }

    return root;
}


void print_tree(Node* root){
    if (root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* x = q.front();
        q.pop();

        if (x == NULL){
            cout<<endl;
            if (!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<x->data<<" ";
            if (x->left){
                q.push(x->left);
            }
            if (x->right){
                q.push(x->right);
            }
        }
    }
}
void insertBST(Node* &root){
    int data;
    cout<<"enter the data"<<endl;
    cin>> data;
    while(data != -1){
        root = inserting(root,data);
        cin>>data;
    }
}


int minimum(Node* root){
    if(root == NULL){
        return -1;
    }

    if (root ->left == NULL){
        return root->data;
    }
    return minimum(root->left);
}

int maximum(Node* root){
    if (root == NULL){
        return -1;
    }
    if (root->right == NULL){
        return root->data;
    }

    return maximum(root->right);
}


int inordersuccesor(Node* root,int data){
    if (root == NULL){
        return -1;
    }

    if (root->data == data){
        if (root->left){
            return root->left ->data;
        }
    }
    if (root->data > data){
        int ans = inordersuccesor(root->left,data);
        if (ans != -1){
            return ans;
        }
    }
    else{
        int ans = inordersuccesor(root->right,data);
        if (ans != -1){
            return ans;
        }
        // return -1;
    }
    return -1;
}

int inorderpredecer(Node* root,int data){
    if (root == NULL){
        return -1;
    }

    if (root->left && root->left ->data == data){
        return root->data;

    }
    if (root->right  && root->right->data == data){
        return root->data;
    }
    if (root->data > data){
        int ans = inorderpredecer(root->left,data);
        if (ans != -1){
            return ans;
        }
    }
    else{
        int ans = inorderpredecer(root->right,data);
        if (ans!= -1 ){
            return ans;
        }

    }
    return -1;
}
int main(){
    Node* root = NULL;
    insertBST(root);
    print_tree(root);
    // 21 12 7 20 26 23 8 3 28 27 -1 
    int min = minimum(root);
    cout<<"minimum value is "<<min<<endl;
    int max = maximum(root);
    cout<<"maximum value is "<<max<<endl;

    cout<<"enter the data to find it inorder predeccor and successor"<<endl;
    int num;
    cin>>num;


    // we can do simply thorough loop also.
    cout<<"succcessor " <<inordersuccesor(root,num)<<endl;
    cout<<"predesor "<<inorderpredecer(root,num)<<endl;

}