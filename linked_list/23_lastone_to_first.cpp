#include<iostream>
using namespace std;
class Node {
    public:
    int data ;
    Node*next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

void insertathead(Node*&head,int data){
    Node* temp= new Node(data);
    temp->next = head;
    head=temp;
    
}
void insertattail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail=temp;
}
void print(Node* head){
    Node*temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void lasttofirst(Node*&head,Node* &tail){
    Node*temp=head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    temp->next->next=head;
    head= temp->next;
    tail=temp;
    tail->next = NULL;
}
int main(){
    Node* newnode= new Node(10);
    Node* head= newnode;
    Node* tail = newnode;

    insertattail(tail,20);
    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,50);
    print(head);

    lasttofirst(head,tail);
    print(head);



}