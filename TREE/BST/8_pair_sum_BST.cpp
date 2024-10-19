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
        this->data = data;
        right = NULL;
        left = NULL;

    }

};






void print(Node* root){
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
Node* insert(Node* & root,int data){
    if (root == NULL){
        root = new Node(data);
        return root;
    }

    // just check that element is greater or not
    if (root->data > data){
        root->left = insert(root->left,data);
    }
    else {
        root->right = insert(root->right,data);
    }

    return root;

}

void insertTree(Node* &root){
    int data;
    cout<<"enter the dta"<<endl;
    cin>>data;
    while(data != -1){
        insert(root,data);
        cin>>data;
    }

}


int inorder(Node* root,vector<int> &arr){
    if (root == NULL){
        return 0;
    }

    // move leftmost 
    int left = inorder(root->left,arr);
    arr.push_back(root->data);
    int right = inorder(root->right,arr);
    return left + right +1;
}

bool check_pair(Node* root,int sum){
    vector<int> arr;
    int n = inorder(root,arr);


    // now check the sum using two pointer
    int start = 0;
    int end = n-1;
    while(start < end){
        if (arr[start] + arr[end] == sum){
            return true;
        }
        else if (arr[start ]+arr[end] < sum){
            // increase the start
            start++;
        }
        else{
            end--;
        }
    }
    return false;

}
int main(){
    Node* root = NULL;
    insertTree(root);
    print(root);
    // 10 6 12 2 8 11 15 -1
    // 13 6 4 3 7 14 18 15 16 -1

    // find the pair which sum is erqual to given sum
    // find the inorfer traversal store it and then find the pair
    cout<<"enter the sum do you want to find"<<endl;
    int sum;
    cin>>sum;
    if (check_pair(root,sum)){
        cout<<"yes the pair is present which sum is present in the tree"<<endl;
    }
    else{
        cout<<"no there is no any pair there"<<endl;
    }

}