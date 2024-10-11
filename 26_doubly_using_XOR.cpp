#include<iostream>
#include<vector>
using namespace std;


class Node{
    public:
    int data;
    Node* npx;
    Node(int data){
        this -> data = data;
        npx=NULL;
    }
}; 

Node* XOR(Node* prev,Node* forw)
{
    return (Node*)((uintptr_t)prev ^ (uintptr_t)forw);
}

Node* insert(Node* head,int data){

    Node* temp = new Node(data);
    if (head == NULL){
        head = temp;
        head->npx = XOR(NULL,NULL);
        return head;
    }

    Node* prev = NULL;
    Node* demo = head;
    Node* x;
    while(true){
        x = XOR(prev,demo->npx);    
        if (x == NULL){
            break;
        }

        prev = demo;
        demo = x;
    }

    // we have prev which is prev node and demo has last node
    demo->npx = XOR(prev,temp);
    temp->npx = XOR(demo,NULL);

    return head;
}

vector<int> getList(Node* head){
    if (head == NULL){
        return {};
    }
    // you have to traveerse
    vector<int> ans;
    Node* prev = NULL;
    Node* x;
    Node* demo = head;
    while(true){
        x = XOR(prev,demo->npx);
        ans.push_back(demo->data);
        if (x == NULL){
            break;
        }

        prev = demo;
        demo = x;
        
        
    }

    return ans;
}
int main(){

    Node* head = NULL;
    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,30);
    head = insert(head,40);
    head = insert(head,50);
    vector<int> ans = getList(head);
    for(int i : ans){
        cout<<i<<" ";
    }

}