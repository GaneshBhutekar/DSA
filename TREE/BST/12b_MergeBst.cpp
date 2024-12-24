// turning tree into doubly linked list.
#include<queue>
#include<iostream>
#include<vector>
using namespace std;



class Node{
    public:
    int data;
    ListNode* left;
    ListNode* right;
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;

    }
};


// create the tree
ListNode* createtree(ListNode* root){
    cout<<"enter the data "<<endl;
    int data;
    cin>>data;
    if (data == -1){
        return NULL;
    }

    root = new Node(data);
    // gpr for the leftfirst 
    cout<<"left"<<endl;
    root->left = createtree(root->left);
    cout<<"riight"<<endl;
    root->right = createtree(root->right);

    return root;
}


// print the tree
void printtree(ListNode* root){
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


void DoublyLL(ListNode* root , ListNode* &head){
    if (root == NULL){
        return;
    }

    //go for right (it has also the reason  that if you go left you can't get last node you only have head and root at that time)
    DoublyLL(root->right,head);
    
    // you have to connect the right one with this current node
    root->right = head;
    // check that head is not null before assging 
    if (head != NULL){
        head->left = root;
    }
    head = root;

    DoublyLL(root->left,head);
}

void printLL(ListNode* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<endl;
}


ListNode* merge(ListNode* head1,ListNode* head2){
    // create Dummy one 
    ListNode* head = new Node(-1);
    ListNode* temp = head;
    ListNode* temp1 = head1;
    ListNode* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        // check which is smaller
        if (temp1->data <= temp2->data){
            temp->right = temp1;
            temp1->left = temp;
            temp = temp1;
            temp1 = temp1->right;
        }
        else{
            temp->right = temp2;
            temp2->left = temp;
            temp = temp2;
            temp2 = temp2->right;
        }
    }

    if (temp1 != NULL){
        temp->right = temp1;
        temp1->left = temp;
    }
    if(temp2 != NULL){
        temp->right = temp2;
        temp2->left = temp;
    }

    return head->right;
}

// make binary tree.
int count(ListNode* head){
    int n = 0;
    while(head != NULL){
        n+=1;
        head = head -> right;
    }
    return n;
}

ListNode* middleone(ListNode* head, int n){
    ListNode* mid = head;
    int i =1;
    while(i < n+1){
        mid = mid->right;
        i++;
    }
    return mid;

}

ListNode* MergeTree(ListNode* head,int n){

    if (n == 0 || head == NULL){
        return  NULL;
    }

    // find the middle element by n/2
    ListNode* mid = middleone(head,n/2);
    // find the root one from the head
    mid->left = MergeTree(head,n/2);
    // now connect right
    int right = n - (n/2) -1;
    mid->right = MergeTree(mid->right,right);

    return mid;

}

ListNode* MergeTree1(ListNode* &head, int n){
    if (n<=0 || head == NULL){
        return NULL;
    }
    ListNode* left = MergeTree1(head,n/2);
    ListNode* root = head;
    root->left = left;
    head = head->right; // doubt
    root->right = MergeTree1(head,n-n/2-1);

    return root;
}
int main(){
    ListNode* root1 = NULL;
    cout<<"ENTER DATA FOR ROOT 1"<<endl;
    // 50 40 30 -1 -1 45 -1 -1 60 55 -1 -1 70 -1 80 -1 -1
    root1 = createtree(root1);
    printtree(root1);

    // make this list doubly linked list.
    ListNode* head1 = NULL;
    DoublyLL(root1,head1);
    cout<<"printling doubling linked list for root 1"<<endl;
    printLL(head1);

    cout<<"ENTER DATA FOR ROOT2"<<endl;
    // 53 46 32 -1 -1 49 -1 -1 65 61 -1 -1 71 -1 85 -1 -1
    ListNode* root2 = NULL;
    root2 = createtree(root2);
    ListNode* head2 = NULL;
    DoublyLL(root2,head2);
    cout<<"printling doubling linked list for root 2"<<endl;
    printLL(head2);


    cout<<"merging both  the list "<<endl;
    ListNode* head = merge(head1,head2);
    printLL(head);

    int n = count(head);
    ListNode* root = MergeTree1(head,n);


    cout<<"PRINTING THE TREE"<<endl;

    printtree(root);
}