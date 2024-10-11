#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this-> data=data;
        this-> next=NULL;

    }
};
void insertatHead(Node * &head,int data){
    Node *temp = new Node(data);
    temp->next=head;
    head=temp;

}
void insertatTail(Node*&tail,int data){
    Node * temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

int givelength(Node* head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

// approach one.
Node* FindMidelement(Node * &head){
    int length=givelength(head);
    int mid=length/2;
    Node*temp=head;
    int cnt=0;
    while(cnt<mid){
        temp= temp->next;
        cnt++;
    }
    return temp;
}

// second approach 
Node * Findmidelement2(Node*head){
    if(head == NULL || head ->next== NULL){
        return head;
    }
    if (head->next->next = NULL){
        return head->next;
    }

    Node*Fast=head;
    Node*slower=head;
    while(Fast!=NULL && Fast -> next != NULL){
        Fast = Fast->next->next; // 2x speed.
        slower=slower->next;
    }
    return slower;
}

void print(Node * head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;

}



int main(){
    Node * node=new Node(10);
    Node * head = node;
    Node*tail=node;
    print(head);

    insertatTail(tail,20);
    insertatTail(tail,30);
    insertatTail(tail,40);

    print(head);

    Node * ans = FindMidelement(head);
    cout<<ans->data<<endl;

    insertatTail(tail,50);
    insertatTail(tail,60);
    insertatTail(tail,70);

    print(head);

    Node * mid = Findmidelement2(head);
    cout<<"mid is "<<mid->data<<endl;

    insertatTail(tail,80);
    print(head);
    mid=Findmidelement2(head);
    cout<<"mid one is "<<mid->data<<endl;




}