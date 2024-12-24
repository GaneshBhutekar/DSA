// stack implementation using linked list.....
#include<iostream>
using namespace std;

// here we can do push the element thkrough head wayy so that when we pop the element we can easily use next member.

class Node{
    public:
    int data;
    ListNode* next;
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }
    ~Node(){}

};


// implementing stack now
class Stack{
    public:
    ListNode* top=NULL;
    
    void push(int element){
        ListNode* newnode = new Node(element);
        newnode->next = top;
        top = newnode;
    }

    void pop(){
        if (top != NULL){
        ListNode* temp = top;
        top=top->next;
        temp->next=NULL;
        delete temp;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    int peek(){
        if (top != NULL){
            return top->data;
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if (top!=NULL){
            return false;
        }
        else{
            return true;
        }
    }

};
int main(){

    Stack var;
    // var.push(10);
    var.push(20);
    // var.pop();
    cout<<var.peek()<<endl;
    if(var.isempty()){
        cout<<"yes it is empty"<<endl;
    }
    else{
        cout<<"no it is not empty"<<endl;
    }

}
