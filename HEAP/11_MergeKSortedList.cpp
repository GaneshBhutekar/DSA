#include<iostream>
#include<queue>
#include<vector>
// create the linked list 
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = nullptr;

    }

    // bool operator>(const ListNode* &other) const {
    //     return this->val > other->val;
    // }
    /*

    Here we cannot use this method because this comparator using we are using ListNode* which is raw pointer and this class 
    is normal pointer thst's why
    */
};


class compareNode{
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
//create the linked list
void createList(ListNode* &tail,ListNode* &head,int val){
    ListNode* newval = new ListNode(val);
    if (tail == nullptr){
        tail = newval;
        head = newval;
        return;
    }

    tail->next = newval;
    tail = newval;
    return;
}

void creating(ListNode* &head,ListNode* &tail){
    // std::cout<<"enter the val"<<std::endl;
    int val;
    std::cin>>val;
    while(val != -1){
        createList(tail,head,val);
        // std::cout<<"enter the val"<<std::endl;
        std::cin>>val;        
    }

}

void printList(ListNode* head){
    while(head != nullptr){
        std::cout<<head->val<<" ";
        head = head->next;
    }
    std::cout<<std::endl;
}


ListNode* mergeKList(std::vector<ListNode*>&lists){
    std::priority_queue<ListNode*,std::vector<ListNode*>,compareNode> pq;
    // starting head 
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;
    // now add the first elements in the heap
    int n = lists.size();
    if (n == 0){
        return nullptr;
    }
    std::cout<<"starting elements "<<std::endl;
    for(int i = 0;i<n;i++){
        if (lists[i]!=nullptr){
        pq.push(lists[i]);
        }
    }
    while(!pq.empty()){
        ListNode* demo = pq.top();
        // and i will push his next to the pq
        tail->next = demo;
        tail = tail->next;
        pq.pop();
        if (demo->next != nullptr){
            // if it is not null then you have to push it into the pq
            pq.push(demo->next);
        }

    }
    return head ->next;

}
int main(){
    std::cout<<"total list you want to create : "<<std::endl;
    int n;
    std::cin>>n;
    std::vector<ListNode*> lists;
    for(int i = 0;i<n;i++){
        std::cout<<"create the linked list: "<<std::endl;
        ListNode* head = nullptr;
        ListNode* tail  =nullptr;
        creating(head,tail);
        lists.push_back(head);
    }
    ListNode* ans = mergeKList(lists);
    printList(ans);

}