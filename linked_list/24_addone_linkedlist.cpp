#include<iostream>
using namespace std;
class Node {
    public:
    int data ;
    ListNode*next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

void insertathead(ListNode*&head,int data){
    ListNode* temp= new Node(data);
    temp->next = head;
    head=temp;
    
}
void insertattail(ListNode* &tail,int data){
    ListNode* temp = new Node(data);
    tail->next = temp;
    tail=temp;
}
void print(ListNode* head){
    ListNode*temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
ListNode* reverseit(ListNode* head){
    ListNode* curr=head;
    ListNode* prev = NULL;
    ListNode* forw = NULL;
    
    while(curr!=NULL){
        forw=curr->next;
        curr->next = prev;
        prev=curr;
        curr=forw;
    }
    return prev;
}


ListNode* addOne(ListNode* head){
    head=reverseit(head);
    int carry=1;
    ListNode*temp = head;
    ListNode*prev=NULL;
    while(temp!=NULL){
        int sum = carry + temp->data;
        int ans = sum%10;
        temp->data = ans;
        carry = sum/10;
        prev=temp;
        temp=temp->next;
    }
    if (carry != 0){
        ListNode* newnode=new Node(carry);
        prev->next = newnode;
    }
    head=reverseit(head);
    return head;


}



int main(){
    ListNode* newnode= new Node(9);
    ListNode* head= newnode;
    ListNode* tail = newnode;

    insertattail(tail,9);
    insertattail(tail,9);
    print(head);
    head=addOne(head);
    print(head);


}