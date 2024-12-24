#include<iostream>
#include<vector>
using namespace std;
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

void sortthevector(vector<int> &storage){
    // using insertion sort.....
    for(int i=0;i<storage.size()-1;i++){
        int minimum=storage[i];
        int index=i;
        for(int j=i+1;j<storage.size();j++){
            if (storage[j]<minimum){
                minimum=storage[j];
                index=j;
            }
        }
            swap(storage[i],storage[index]);

    }
}

// approach one to solve the linked list to the flatten.
ListNode* flatten_downwards_1(ListNode*head){
    vector<int> storage;
    ListNode*temp=head;
    ListNode* temp1 = temp;

    while(temp!= NULL){
        while(temp1!=NULL){
            storage.push_back(temp1->data);
            temp1=temp1->down;
        }
        temp=temp->next;
        temp1=temp;
    }

    // now sort the vector........
    sortthevector(storage);

    // now paste this again in linkedlist

    ListNode*dummynode= new Node(-1);
    ListNode*new_head=dummynode;
    ListNode*new_down=dummynode;

    for(int i: storage){
        insertatdown(new_down,i);
    }
    return new_head->down;

}

ListNode* mergelist(ListNode* head1 , ListNode*head2){
    // create a dummy node
    ListNode* dummy_node= new Node(-1);
    ListNode*head= dummy_node;
    ListNode*tail=dummy_node;
    ListNode*t1 = head1;
    ListNode*t2=head2;

    while(t1!=NULL && t2!=NULL){
        if (t1->data <= t2->data){  
            tail->down=t1;
            tail=t1;
            t1=t1->down;
        }
        else{
            tail->down=t2;
            tail=t2;
            t2=t2->down; 
        }
        tail->next = NULL;
    }

    while(t1!=NULL){
        tail->down=t1;
        tail=t1;
        t1=t1->down;
        tail->next = NULL;
    }
    while(t2!= NULL){
        tail->down=t2;
        tail=t2;
        t2=t2->down;
        tail->next = NULL;
    }
    
    return head->down;


}

ListNode* flatten_downwards_2(ListNode*head){
    if (head->next == NULL){
        return head;
    }

    head->next = flatten_downwards_2(head->next);

    // merge it with head
    return mergelist(head,head->next);

    
}



int main(){
        ListNode* newnode= new Node(6);
        ListNode* tail = newnode;
        ListNode* head = newnode;
        ListNode* niche1 =newnode;

        insertattail(tail,3);
        ListNode* niche2 = tail;
        insertatdown(niche2,5);
        insertatdown(niche2,10);

        insertattail(tail,8);
        ListNode* niche3 = tail;
        insertatdown(niche3,9);
        insertatdown(niche3,10);

        insertattail(tail,11);
        ListNode*niche4 = tail;
        insertatdown(niche4,12);

        // print to checkout

        print(head);
        print_down(head);
        print_down(head->next);
        print_down(head->next->next);
        print_down(head->next->next->next);

        cout<<"after flatten linked list top to the down will be"<<endl;
        ListNode* new_head=flatten_downwards_1(head);
        print_down(new_head);

        cout<<"with another approach which is more efficient"<<endl;
        new_head= flatten_downwards_2(head);
        print_down(new_head);


}