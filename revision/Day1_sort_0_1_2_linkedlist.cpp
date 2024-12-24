ListNode* approached_two(ListNode*head){
    ListNode*zeros=new Node(0);
    ListNode*head_zeros=zeros;
    ListNode*tail_zero=zeros ;
    ListNode*ones=new Node(0);
    ListNode*head_ones=ones;
    ListNode*tail_ones=ones;
    ListNode*two = new Node(0);
    ListNode*head_two=two;
    ListNode*tail_twos=two;

    ListNode*temp=head;
    while(temp!=NULL){
        if (temp->data == 0){
            insertatTail(tail_zero,0);
        }
        else if (temp->data == 1){
            insertatTail(tail_ones,1);
        }
        else{
            insertatTail(tail_twos,2);
        }
        temp=temp->next;

    }
    if (head_ones->next == NULL){
        tail_zero->next = head_two->next;
    }
    else{
    tail_zero->next=head_ones->next;
    tail_ones->next=head_two->next;
    }
    ListNode*todelete=head_zeros;
    head_zeros=head_zeros->next;
    todelete->next=NULL;
    delete todelete;
    delete head_ones;
    delete head_two;
    return head_zeros;


}