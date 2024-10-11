
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
void insertatTail(Node*&tail,int data){
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

int add_element(Node*head,vector<int> &array){
    Node*temp=head;
    int length=0;
    while(temp!=NULL){
        array.push_back(temp->data);
        length++;
        temp=temp->next;
    }
    return length;

}
bool check_palindrome(Node* head){
    // traverse to store value in array;
    vector<int> array;
    int length=add_element(head,array);
    int i=0;
    int j=length-1;
    while(i<=j){
        if (array[i]!=array[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int check_length(Node* head){
    Node*temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;

}
bool check_palindrome_approach2(Node*head){  // [1,3,1,3] not good approach 
    int length=check_length(head);
    int mid=0;
    if (length&1){
        mid=(length/2)+1;
    }
    else{
        mid=length/2;
    }
    Node*temp=head;
    int cnt=0;
    while(cnt!=mid){
        temp=temp->next;
        cnt++;
    }
    int total=0;
    Node*start=head;
    while(temp!=NULL){
        total+=start->data;
        total-=temp->data;
        start=start->next;
        temp=temp->next;
    }
    if (total==0){
        return true;
    }
    else{
        return false;
    }

}


Node* MidValue(Node*head){
    Node*fast=head->next;
    Node*slow=head;
    while(fast!=NULL && fast->next != NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;

}
Node* reverseit(Node* head ){
    Node*prev=NULL;
    Node*curr=head;
    Node*forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
bool check_palindrome_approach_3(Node*head){
    // find mid
    Node* mid=MidValue(head);
    // reverse it from that mid.
    Node*head1=head;
    mid->next=reverseit(mid->next);
    //check palindrome
    Node*head2=mid->next;
    bool ans=true;
    while(head2!=NULL){
        if (head1->data != head2->data){
            ans=false;
            break;
        }
        head1=head1->next;
        head2=head2->next;
    }
    // ans=true;
    mid->next=reverseit(mid->next);
    return ans;


}
int main(){
    Node* node1 = new Node(1);
    Node*head=node1;
    Node*tail=node1;

    insertatTail(tail,3);
    insertatTail(tail,2);
    insertatTail(tail,3);
    insertatTail(tail,1);
    print(head);

    if(check_palindrome_approach_3(head)){
        cout<<"it is palindrome"<<endl;
    }
    else{
        cout<<"it is not palindrome"<<endl;
    }
    Node* mid=MidValue(head);
    cout<<mid->data<<endl;






}