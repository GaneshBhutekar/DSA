#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next; // to stire next node address
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    // destructor when delete is used for this class 's object.
    ~Node(){
        cout<<"data deleted is "<<this -> data<<endl;

        delete next;
        // delete this ;
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

Node * reverse_in_group(Node * &head,int group){
    if (head==NULL){
        return NULL;
    }
    Node * curr= head;
    Node* next =NULL;
    Node * prev = NULL;
    int cnt=0;
    while(cnt<group && curr != NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }
    if (next != NULL){ // real base condition
        head->next=reverse_in_group(next,group);
    }
    return prev;
}
int main(){
    Node * node=new Node(10);
    Node * head=node;
    Node * tail=node;

    insertionatTail(tail,30);
    insertionatTail(tail,40);
    insertionatTail(tail,50);
    insertionatTail(tail,60);
    insertionatTail(tail,70);
    insertionatTail(tail,80);
    insertionatTail(tail,90);
    insertionatTail(tail,100);
    insertionatTail(tail,110);
    insertionatTail(tail,120);
    print(head);

    head=reverse_in_group(head,2);
    print(head);
    cout<<"prev is at "<<head->data<<endl;

}