// Circular single linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data ;
        this -> next = NULL;

    }
    ~Node(){
        cout<<"deleting the data "<<this-> data <<endl;
    }
};
void insertionNode(Node*  &tail,int element,int data){
    // if the list is empty
    if (tail==NULL){
        Node *temp = new Node(data);

        tail=temp;
        temp->next=temp;
    }
    else{
        // create pointer to iterate.
        Node * curr = tail;
        while(curr->data != element){
            curr=curr->next;
        }
        Node * temp = new Node(data);
        temp->next = curr->next;
        curr->next=temp;

    }
}



void print(Node* &tail){
    if(tail==NULL){
        cout<<"empty hain"<<endl;
        return;
    }
    Node* temp=tail; // to iterate 
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp != tail){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(Node* &tail,int element){
    if (tail==NULL){
        cout<<"Pahle kuch daal to list main EMPTY hain"<<endl;
        
    }

    else{


        Node * prev = tail;
        Node * curr = tail->next;




        while(curr->data!=element){
            prev=curr;
            curr=curr->next;
        }

        if (prev==curr){  
            // because there is one node and when again we access the tail below it will segmentation fault
            tail=NULL;
        }
        else if (tail==curr){
            tail=prev;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }

}
int main(){

    Node *tail=NULL;
    insertionNode(tail,4,10);
    print(tail);
    deletion(tail,10);
    print(tail); 

    // new node
    insertionNode(tail,10,20);
    print(tail);

    // new node
    insertionNode(tail,20,30);
    print(tail);

    // new node
    insertionNode(tail,20,25);
    print(tail);

    // inserttion
    insertionNode(tail,30,10);
    print(tail);
    // deleting the node.
    deletion(tail,10);
    print(tail);   

    // inserting node
    insertionNode(tail,25,40);
    print(tail);

    // inserting node
    insertionNode(tail,40,50);
    print(tail);

    // deleting node
    deletion(tail,50);
    print(tail);
    cout<<"Tail is "<<tail->data<<endl;

    // deletion node
    deletion(tail,20);
    print(tail);


}
