#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

};

void insertionatHead(Node * &head,int data){
    ListNode* temp= new Node(data);
    temp->next=head;
    head=temp;
}
void insertionatTail(Node * &tail,int data){
    ListNode* temp = new Node(data);
    tail->next= temp;
    tail=temp;

}
void print(Node * &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}

ListNode* reversing_approach1(ListNode* &head){

    if(head==NULL || head-> next == NULL){
        return head;
    }
    Node * prev = NULL;
    Node * curr = head;
    Node * forword = NULL;
    while(curr!=NULL){
        forword=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forword;
    }
    return prev;
}

void reverse_approach2(ListNode* &head,ListNode*curr,ListNode*prev){
    if (curr==NULL){
        head=prev;
        return;
    }
    reverse_approach2(head,curr->next,curr);
    curr->next=prev;
}

ListNode* reverseit(ListNode*head) {
    ListNode* prev=NULL;
    ListNode* forword=NULL;
    ListNode* curr = head;
    reverse_approach2(head,curr,prev);
    return head;
    
}
ListNode* reverse_approach3(ListNode*head){
    if (head==NULL || head-> next == NULL){
        return head;
    }

    Node * chota_head=reverse_approach3(head->next);
    head->next->next=head;
    head->next=NULL;
    return chota_head;
}
int main(){
    Node *node1 = new Node(10);
    Node * head=node1;
    Node * tail=node1;
    insertionatTail(tail,20);

    insertionatTail(tail,30);
    insertionatTail(tail,40);
    insertionatTail(tail,50);
    print(head);

    // reverse th list.
    head=reversing_approach1(head);
    print(head);

    head=reverseit(head);
    print(head);

    head=reverse_approach3(head);
    print(head);



}