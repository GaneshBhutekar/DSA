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
        this->right = NULL;
        this->left = NULL;
        this ->data = data;
    }
    ~Node(){
        cout<<"node deleted "<<endl;
    }
};


Node* insertRecursive(Node* root , int data){
    if (root == NULL){
        root = new Node(data);
        return root;
        // this will return the node which created to the prev node
    }

    if (root ->data > data){
        // go to left because you are small
        root->left = insertRecursive(root->left,data);

    }
    else{
        root ->right = insertRecursive(root->right,data);
    }

    return root;
}


void  createBST(Node* &root){
    cout<<"enter the data"<<endl;
    int data;
    cin>> data;
    while(data != -1){
        root = insertRecursive(root,data);
        cout<<"insert the data"<<endl;
        cin>>data;
    }

    
}
void  print_tree(Node* root){
    // level order traversal
    if (root == NULL){
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
            cout<<demo ->data<<" ";
            if (demo->left){
                q.push(demo->left);
            }
            if (demo->right){
                q.push(demo->right);
            }
        }
    }

}



// Node* DeleteTheNode(Node* &root,int data){ // bekar code hain pr tobhi acha socha time pass mt kar
//     if (root == NULL){
//         return NULL;
//     }

//     if (root ->data == data){
//         // check && 
//         if (!root ->left && !root->right ){
//             delete root;
//             return NULL;
//         }
//         if (root->left == NULL){
//             Node* todelete = root;
//             root = root->right;
//             todelete->right = NULL;
//             delete todelete;
//             return root->right;
//         }
//         else if (root->right == NULL){
//             Node* todelete = root;
//             root = root->left;
//             todelete ->left = NULL;
//             delete todelete;
//             return root;
//         }
//         else if (root->left ->right == NULL){
//             root->left->right = root->right;
//             Node* todelete = root;
//             root = root->left;
//             todelete->right = NULL;
//             todelete->left = NULL;
//             return root;
//         }
//         else{
//             cout<<"ji ha main yaha pe aya"<<endl;
//             Node* temp = root->left;
//             while(temp->right != NULL){
//                 temp = temp->right;
//             }
//             temp ->right = root->right;
//             Node* todelete = root;
//             root = root->left;
//             todelete->left = NULL;
//             todelete ->right = NULL;
//             delete todelete;
//             return root;
//         }


//     }

//     // move left and right to find the node
//     if (root->data > data){
//         root->left = DeleteTheNode(root->left,data);
//     }
//     else{
//         root->right = DeleteTheNode(root->right,data);
//     }
//     return root;

// }


Node* inorderPredecessor(Node* root){
    if (root == NULL){
        return NULL;
    }

    if (root->right == NULL){
        return root;
    }
    return inorderPredecessor(root->right);
}


Node* DeleteBst(Node* root ,int data){
    // base cases
    if (root == NULL){
        return NULL;
    }

    else if (root->data == data){
        // we have four cases
        // if there is not children node
        if (root->left == NULL && root ->right == NULL){
            delete root;
            return NULL;
        }

        // if there is left null

        else if (root->left != NULL && root->right == NULL){
            Node* temp = root ->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        // if there is right null
        else if (root ->left == NULL && root->right != NULL){
            Node* temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        // if both side is noon null

        else{
            // now find the predecessor
            cout<<"before"<<endl;
            int mini = inorderPredecessor(root->left)->data;
            cout<<"after"<<endl;
            // delete the node at that point 
            root->left = DeleteBst(root->left,mini);
            root->data = mini;
            return root;
        }
    }

    else if (root->data > data){
        root->left = DeleteBst(root->left,data);
    }
    else{
        root->right = DeleteBst(root->right,data);
    }

    return root;
}
int main(){
    Node* root = NULL;
    createBST(root);
    print_tree(root);
    // 100 50 110 25 70 60 120 115 111 116 125 121 126
    int num;
    cout<<"enter the num which you want to delete"<<endl;
    cin>>num;

    while(num != -1){
       root =  DeleteBst(root,num);
        print_tree(root);
        cout<<"without deleted  node tree will be is"<<endl;
        cin>>num;
    }


}