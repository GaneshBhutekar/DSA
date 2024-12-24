// make a clone 

#include<iostream>
#include<unordered_map>
using namespace std;    
class random_Node{
    public:
    int data;
    random_ListNode* next;
    random_ListNode* random;
    random_Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;

    }

};
void insertatHead(random_ListNode* &head,int data){
    random_ListNode*temp = new random_Node(data);
    temp->next = head;
    head=temp;
}
void insertatTail(random_ListNode*&head,random_ListNode* &tail,int data){

    random_ListNode* temp = new random_Node(data);
    if (tail==NULL){
        tail=temp;
        head=temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(random_ListNode*head){
    random_ListNode*temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp=temp->next;

    }
    cout<<endl;
}


random_ListNode*  clone_list(random_ListNode* head){
    // create the clone node
    random_Node * clonehead=NULL;
    random_Node * clonetail = NULL;

    random_ListNode*temp = head;
    // insert value in clone list.
    // and map it in unrdered map as well.
    unordered_map<random_ListNode*,random_ListNode*> map;
    while(temp!=NULL){
        insertatTail(clonehead,clonetail,temp->data);
        map[temp]=clonetail;
        temp=temp->next;
    }

    // map the random pointer now using map.
    random_ListNode*temp1 = clonehead;
    temp=head;
    while(temp1!=NULL && temp != NULL){
        temp1->random = map[temp->random];
        temp=temp->next;
        temp1=temp1->next;
    }
    return clonehead;
}


random_ListNode* clone_list2(random_ListNode* head){
    // make a clone list;
    if (head == NULL){
        return NULL;
    }

    random_ListNode* temp=head;
    // clone list
    random_ListNode* clonehead=NULL;
    random_ListNode* clonetail = NULL;

    while(temp!=NULL){
        insertatTail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }

    // inter connect the orignal node and clone node.
    random_ListNode* orignal=head;
    random_ListNode* clone=clonehead;
    while(orignal != NULL && clone != NULL){
        // connecting with clone Node
        random_ListNode* next = orignal->next;
        orignal->next = clone;
        orignal = next;
        
        // connecting with orignal
        next = clone->next;
        clone->next = orignal;
        clone=next;
    }
     
    //  add random assign ment.
    temp = head;
    while(temp!= NULL){
        if (temp->next!=NULL){
            if (temp->random != NULL){
                temp->next ->random = temp->random -> next;
            }
            else{
                temp->next ->random = NULL;
            }
        }
        temp=temp->next ->next ;

    }


    // remove the intersection.
    orignal = head;
    clone=clonehead;
    while(orignal != NULL && clone != NULL){
        // remove links from orignal linked list.
        orignal->next = clone->next;
        orignal = orignal ->next;


        // remove links from clone lists.
        if (orignal!= NULL){
        clone->next = orignal->next;
        
        clone=clone->next;
        }

        

    }
    // return clonenode
    return clonehead;

}
int main(){
    // for creating orognal array we will do...
    random_ListNode* orignal=new random_Node(10);
    random_ListNode* head=orignal;
    random_ListNode* tail = orignal;
    insertatTail(head,tail,20);
    insertatTail(head,tail,30);
    insertatTail(head,tail,40);
    print(head);
    head->random = head->next ->next ;
    head->next->random = head->next ->next ->next;
    head->next ->next ->random=head->next ;
    head->next ->next ->next -> random = head;


//   APPROACH 1
//     now we will do clone for this .....
    cout<<"approach 1"<<endl;
    random_ListNode* clone= clone_list(head);
    print(clone); 
    cout<<clone->next->next->next->random->data<<endl;

//  APPROACH 2
    cout<<"approach 2"<<endl;
    random_ListNode* newhead = clone_list2(head);
    print(newhead);
    cout<<newhead->random->data<<endl;
    cout<<newhead->next->next->next->random->data<<endl;



}