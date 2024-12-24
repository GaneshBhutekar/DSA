#include<iostream>
#include<vector> 
using namespace std;

// create a node which have down as well;

class Node{
    public:
    int data;
    ListNode* next;
    ListNode* down;
    Node(int data){
        this -> data = data;
        this ->next = NULL;
        this -> down = NULL;

    }

    // destructor for dynamic use.
    ~Node(){

    }
};

void insertHead(ListNode* &head,int element){
    ListNode* temp = new Node(element);
    temp->next = head;
    head = temp;
}

void insertTail(ListNode* &tail,int element){
    ListNode* temp = new Node(element);
    tail->next = temp;
    tail=temp;
}

void insertDown(ListNode* &top,int element){
    ListNode* temp = new Node(element);
    top->down = temp;
    top= temp;
}


ListNode*  merge_two_list(ListNode*temp1,ListNode*temp2){

    ListNode* ori_head = new Node(-1); // dummy node.
    Node * tail = ori_head;

    while(temp1!=NULL && temp2 != NULL){
        if (temp1->data <= temp2 -> data){
            tail->down = temp1;
            tail = temp1;
            temp1 = temp1->down;
            tail->down = NULL;

        }
        else{
            tail->down = temp2;
            tail= temp2;
            temp2 = temp2->down;
            tail->down = NULL;
        }
        
    }

    while(temp1!=NULL){
        tail->down = temp1;
        tail = temp1;
        temp1=temp1->down;
        tail->down = NULL;
    }

    while(temp2!=NULL){
        tail->down = temp2;
        tail= temp2;
        temp2= temp2->down;
        tail->down = NULL;
    }
    
    return ori_head->down;

}

ListNode* merge_down(ListNode* head){
    // doiing these through recurssion
    if (head->next == NULL){
        return head;
    }

    head->next = merge_down(head->next);

    return merge_two_list(head,head->next); // for last case head one is last and head -> next will be null;
}
void print_next(ListNode* head){
    ListNode* temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void print_down(ListNode* head){
    ListNode* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp -> down;
    }
    cout<<endl;
}


int main(){
    ListNode* newnode= new Node(2);
    ListNode* head = newnode;
    ListNode* tail = newnode;
    ListNode* down1 = newnode;
    insertDown(down1,16);

    // now next one

    insertTail(tail,3);
    ListNode* down2= tail;
    insertDown(down2,8);

    insertTail(tail,1);
    ListNode* down3 = tail;
    insertDown(down3,6);
    insertDown(down3,7);

    insertTail(tail,8);
    ListNode*down4 = tail;

    print_next(head);

    // merge them downwords

    ListNode* new_head = merge_down(head);
    print_down(new_head);
}
