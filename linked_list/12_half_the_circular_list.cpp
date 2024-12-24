
// split the linked list into half ...

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }
    ~Node(){
        cout<<"destruct the duplicate node"<<endl;
    }

};

void insertelement(ListNode*&tail,int position,int data){
    if (tail==NULL){
        ListNode*newnode= new Node(data);
        newnode->next=newnode;
        tail=newnode;
        return;
    }
    ListNode*temp=tail;
    while(temp->data!=position){
        temp=temp->next;
    }
    ListNode*newnode =  new Node(data);
    newnode->next=temp->next;
    temp->next=newnode;

}
void print(ListNode*tail){
    ListNode*temp=tail;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp  != tail);
    cout<<endl;
}

int findlength(ListNode*tail){
    ListNode*temp=tail;
    int count=0;
    do{
        count++;
        temp=temp->next;
    }while(temp != tail);
    return count;

}
vector<ListNode*> half_the_list(ListNode*tail){
    if (tail== NULL){
            cout<<"empty list is not alloweed"<<endl;
            return {tail,tail};
    }
    
    ListNode*head1=NULL;
    ListNode*tail1=NULL;
    //length of the list
    int count=findlength(tail);
    if (count == 1){
        return {tail,tail};
    }
    ListNode*temp=tail;
    int cnt=1;
    do{

        if (cnt==count/2){
            tail1=temp;
            head1=temp->next;

        }
        temp=temp->next;
        cnt++;
    }while(temp ->next!= tail);

    tail1->next = tail;
    temp->next=head1;
    vector<ListNode*> ans= {tail,head1};
    cout<<"tail1 is "<<tail1->data<<endl;
    cout<<"temp is "<< temp->data<<endl;

    return ans;
    

}


int main(){
    ListNode*tail=NULL;
    insertelement(tail,5,10);
    insertelement(tail,10,15);
    insertelement(tail,15,20);
    insertelement(tail,20,25);
    insertelement(tail,25,30);
    insertelement(tail,30,35);
    insertelement(tail,35,40);
    print(tail);
    // cout<<findlength(tail)<<endl;
    vector<ListNode*> heads=half_the_list(tail);

    cout<<"first half of the linked list"<<endl;
    print(heads[0]);
    cout<<"second half of the linked list"<<endl;
    print(heads[1]);
    



}