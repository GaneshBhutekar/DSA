//5754

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

int inorder(ListNode* root,vector<ListNode*> &sorted){
    if (root == NULL){
        return 0;
    }

    // go for left
    int left = inorder(root->left,sorted);

    sorted.push_back(root);

    int right = inorder(root->right,sorted);

    return right+left +1;
}

ListNode* balancingIt(vector<ListNode*> &sorted,int start,int end){
    if (start > end){
        return NULL;
    }

    // create the root node here 
    int mid = start+(end-start)/2;
    ListNode* top = sorted[mid];

    // go to the left
    top->left = balancingIt(sorted,start,mid-1);
    top->right = balancingIt(sorted,mid+1,end);

    return top;
}

ListNode* BalancedBst(ListNode* root){
    if (root == NULL){
        return NULL;
    }
    vector<ListNode*> sorted;
    int n = inorder(root,sorted);

    // after doiing this we have to recreate the tree from scratch using merge sort type
    ListNode* top = balancingIt(sorted,0,n-1);


    return top;
}
int main(){
    ListNode* root =  NULL;
    insertTree(root);
    cout<<"UNBALANCED TREE "<<endl;
    print(root);
    ListNode* ans = BalancedBst(root);
    cout<<"BALANCED TREE"<<endl;
    print(ans);
    // 50 30 70 20 35 60 80 5 28 34 43 68 25 -1
    // 10 8 12 4 16 2 20 -1
}

