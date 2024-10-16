#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// create class to add in the inner node
class InnerNode{
    public:
    InnerNode* next;
    int data;
    InnerNode(int data){
        this->data = data;
        next = NULL;
    }

};

class OuterNode{
    public:
    // here we have to make the new linked list of the innerNode type okay and we can access it by the OuterNode object
    InnerNode* head;
    InnerNode* tail;
    OuterNode* next;
    int cnt =0;
    OuterNode(){
        this->head = NULL;
        this -> tail = NULL;
        this->next = NULL;
    }
};



void Inserting(OuterNode* &head,OuterNode* &tail,int limit,int data){
    if (head == NULL){
        // not inserted anything 
        // create first outer node
        head = new OuterNode();
        tail = head;

        // now fill the element inside the inner linked list 
        head->head = new InnerNode(data);
        head->tail = head->head;
        head->head->next = head->head;
        // we filled one node that's why.
        head->cnt++;
        return;
    }

    // if it is not null 
    // check that current tail of outer node is filled or not 
    if (tail->cnt == limit){
        // time tp create new outer node
        OuterNode* newnode = new OuterNode();
        tail->next = newnode;
        tail = newnode;

        // now add first element here
        tail->head = new InnerNode(data);
        tail->tail = tail->head;
        tail->head->next = tail->head;
        tail->cnt ++;
    }
    else{
        // create a new node there
        InnerNode* temp = new InnerNode(data);
        temp->next = tail->tail;
        tail->tail = temp;
        tail->head->next = tail->tail;
        tail->cnt++;
    }

}

void insertIntoList(OuterNode* &head,OuterNode* &tail,int limit){
    cout<<"enter the data "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        Inserting(head,tail,limit,data);
        cout<<"insert the data"<<endl;
        cin>>data;
    }
}



void printList(OuterNode* head,OuterNode* tail){
    
    OuterNode* temp = head;
    while(temp != NULL){
        // traverse inside circular list
        InnerNode* innertemp = temp->tail;
        do{
            cout<<innertemp->data<<" ";
            innertemp = innertemp->next;
        }while(innertemp != temp->tail);
        cout<<endl;
        temp= temp->next;
    }
}

int main(){
    // now you are ready to insert fdata
    cout<<"enter the number of data you want to insert"<<endl;
    int n;
    cin>>n;

    // this limit is the number of node inside each node
    int limit = sqrt(n);
    cout<<"limit is "<<limit<<endl;
    OuterNode *head = NULL;
    OuterNode*tail = NULL;
    insertIntoList(head,tail,limit);
    cout<<"printing the list"<<endl;
    printList(head,tail);




}
