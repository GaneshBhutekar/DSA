// DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int data)
    {   
        this-> data = data;
        this->prev=NULL;
        this->next = NULL;

    }
    ~Node(){
        cout<<"data is deleted which is "<<this-> data <<endl;
        
    }

};

void print(Node * &head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getlength(ListNode* &head){
    ListNode*temp=head;
    int length=0;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

void insertatHead(ListNode* &head,Node * &tail,int data){
    if (head==NULL){ // if head is empty (no node) then create first node and set it head
        ListNode* temp=new Node(data);
        head=temp;
        tail=temp; 
    }
    else{
        // create new node
        Node * temp = new Node(data);
        temp->next=head;
        head->prev = temp;
        head=temp;
    }
}

void insertatTail(ListNode* &head,ListNode* &tail,int data){
    if (tail==NULL){
        ListNode*temp = new Node(data);
        tail=temp;
        head=temp;
    }

    else{
        ListNode* temp = new Node(data);
        temp->prev = tail;
        tail->next=temp;
        tail = temp;

    }
}

void insertatPosition(Node * &tail,Node * &head,int data,int position){

    Node *temp = head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp-> next;
        cnt++;
    }
    if (temp == NULL){
        cout<<"OUT OF BOND HAI YEDYA"<<endl;
        return;
    }

    if (position==1){
        insertatHead(head,tail,data);
        return;
    }
    if (temp->next==NULL){
        insertatTail(head,tail,data);
        return;
    }


    Node * new_node=new Node(data);
    new_node->next=temp->next;
    temp->next->prev=new_node;

    temp->next=new_node;
    new_node->prev=temp;



}

void deletion(Node * &head,ListNode* &tail,int position){
    if (position==1){
        Node * temp = head;
        head=temp->next;
        temp-> next -> prev =NULL;
        temp-> next = NULL;
        delete temp;
    }
    else{
        Node * previous=NULL;
        Node * current = head;
        int cnt=1;
        while(cnt<position){
            previous=current;
            current=current->next;
            cnt++;
        }

        if (current -> next == NULL){
            tail=current->prev;
            tail->next=NULL;
        }
        else{
            previous->next=current->next; // current->prev->next
            current->next->prev=previous;    // current->prev;
        }

        current->next=NULL;
        current->prev = NULL;
        delete current;
    }
}

int main(){
    // let's say you started empty
    ListNode*head = NULL;
    Node * tail = NULL;
    
    // new node
    insertatHead(head,tail,5);
    print(head);

    //new node
    insertatHead(head,tail,1);
    print(head);
    cout<<"length right now is "<<getlength(head)<<endl;

    // new node 
    insertatTail(head,tail,20);
    print(head);

    // new node inserted.
    insertatPosition(tail,head,7,3);
    print(head);
    cout<<"tail is at "<<tail->data<<endl;
    cout<<"head is at "<<head->data<<endl;




    // new node inserted
    insertatPosition(tail,head,30,5);
    print(head);

    // new node insert
    insertatPosition(tail,head,0,1);
    print(head);

    //deletion of node
    deletion(head,tail,4);
    print(head);

    //deletion of node 
    deletion(head,tail,1);
    print(head);
    cout<<"Tail at this time is "<<tail->data<<endl;
    //deletion last node
    deletion(head,tail,4);
    print(head);
    cout<<"Now tail is "<<tail->data<<endl;


}