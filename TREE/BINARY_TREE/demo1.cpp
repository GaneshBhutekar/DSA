#include<iostream>
#include<vector>
using namespace std;
class node {
    public:
    int data= data;
    node* next = NULL;
    node(int data){
        this ->data = data;
        next = NULL;
    }
    ~node(){

    }
};

void InsertHead(node* &head,int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

void InsertTail(node* &tail,int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}


// find the half 
node* find_half(node* head){
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast ->next ->next;
        slow = slow->next;
    }
    return slow;
}

// find the middle value
node* reverse(node* head){
    node* curr = head;
    node* next = NULL;
    node* prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
    }

    return prev;
}
bool is_Palindrome(node* head){
    // find mid value then send other half for the reversing
    if (head->next == NULL){
        return true;
    }
    node* mid = find_half(head);
    mid->next =reverse(mid->next);
    node* temp1 = head;
    node* temp2 = mid->next;
    while(temp2 != NULL){
        if (temp1->data != temp2->data){
            return false;
        }
        temp1= temp1->next;
        temp2 = temp2 ->next;
    }
    return true;
}



void print_list(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}
int main(){
    node* newnode = new node(1);
    node* head = newnode;
    node* tail = newnode;

    int data=0;
    while (data != -111){
        cout<<"enter the data "<<endl;
        cin>>data;
        if (data != -111){
            InsertTail(tail,data);
        }
    }
    print_list(head);
    if (is_Palindrome(head)){
        cout<<"it is palindrome"<<endl;
    }
    else{
        cout<<"it is not palindrome"<<endl;
    }

    // using srac

}