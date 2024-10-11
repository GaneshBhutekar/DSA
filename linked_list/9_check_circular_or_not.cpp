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
class Node2{
    public:
    int data;
    Node2*next;
    Node2(int data){
        this -> data = data;
        this-> next = this;

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

void Insertionincircular(Node2 * tail,int position,int data){ 
    Node2*temp=new Node2(data);
    Node2 * curr = tail;
    
    while(curr->data != position){
        curr =curr-> next;
    }
    temp->next=curr->next;
    curr->next= temp;
}
void print_circular(Node2* tail1){
    Node2 * temp=tail1->next;
    cout<<tail1->data<<" ";

    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp->data != tail1->data);
    cout<<endl;
    
}

void print(Node * &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}

bool check_circular_or_not(Node2 * tail){
    if (tail==NULL){
        return true;
    }
    Node2 *temp = tail->next;
    while(temp->next != NULL && temp!=tail){
        temp=temp->next;
    }
    if (temp== tail) return true;
    return false;
}
int main(){
    Node* node = new Node(10);
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
    insertionatTail(tail,100);
    print(head);


    Node2 * node1 = new Node2(10);
    Node2*tail1=node1;

    Insertionincircular(tail1,10,20);
    Insertionincircular(tail1,20,30);
    Insertionincircular(tail1,30,40);
    Insertionincircular(tail1,40,50);
    Insertionincircular(tail1,50,60);
    Insertionincircular(tail1,60,70);



    print_circular(tail1);


    cout<<"Before going to check it know that check_circular_or_not have either work for Node and Node2"<<endl;
    // for not circular
    // check for tail and tail1
    if (check_circular_or_not(tail1)){
        cout<<"yes it is circular";
    }
    else{
        cout<<"no it is not circular"<<endl;
    }


}