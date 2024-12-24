// sort using map
#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this-> data=data;
        this-> next=NULL;

    }
    ~Node(){
    }
};
void insertatHead(Node * &head,int data){
    Node *temp = new Node(data);
    temp->next=head;
    head=temp;

}
void insertatTail(ListNode*&tail,int data){
    Node * temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void print(Node * head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;

}
void delete_duplicates(ListNode*&head){
    if (head==NULL){
        return;
    }
    map<int,bool> taken;
    ListNode*temp=head;
    taken[temp->data]=true;
    while(temp!=NULL && temp->next!=NULL){
        if (taken[temp->next->data] == true){
            ListNode*todelete=temp->next;
            temp->next=temp->next->next;
            todelete->next=NULL;
            delete todelete;
        }
        else{
            taken[temp->next->data]=true;
            temp=temp->next;
        }
    }
}

int main(){
    ListNode*node=new Node(10);
    ListNode*tail=node;
    ListNode*head=node;
    insertatTail(tail,5);
    insertatTail(tail,7);
    insertatTail(tail,3);
    insertatTail(tail,18);
    insertatTail(tail,18);
    insertatTail(tail,13);
    insertatTail(tail,0);
    insertatTail(tail,5);
    insertatTail(tail,13);
    print(head);
    cout<<"after deleting duplicates"<<endl;
    delete_duplicates(head);
    print(head);

}

