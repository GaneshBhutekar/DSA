Node* approached_two(Node*head){
    Node*zeros=new Node(0);
    Node*head_zeros=zeros;
    Node*tail_zero=zeros ;
    Node*ones=new Node(0);
    Node*head_ones=ones;
    Node*tail_ones=ones;
    Node*two = new Node(0);
    Node*head_two=two;
    Node*tail_twos=two;

    Node*temp=head;
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
    Node*todelete=head_zeros;
    head_zeros=head_zeros->next;
    todelete->next=NULL;
    delete todelete;
    delete head_ones;
    delete head_two;
    return head_zeros;


}