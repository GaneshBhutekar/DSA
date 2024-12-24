
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
void count(ListNode*head,vector<int> &value){
    ListNode*temp=head;
    while(temp!=NULL){
        if (temp->data == 0){
            value[0]=value[0]+1;
            
        }
        if (temp->data == 1){
            value[1]=value[1]+1;
        }
        else{
            value[2]=value[2]+1;
        }
        temp=temp->next;
    }
}
void approach_one(ListNode*head){
    vector<int> value(3,0);
    count(head,value);
    ListNode*temp=head;
    while(temp!=NULL){
        if (value[0]>0){
            temp->data = 0; 
            value[0]=value[0]-1;           
        }
        else if (value[0]==0 && value[1]>0){
            temp->data = 1;     
            value[1]=value[1]-1;       
        }
        else{
            temp->data=2;
            value[2]=value[2]-1;
        }
        temp=temp->next;
    }

}
ListNode* approached_two(ListNode*head){
    ListNode*zeros=new Node(0);
    ListNode*head_zeros=zeros;
    ListNode*tail_zero=zeros ;
    ListNode*ones=new Node(0);
    ListNode*head_ones=ones;
    ListNode*tail_ones=ones;
    ListNode*two = new Node(0);
    ListNode*head_two=two;
    ListNode*tail_twos=two;

    ListNode*temp=head;
    while(temp!=NULL){
        if (temp->data == 0){
            insertatTail(tail_zero,0);
        }
        else if (temp->data == 1){
            insertatTail(tail_ones,1);
        }
        else{
            insertatTail(tail_twos,2);
        }
        temp=temp->next;

    }
    if (head_ones->next == NULL){
        tail_zero->next = head_two->next;
    }
    else{
    tail_zero->next=head_ones->next;
    tail_ones->next=head_two->next;
    }
    ListNode*todelete=head_zeros;
    head_zeros=head_zeros->next;
    todelete->next=NULL;
    delete todelete;
    delete head_ones;
    delete head_two;
    return head_zeros;


}
int main(){
    ListNode* temp=new Node(1);
    ListNode*head=temp;
    ListNode*tail=temp;

    insertatTail(tail,1);
    insertatTail(tail,0);
    insertatTail(tail,1);
    insertatTail(tail,2);
    insertatTail(tail,0);

    print(head);

    approach_one(head);
    cout<<"we are here"<<endl;
    print(head);

    ListNode*new_head=approached_two(head);
    cout<<"answer is "<<endl;
    print(new_head);
    
}