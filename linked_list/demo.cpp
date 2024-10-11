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
Node* reverseit(Node* head){
    Node* curr=head;
    Node* prev = NULL;
    Node* forw = NULL;
    
    while(curr!=NULL){
        forw=curr->next;
        curr->next = prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}


Node* addOne(Node* head){
    head=reverseit(head);
    int carry=1;
    Node*temp = head;
    Node*prev=NULL;
    while(temp!=NULL){
        int sum = carry + temp->data;
        int ans = sum%10;
        temp->data = ans;
        carry = sum/10;
        prev=temp;
        temp=temp->next;
    }
    if (carry != 0){
        Node* newnode=new Node(carry);
        prev->next = newnode;
    }
    head=reverseit(head);
    return head;


}



int main(){
    Node* newnode= new Node(9);
    Node* head= newnode;
    Node* tail = newnode;

    insertattail(tail,9);
    insertattail(tail,9);
    print(head);
    head=addOne(head);
    print(head);


}