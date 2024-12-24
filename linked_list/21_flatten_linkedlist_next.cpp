#include<iostream>
using namespace std;


// here we done this in next single child linked list but we want it to flatten it to child i mean
// 1->2->3->4    xxxx
/* 1
   |
   2
   |
   3
   |
   4|

*/


class Node{
    public:
    int data;
    ListNode* next ;
    ListNode* down;
    Node(int data){
        this-> data = data;
        this -> next = NULL;
        this ->down=NULL;

    }
};

void insertathead(ListNode* &head,int data){
    ListNode* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertattail(ListNode* &tail,int data){
    ListNode* temp = new Node(data);
    tail->next = temp;
    tail=temp;

}
void insertatdown(ListNode* & niche,int data ){
    ListNode* temp = new Node(data);
    niche->down = temp;
    niche = temp;
}
void print(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void print_down(ListNode* head){
    ListNode*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->down;
    }
    cout<<endl;
}


ListNode* Merge2Sort(ListNode* head1,ListNode*head2){
    if (head1==NULL){
        return head2;
    }
    if (head2==NULL){
        return head1;
    }
    ListNode* new_list = new Node(-1); // dummy node.
    ListNode* tail= new_list;
    ListNode* head = new_list;

    ListNode* temp1 = head1 ;// traverse through down member.
    ListNode* temp2 = head2 ;// traverse through next member.

    while(temp1 != NULL && temp2 != NULL){
        if (temp1 ->data <= temp2 -> data ){
            insertattail(tail,temp1->data);
            temp1=temp1->down;
        }
        else{
            insertattail(tail,temp2->data);
            temp2=temp2->next;
        }
    }

    while(temp1!= NULL){
        insertattail(tail,temp1->data);
        temp1=temp1->down;
    }
    while(temp2!=NULL){
        insertattail(tail,temp2->data);
        temp2=temp2->next;

    }
    return head->next;

}

ListNode* flatten(ListNode* head){
    if (head==NULL  || head->next == NULL){
        return head;
    }
    

    
    head->next  = flatten(head->next); // provide head of the sorted list.

    // now merge and sort the head and the temp list 
    head = Merge2Sort(head,head->next);

    // return the head.
    return head;

}
int main(){
    ListNode* node= new Node(50);
    ListNode* head=node;
    ListNode* tail = node;

    insertattail(tail,30);
    insertattail(tail,40);
    insertattail(tail,60);

    print(head);

    // setting down pointer;
    ListNode* niche1 = head;
    insertatdown(niche1,60);
    insertatdown(niche1,70);
    insertatdown(niche1,75);
    
    ListNode* niche2 = head->next;
    insertatdown(niche2,31);
    insertatdown(niche2,32);

    ListNode* niche3 = head->next ->next ;
    insertatdown(niche3,44);    
    insertatdown(niche3,48);

    ListNode* niche4 = head->next->next ->next ;
    insertatdown(niche4,65);

    print_down(head->next->next->next);


    ListNode* merged_to_flatten = flatten(head);
    cout<<"flattened the branched linked list"<<endl;
    print(merged_to_flatten);





    
}