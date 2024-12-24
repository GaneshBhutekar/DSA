
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

ListNode* reversit(ListNode*head){
    ListNode*curr=head;
    ListNode* prev=NULL;
    ListNode* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;

    }
    return prev;
}

void insertnewnode(ListNode*&head,ListNode*&tail,int data){
    Node * temp=new Node(data);
    if (head==NULL){
        head=temp;
        tail=temp;
    }
    else{
    tail->next=temp;
    tail=temp;
    }
}
ListNode*  addition(ListNode*head1,ListNode*head2){  
    if (head1==NULL && head2==NULL){
        return NULL;
    }
    if (head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    // reverse the both array....
    ListNode*start1=reversit(head1);
    ListNode*start2=reversit(head2);
    ListNode*head=NULL;
    ListNode*tail=NULL;
    insertnewnode(head,tail,-1);
    
    
    int carry=0;
    while(start1!=NULL && start2!=NULL){
        int sum=carry+ start1->data+start2->data;
        int data = sum%10;
        carry = sum/10;
        insertnewnode(head,tail,data);
        start1=start1->next;
        start2=start2->next;
    }

    while(start1!=NULL){
        int sum=carry + start1->data;
        int data = sum%10;
        carry = sum/10;
        insertnewnode(head,tail,data);
        start1=start1->next;

    }

    while(start2!=NULL){
        int sum = carry + start2->data;
        int data = sum%10;
        carry = sum/10;
        insertnewnode(head,tail,data);
        start2=start2->next;
    }

    if (carry != 0){
        insertnewnode(head,tail,carry);
    }
    // reverse the answer again 
    head=head->next;
    head=reversit(head);
    return head;


}


ListNode* generic_addition(ListNode*head1,ListNode*head2){
    if (head1==NULL && head2==NULL){
        return NULL;
    }
    else if (head1==NULL){
        return head2;
    }
    else if (head2==NULL){
        return head1;
    }

    // reverse the lists
    ListNode* start1=reversit(head1);
    ListNode* start2=reversit(head2);
    
    // answer list
    ListNode*head=NULL;
    ListNode*tail=NULL;

    insertnewnode(head,tail,0);
    int carry = 0;
    while(start1 != NULL || start2 != NULL || carry != 0){
        
        int val1=0;
        if (start1!=NULL)
            val1=start1->data;
        
        int val2=0;
        if (start2 != NULL)
            val2 = start2->data;
        
        int sum = carry + val1 + val2;
        int digit = sum%10;
        insertnewnode(head,tail,digit);
        carry = sum/10;

        if (start1!=NULL)
            start1=start1-> next;
        if (start2!=NULL)
            start2=start2->next;
        

    }

    // now reverse the list.
    head= head->next;
    head=reversit(head);
    return head;


}





int main(){
    ListNode*node1=new Node(9);
    ListNode*head1=node1;
    ListNode*tail1=node1;
    insertatTail(tail1,8);
    insertatTail(tail1,7);
    insertatTail(tail1,5);
    
    ListNode*node2=new Node(6);

    ListNode*head2=node2;
    ListNode*tail2=node2;
    insertatTail(tail2,3);
    insertatTail(tail2,1);
    print(head1);
    print(head2);

    ListNode*head= generic_addition(head1,head2);
    print(head);
}
