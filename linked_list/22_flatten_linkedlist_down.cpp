#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next ;
    Node* down;
    Node(int data){
        this-> data = data;
        this -> next = NULL;
        this ->down=NULL;

    }
};

void insertathead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
void insertattail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail=temp;

}
void insertatdown(Node* & niche,int data ){
    Node* temp = new Node(data);
    niche->down = temp;
    niche = temp;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void print_down(Node* head){
    Node*temp=head;
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
Node* flatten_downwards_1(Node*head){
    vector<int> storage;
    Node*temp=head;
    Node* temp1 = temp;

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

    Node*dummynode= new Node(-1);
    Node*new_head=dummynode;
    Node*new_down=dummynode;

    for(int i: storage){
        insertatdown(new_down,i);
    }
    return new_head->down;

}

Node* mergelist(Node* head1 , Node*head2){
    // create a dummy node
    Node* dummy_node= new Node(-1);
    Node*head= dummy_node;
    Node*tail=dummy_node;
    Node*t1 = head1;
    Node*t2=head2;

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

Node* flatten_downwards_2(Node*head){
    if (head->next == NULL){
        return head;
    }

    head->next = flatten_downwards_2(head->next);

    // merge it with head
    return mergelist(head,head->next);

    
}



int main(){
        Node* newnode= new Node(6);
        Node* tail = newnode;
        Node* head = newnode;
        Node* niche1 =newnode;

        insertattail(tail,3);
        Node* niche2 = tail;
        insertatdown(niche2,5);
        insertatdown(niche2,10);

        insertattail(tail,8);
        Node* niche3 = tail;
        insertatdown(niche3,9);
        insertatdown(niche3,10);

        insertattail(tail,11);
        Node*niche4 = tail;
        insertatdown(niche4,12);

        // print to checkout

        print(head);
        print_down(head);
        print_down(head->next);
        print_down(head->next->next);
        print_down(head->next->next->next);

        cout<<"after flatten linked list top to the down will be"<<endl;
        Node* new_head=flatten_downwards_1(head);
        print_down(new_head);

        cout<<"with another approach which is more efficient"<<endl;
        new_head= flatten_downwards_2(head);
        print_down(new_head);


}