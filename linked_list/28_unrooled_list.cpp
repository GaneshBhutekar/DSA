#include<iostream>
#include<vector>
using namespace std;


// UNROLL LINKED LIST.
class Node{
    public:
    int noE; // number of elements.
    static const int n = 5;
    static const int thersold = 3;
    int arr[n];
    ListNode* next;
    Node(){
        this -> noE = 0;
        this->next = NULL;
    }
};




void print_ULL(ListNode*head){
    if (head == NULL){
        return;
    }
    
    ListNode* temp = head;
    while(temp!= NULL){
        for(int i =0;i<temp->noE;i++){
            cout<<temp->arr[i]<<" ";
        }
        cout<<endl;
        temp = temp ->next;
    }
}
void insertList(ListNode* &head,int data){
    if (head == NULL){
        // create the Node
        head = new Node();
        // push the element in it.
        head->arr[head->noE] = data;
        head->noE++;
        return;
    }

   
    else{
        ListNode* temp = head;
        int thersold = temp->thersold;
        while(temp->next != NULL){
            temp = temp->next;

        }

        // check whether this node is full or not
        if (temp->noE < thersold){
            temp -> arr[temp->noE] = data;
            temp->noE ++;
        }

        else{
            ListNode* newone = new Node();
            newone-> arr[newone ->noE] = data;
            newone-> noE++;
            temp->next = newone;
        }
    }

}


// finding the element require ascending order so that there will be the benifits of it.

bool find_ULL(ListNode* head,int data){
    if(head == NULL){
        return NULL;

    }
    ListNode* temp = head;
    while(temp != NULL){
        if (temp->arr[temp->noE-1 ] == data){
            return true;
        }
        else if (temp->arr[temp->noE-1] > data){
            // trverse here
            for(int i = 0;i<temp->noE;i++ ){
                if (temp->arr[i] == data){
                    return true;
                }
            }
            return false;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    ListNode* head = NULL;
    cout<<"enter the data "<<endl;
    int data;
    cin>>data;
    while(data != -1){
        insertList(head,data);
        cout<<"enter the data (-1 for leaving this loop)"<<endl;
        cin>> data;
    }       
    print_ULL(head);

    cout<<"enter the element which you want to check is it available or not"<<endl;
    int element;
    cin>>element;
    if (find_ULL(head,element)){
        cout <<"YES IS IT PRESENT THERE"<<endl;
    }
    else{
        cout<<"NO IT IS NOT"<<endl;
    }
    // 1 2 3 4 5 6 7 8 9 10 11 12 -1

}