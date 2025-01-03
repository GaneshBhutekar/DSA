#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    ListNode* next ;
    Node(int data){
        this-> data = data;
        this -> next = NULL;
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
void print(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

ListNode* findMid(ListNode* head){
    ListNode* fast = head->next;
    ListNode* slow=head;
    while(fast != NULL && fast->next != NULL){
        fast = fast ->next ->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* Sortit(ListNode* left , ListNode* right){
    if (left == NULL){
        return right;
    }
    if (right == NULL){
        return left;
    }
    // create new node to sort the two left and right by dummmy node
    ListNode* ans=new Node(-1);
    ListNode* temp = ans;

    while(left != NULL && right != NULL){
        if (left ->data <= right ->data ){
            // not creating the node we just get it from the 
            temp->next= left;
            temp= left;
            left = left -> next ;
        }
        else{
            temp ->next = right;
            temp = right;
            right =right->next;

        }
    }
    // if nodes left in left;
    while(left!=NULL){
        temp->next = left;
        temp=left;
        left = left -> next;

    }
    while(right != NULL){
        temp ->next = right;
        temp=right;
        right= right ->next;
    }

    return ans->next ;
}

ListNode* mergeSort(ListNode* head){
    // check that head is null or only one node.
    if (head == NULL || head->next == NULL){
        return head;
    }

    // find the mid to split the list.
    ListNode*mid = findMid(head);
    //split the linked list from the 
    ListNode*left = head;
    ListNode* right = mid->next;
    // split it 
    mid->next = NULL;

    // sort the left and right linked list.
    left = mergeSort(left);
    right = mergeSort(right);
    
    // sort the left and right
    ListNode*result = Sortit(left , right);
    return result;


}

int main(){
    ListNode* node = new Node(6);
    ListNode* head=node;
    ListNode* tail= node;
    insertattail(tail,3);
    insertattail(tail,1);
    insertattail(tail,9);
    insertattail(tail,15);
    insertattail(tail,11);
    print(head);

    cout<<"sorting the linked list"<<endl;
    ListNode*new_head= mergeSort(head);
    print(new_head);
}