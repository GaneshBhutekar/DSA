

// sort using map
#include<iostream>
#include<vector>
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
        cout<<"deleting something ..."<<endl;
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
ListNode* mergeit(ListNode* head1,ListNode*head2){
    if (head1==NULL){
        return head2;
    }
    else if (head2==NULL){
        return head1;
    }
    ListNode*temp1=head1;
    ListNode*temp2=head2;
    ListNode*newnode=new Node(0);
    ListNode*head=newnode;
    ListNode*tail=newnode;

    while(temp1 != NULL && temp2 != NULL){
        if (temp1->data <= temp2->data){
            insertatTail(tail,temp1->data);
            temp1=temp1->next;
        }
        else{
            insertatTail(tail,temp2->data);
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        insertatTail(tail,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insertatTail(tail,temp2->data);
        temp2=temp2->next;
    }
    ListNode*todelete=head;
    head=head->next;
    todelete->next=NULL;
    return head;

}

ListNode* mergeit_approach2(Node * head1,ListNode*head2){
    if (head1==NULL){
        return head2;
    }
    else if (head2==NULL){
        return head1;
    }
    ListNode*temp1;
    ListNode*temp2;
    ListNode*final_head;
    if (head1->data >= head2->data){
        temp1=head2;
        temp2=head1;
        final_head=head2;
    }
    else{
        temp1=head1;
        temp2=head2;
        final_head=head1;
    }

    while(temp2 !=NULL && temp1 ->next !=NULL){
        if (temp1->next->data > temp2->data){
            ListNode*demo=temp2;
            temp2=temp2->next;
            demo->next = temp1->next;
            temp1->next=demo;
        }
        else{
            temp1=temp1->next;
        }

    }
    while(temp2!=NULL){
        ListNode*demo=temp2;
        temp2=temp2->next;
        temp1->next =demo;    
    }
    return final_head;
}
int main(){
    ListNode*node1=new Node(1);
    ListNode*head1=node1;
    ListNode*tail1=node1;
    insertatTail(tail1,4);
    insertatTail(tail1,5);
    insertatTail(tail1,6);
    insertatTail(tail1,6);
    print(head1);

    ListNode*node2=new Node(2);
    ListNode*head2=node2;
    ListNode*tail2=node2;
    insertatTail(tail2,3);
    insertatTail(tail2,5);

    print(head2);

    cout<<"merge it approach 1"<<endl;
    ListNode* head=mergeit(head1,head2);
    print(head);
    cout<<"merge it approach 2"<<endl;
    head=mergeit_approach2(head1,head2);
    print(head);





}