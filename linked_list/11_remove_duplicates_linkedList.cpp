#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }
    ~Node(){
        cout<<"destruct the duplicate node"<<endl;
    }

};

void insertionatHead(Node * &head,int data){
    Node* temp= new Node(data);
    temp->next=head;
    head=temp;
}
void insertionatTail(Node * &tail,int data){
    Node* temp = new Node(data);
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

void remove_duplicates(Node * head){ // myapproach
    if (head==NULL){
        return;
    }
    Node * temp= head;
    while(temp->next!=NULL){
        if (temp->next->data == temp->data){ 
            Node* todelete=temp->next;
            temp -> next = temp->next->next;
            todelete->next=NULL;
            delete todelete;


        }
        else{
            temp=temp->next;
        }
    }


}

void remove_unsortedlist_duplicates(Node*head){
    if (head==NULL){
        return;
    }
    Node*curr=head;
    Node*forward = head;
    while(curr->next != NULL){

    while(forward->next != NULL){
        if (curr->data == forward->next->data){
            Node*temp=forward->next;
            forward->next=forward->next->next;
            temp->next=NULL;
            delete temp;

        }
        else{
            forward=forward->next;
        }
    }
    curr=curr->next;
    forward=curr;
    }
}
int main(){
    Node* node = new Node(10);
    Node* head=node;
    Node * tail = node;

    insertionatTail(tail,20);
    insertionatTail(tail,20);
    insertionatTail(tail,20);
    insertionatTail(tail,30);
    insertionatTail(tail,30);
    insertionatTail(tail,40);
    insertionatTail(tail,50);
    insertionatTail(tail,60);
    insertionatTail(tail,70);
    insertionatTail(tail,70);

    print(head);


    cout<<"remove duplicates"<<endl;
    remove_duplicates(head);
    print(head);


    cout<<"For Unsorted Linked list removing duplicate value is "<<endl;
    Node * node1=new Node(1);
    Node*head1=node1;
    Node*tail1=node1;
    insertionatTail(tail1,6);
    insertionatTail(tail1,1);
    insertionatTail(tail1,4);
    insertionatTail(tail1,1);
    insertionatTail(tail1,4);
    insertionatTail(tail1,6);
    insertionatTail(tail1,8);
    insertionatTail(tail1,15);
    insertionatTail(tail1,18);
    insertionatTail(tail1,0);
    insertionatTail(tail1,3);
    insertionatTail(tail1,5);
    insertionatTail(tail1,15);
    insertionatTail(tail1,15);
    print(head1);

    remove_unsortedlist_duplicates(head1);
    print(head1);


}