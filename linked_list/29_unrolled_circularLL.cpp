#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// create class to add in the inner node
class InnerNode{
    public:
    InnerListNode* next;
    int data;
    InnerNode(int data){
        this->data = data;
        next = NULL;
    }

};

class OuterNode{
    public:
    // here we have to make the new linked list of the innerNode type okay and we can access it by the OuterNode object
    InnerListNode* head;
    InnerListNode* tail;
    OuterListNode* next;
    int cnt =0;
    OuterNode(){
        this->head = NULL;
        this -> tail = NULL;
        this->next = NULL;
    }
};


void printList(OuterListNode* head,OuterListNode* tail){
    
    OuterListNode* temp = head;
    while(temp != NULL){
        // traverse inside circular list
        InnerListNode* innertemp = temp->tail;
        do{
            cout<<innertemp->data<<" ";
            innertemp = innertemp->next;
        }while(innertemp != temp->tail);
        cout<<endl;
        temp= temp->next;
    }
}


void Inserting(OuterListNode* &head,OuterListNode* &tail,int limit,int data){
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
        OuterListNode* newnode = new OuterNode();
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
        InnerListNode* temp = new InnerNode(data);
        temp->next = tail->tail;
        tail->tail = temp;
        tail->head->next = tail->tail;
        tail->cnt++;
    }

}

void insertIntoList(OuterListNode* &head,OuterListNode* &tail,int limit){
    cout<<"enter the data "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        Inserting(head,tail,limit,data);
        cout<<"insert the data"<<endl;
        cin>>data;
    }
}
void insertBetween(OuterListNode* &head,OuterListNode* &tail,int data,int key,int limit){
    
    // find the node in which this data will insertted
    // starting from the head
    OuterListNode* temp = head;
    while(temp->tail->data < key){
        // move till the tail value of innernode is actually larger than key
        temp=temp->next;
    }

    // we have temp now.
    // add the data in it.
    // find the key which will be previous of inserting key.
    InnerListNode* innertemp = temp->tail;
    while(innertemp->data != key){
        innertemp = innertemp->next;
    }

    // we found the key!!!
    // create the innernode
    InnerListNode* newnode = new InnerNode(data);
    newnode->next = innertemp->next;
    innertemp->next = newnode;
    temp->cnt ++;

    // check cnt
    // now traverse 
    // remove the tail node and add to the next one
    if(temp->cnt <= limit){
        return;
    }

    // stiore the node
    InnerListNode* extra = temp->tail;
    int remain = extra->data;
    temp -> tail = temp->tail->next;
    temp->head->next = temp->tail;
    extra->next = NULL;
    delete extra;


    // cout<<"i am here"<<endl;
    // printList(head,tail);
    // 1 2 3 4 6 7 8 9 10 -1
    temp = temp->next;

    // move untill the cnt is full or it is not null.
    while(temp != NULL && temp -> cnt >= limit){
        // add the remain into the head and delete the tail for future
        InnerListNode* node = new InnerNode(remain);
        temp->head->next = node;
        node->next = temp->tail->next;

        InnerListNode* extra = temp->tail;
        remain = temp->tail->data;
        temp->tail = temp->tail->next;
        extra -> next = NULL;
        delete extra;  

        temp = temp->next;
    }
    Inserting(head,tail,limit ,remain);
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
    OuterListNode*tail = NULL;
    insertIntoList(head,tail,limit);
    printList(head,tail);
    cout<<"insert one data here"<<endl;
    int data;
    cin>>data;
    cout<<"after which you want to add it "<<endl;
    int key;
    cin>>key;
    insertBetween(head,tail,data,key,limit);
    cout<<"printing the list"<<endl;
    printList(head,tail);

    // 1 2 3 4 6 7 8 9 10 -1
}
