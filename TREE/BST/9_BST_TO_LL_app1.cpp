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
        right = NULL;
        left = NULL;

    }

};






void print(ListNode* root){
    if (root == NULL){
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
            if (demo->right){
                q.push(demo->right);
            }
        }
    }
}
ListNode* insert(ListNode* & root,int data){
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

void insertTree(ListNode* &root){
    int data;
    cout<<"enter the dta"<<endl;
    cin>>data;
    while(data != -1){
        insert(root,data);
        cin>>data;
    }

}

ListNode* predecessor(ListNode* curr){
    ListNode* pred = curr->left;
    while(pred->right != NULL){
        pred = pred -> right;
    }
    return pred;
}

ListNode* successor(ListNode* curr){
    ListNode* succ = curr->right;
    while(succ ->left != NULL){
        succ = succ->left;
    }
    return succ;
}
ListNode* BST_to_LL(ListNode* root){
    // check first it is null or not
    if (root == NULL){
        return NULL;
    }

    ListNode* curr = root;
    ListNode* start;
    int min = curr->data;
    while(curr != NULL){
        // check is there left have 
        if (curr->data < min){
            start = curr;
            min = curr->data;
        }
        if (curr->left){
            // check for the predecessor;
            ListNode* pred = predecessor(curr);
            // now connect the 
            pred -> right = curr;
            // remove curr ka left
            ListNode* temp = curr->left;

            curr->left = NULL;
            // temp= curr;
            curr= temp;
        }

        else{
            // this mean there is not left node so here 
            // we have to find successor 
            // so here have three problem
            // first if curr right is NULL then do nothing just do next
            // second there is to find the successor and connect curr right tp that successor
            if (curr->right != NULL){
                ListNode* succ = successor(curr);
                //store the curr right  first
                ListNode* temp = curr->right;
                curr->right = succ;
                curr = temp;
            }
            else{
                curr = curr->right;
        }
    }

}
    return start;
}


void print_list(ListNode* start){
    while(start != NULL){
        cout<<start->data<<" ";
        start = start->right;
    }
    cout<<endl;
}
int main(){
    ListNode* root = NULL;
    insertTree(root);
    // 10 5 15 3 7 11 16 21 4 24 22
    print(root);
    ListNode* x = BST_to_LL(root);
    cout<<"printing the LL"<<endl;
    print_list(x);
}