#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    ListNode* right;
    ListNode* left;
    Node(int data){
        this ->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// now insert the element.
void printit(ListNode* root){
    if(root == nullptr){
        return;
    }
    queue<ListNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        ListNode* demo = q.front();
        q.pop();
        if (demo == nullptr){
            cout<<endl;
            if (!q.empty()){
                q.push(nullptr);
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

ListNode* insert(ListNode* root){
    int data;
    // cout<<"enter the data"<<endl;
    cin>>data;
    if (data == -1){
        return nullptr;
    }

    root = new Node(data);

    // go to the left
    root->left= insert(root->left);

    // go to the right
    root->right = insert(root->right);

    return root;

}



// now we have the binary tree now check whether it is max heap or not
// This one is more gppd than recursion because we don't need to count the total no. of element.
bool level_wise_check(ListNode* root){
    // here we don't need total number of  elements 
    queue<ListNode*> q;
    q.push(root);
    ListNode* demo = root;
    while(demo != nullptr){
        // when you encountered first null 
        q.pop();
        // jo bhi hain smne daal de
        q.push(demo->left);
        q.push(demo->right);
        demo = q.front();

        
    }

    // now here demo has front null now remove all thge element if any element is not null then it is not heap
    while(!q.empty()){
        if(q.front() != nullptr){
            return false;
        }
        q.pop();
    }
    return true;

}



bool CBT(ListNode* root,int n,int i){
    // i is index right now and n is total number of node

    if(root == nullptr){
        return true;
    }
    if (i>n){
        return false;
    }

    i= 2*i;
    // go for the left
    bool left = CBT(root->left,n,i);
    bool right = CBT(root->right,n,i+1);
    return left & right;

}


int count_nodes(ListNode* root){
    if (root == nullptr){
        return 0;
    }

    // go for left
    int left = count_nodes(root->left);
    int right = count_nodes(root->right);

    return left+right+1;
}


bool maxHeap(ListNode* root){
    if (root == nullptr){
        return true;
    }

    // go left most
    bool left = maxHeap(root->left);
    // go for the right
    bool right = maxHeap(root->right);

    // current node sitiatiom
    bool current = false;
    if (( root->left == nullptr || root->data > root->left->data) && (root->right == nullptr || root->data > root->right->data)){
        current = true;
    }
    return left & right & current;
}
bool check_heap(ListNode* root){
    /*
    There are 2 ways to check the complete binary tree or not
        1. recursion
        2. level order traversal

    We can check max heap by travsersing over the child node which should be smaller than the parent
    */
   // count the nodes
   int n = count_nodes(root);
   int i = 1;
   if( level_wise_check(root) && maxHeap(root)){
        return true;
   }
   else{
    return false;
   }


}
int main(){
    // correct heaap 100 80 45 10  -1 -1 -1 75 -1 -1 90 85 -1 -1 60 -1 -1
    // 100 50 30 15 -1 -1 -1 45 -1 -1 40 -1 -1
    // 100 80 60 -1 -1 40 -1 -1 90 95 -1 -1 -1 
    ListNode* root = nullptr;
    // insert the datra
    root = insert(root);
    printit(root);
    if(check_heap(root)){
        cout<<"yes!!"<<endl;
    }
    else{
        cout<<"no!!!"<<endl;
    }
}