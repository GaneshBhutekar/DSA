// make a clone 

#include<iostream>
#include<unordered_map>
using namespace std;    
class random_Node{
    public:
    int data;
    random_Node* next;
    random_Node* random;
    random_Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> random = NULL;

    }

};
void insertatHead(random_Node* &head,int data){
    random_Node*temp = new random_Node(data);
    temp->next = head;
    head=temp;
}
void insertatTail(random_Node*&head,random_Node* &tail,int data){

    random_Node* temp = new random_Node(data);
    if (tail==NULL){
        tail=temp;
        head=temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void print(random_Node*head){
    random_Node*temp = head;
    while(temp != NULL){
        cout<<temp->data <<" ";
        temp=temp->next;

    }
    cout<<endl;
}

int main(){
    Node* newnode = new Node(10);
    Node

}