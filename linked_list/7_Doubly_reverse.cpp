// reverse the doubly linked list

#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node* prev;
    Node* next;
    Node(int data){
        this-> data = data;
        this-> prev = NULL;
        this-> next =NULL;
    }
};

void insertatHead(Node * &head,int data){
    Node * temp = new Node(data);
    temp->next= head;
    head->prev = temp;
    head=temp;

}

void insertionatTail(Node * & tail,int data){
    Node* temp = new Node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverse_doubly(Node* head){
    Node*previous=NULL;
    Node* curr = head;
    Node* forward = NULL;
    while(curr != NULL){
        forward=curr->next;
        curr->next=previous;
        curr->prev=forward;
        previous=curr;
        curr=forward;

    }
    return previous;

}

void recurrsive_reverse(Node * &head ,Node *curr,Node*previous){
    if (curr == NULL){
        head=previous;
        return;
    }


    recurrsive_reverse(head,curr->next,curr);

    curr->prev=curr->next;
    curr->next=previous;
}

Node* reverseit(Node*head){
    Node*previous=NULL;
    Node*curr=head;
    recurrsive_reverse(head,curr,previous);
    return head;

}
int main(){
    Node *node=new Node(10);
    Node*tail=node;
    Node*head=node;
    
    insertionatTail(tail,20);
    insertionatTail(tail,30);
    insertionatTail(tail,40);
    insertionatTail(tail,50);
    insertionatTail(tail,60);
    insertionatTail(tail,70);
    insertionatTail(tail,80);
    insertionatTail(tail,90);
    print(head);
    head=reverse_doubly(head);
    print(head);

    head=reverseit(head);
    print(head);

}