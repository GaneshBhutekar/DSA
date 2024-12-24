#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

};

void insertionatHead(Node * &head,int data){
    ListNode* temp= new Node(data);
    temp->next=head;
    head=temp;
}
void insertionatTail(Node * &tail,int data){
    ListNode* temp = new Node(data);
    tail->next= temp;
    tail=temp;

}
void print(Node * &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}


bool check_loop(Node *head){
    ListNode*temp=head;
    map<ListNode*,bool> visited;
    while(temp!=NULL){
        if (visited[temp]==true){
            cout<<"Cycle is present at the element is (beginnining) "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

bool floyd_cycle_detection(Node * head){
    if (head==NULL){
        return false;
    }
    ListNode*slow=head;
    ListNode*fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast){

            cout<<"cycle is present at "<<slow->data<<endl;
            return true;
        }

    }

    return false;

}

Node * find_cycle_initial(ListNode*head){
    if (head==NULL){
        return head;
    }
    ListNode*fast=head;
    ListNode*slow=head;
    while(true){
        fast=fast->next->next;
        slow=slow->next;
        // if (fast->next == slow->next){

        // }
        if (fast == slow){
            slow=head;
            break;
        }
    }

    // find the initial position of cycle

    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return fast;

}

void remove_loop(ListNode* head){
    Node * intersection = find_cycle_initial(head);
    Node * temp=intersection;
    while(temp->next != intersection){
        temp=temp->next;
    }

    temp->next = NULL;

    cout<<"LOOP DESTROYED"<<endl;

}

int main(){
    Node *node1 = new Node(10);
    Node * head=node1;
    Node * tail=node1;
    insertionatTail(tail,20);

    insertionatTail(tail,30);
    insertionatTail(tail,40);
    insertionatTail(tail,50);
    insertionatTail(tail,60);

    tail->next=head->next->next;
    // cout<<"now tails next value is "<<tail->next->data<<endl;
    // print(head);

    // non loop kinked list 

    Node * node2 = new Node(10);
    Node * head2 = node2;
    Node * tail2 = node2;
    insertionatTail(tail2,20);

    insertionatTail(tail2,30);
    insertionatTail(tail2,40);
    insertionatTail(tail2,50);
    insertionatTail(tail2,60);
    print(head2);

    cout<<"check that loop is circular or not head"<<endl;
    cout<<" USE OF MAP"<<endl;
    // head and head2.
    if(check_loop(head2)){
        cout<<"It is circular"<<endl;
    }
    else{
        cout<<"It is not circular"<<endl;
        
    }

    cout<<"USING FLOYD CIRCULAR DETECTION"<<endl;
    if(floyd_cycle_detection(head)){
        cout<<"it is circular"<<endl;
    }
    else{
        cout<<"it is not circular"<<endl;
    }


    cout<<"finding the initial position of cycle in loop linked list"<<endl;

    Node * position=find_cycle_initial(head);
    cout<<"position of node which is point of initial value " <<position->data<<endl;
    
    remove_loop(head);
    print(head); 

}
