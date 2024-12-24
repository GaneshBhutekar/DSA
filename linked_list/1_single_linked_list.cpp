#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    ListNode* next; // to stire next node address
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
void insertionAtHead(ListNode* &head,int data){
    ListNode* temp = new Node(data);
    temp->next=head;
    head=temp;

}

void print(Node * &head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void inserttionAtTail(Node * &tail,int data){
    Node *temp = new Node(data);
    tail->next=temp;
    tail=temp;

}

void InserttionAtPosition(Node * &tail,Node * &head,int position,int value){
    Node *temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if (position == 1){
        insertionAtHead(head,value);
        return;
    }
    if(temp->next == NULL){
        inserttionAtTail(tail,value);
        return;
    }

    Node * new_node=new Node(value);
    new_node-> next = temp->next;
    temp-> next = new_node;
}

void deletion(ListNode* &tail,Node * &head,int position){
    // deletion of start or first node
    if (position==1){
        Node * temp = head;
        head=temp->next;

        // freed the memory 
        temp->next=NULL;
        delete temp;
    }
    else{
        Node * prev = NULL;
        Node * curr = head;
        int cnt=1;
        while(cnt<position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        if (curr->next==NULL){
            tail=prev;
        }

        prev -> next = curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void deletion_by_value(Node * &tail,Node * &head,int value){
    Node *temp=head;
    int cnt=1;
    while(temp != NULL){

        if (temp->data==value){
            deletion(tail,head,cnt);
        }
        temp=temp->next;
        cnt++;
    }
}

int main(){
    Node *node1=new Node(10); // creating first node
    ListNode* head=node1;
    ListNode* tail=node1;
    print(head);
    // create new node
    inserttionAtTail(tail,30);
    print(head);
    // create new node
    inserttionAtTail(tail,40);
    print(head);
    // create new node
    inserttionAtTail(tail,60);
    print(head);
    //creation new node
    inserttionAtTail(tail,70);
    print(head);

    // insert at position
    InserttionAtPosition(tail,head,4,50);
    print(head);

    // insert at position 0 
    InserttionAtPosition(tail,head,1,5);
    print(head);

    // insertion at last
    InserttionAtPosition(tail,head,8,80);
    print(head);


    // deleting first node 
    deletion(tail,head,1);
    print(head);

    // deletion node
    deletion(tail,head,5);
    print(head);

    // deletion node 
    deletion(tail,head,6);
    print(head);

    // deletion by value.
    deletion_by_value(tail,head,30);
    print(head);
    cout<<"And tail is "<<tail-> data <<endl;
}