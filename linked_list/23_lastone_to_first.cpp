#include<iostream>
using namespace std;
class Node {
    public:
    int data ;
    ListNode*next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

void insertathead(ListNode*&head,int data){
    ListNode* temp= new Node(data);
    temp->next = head;
    head=temp;
    
}
void insertattail(ListNode* &tail,int data){
    ListNode* temp = new Node(data);
    tail->next = temp;
    tail=temp;
}
void print(ListNode* head){
    ListNode*temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void lasttofirst(ListNode*&head,ListNode* &tail){
    ListNode*temp=head;
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
    ListNode* newnode= new Node(10);
    ListNode* head= newnode;
    ListNode* tail = newnode;

    insertattail(tail,20);
    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,50);
    print(head);

    lasttofirst(head,tail);
    print(head);



}