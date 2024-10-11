#include<iostream>
using namespace std;

// doubly queue......
class doubly_queue{
    public:
    int size;
    int * arr;
    int front;
    int rear;
    doubly_queue(int size){
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;      

    }
    // push from the front ....
    void push_front(int element){

        // check that queue is full or not.
        // same as before.
        if ((front == 0 && rear == size -1) || (front != 0 && rear == (front -1)%(size -1))){
            cout<<"queue is full "<<endl;
            return;
        }

        // for the first element
        else if(front == -1){
            front=0;
            rear = 0;
        }
        // ensure cycle features
        else if(front == 0){
            front = size -1;
        }

        // normal one
        else{
            front--;
        }

        arr[front] = element;
    }

    // push from the end.
    void push_rear(int element){

        if ((front == 0 && rear == size -1) || (front != 0 &&  rear == (front - 1)%(size -1))){
            cout<<"queue is full "<<endl;
            return;
        }
        // if there is only one element to add
        else if (front == -1){
            front = 0;
            rear = 0;
        }

        // ensure cyclic nature
        else if(front != 0 && rear == size -1){
            rear = 0;
        }

        // normal one
        else{
            rear++;
        }
        arr[rear] = element;
    }

    // pop from the front.

    void pop_front(){
        
        // check the queue is empty
        if(front == -1){
            cout<<"queue is empty "<<endl;
            return;
        }

        // if there is only one element.
        else if(front == rear){
            arr[front] =-1;
            front =-1;
            rear = -1;
        }

        // ensure the cycle of the queue.

        else if (front == size -1){
            arr[front] = -1;
            front = 0;

        }

        // normal one

        else{
            arr[front] = -1;
            front++;
        }
    }

    // pop from back.
    void pop_back(){
        // check that queue is empty or not.
        if (front == -1){
            cout<<"queue is empty "<<endl;
            return;
        }
        // if there is only one element.
        else if (front == rear){
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }

        // ensure the circular habit.
        else if(rear == 0){
            arr[rear] = -1;
            rear = size-1;
        }

        // normal one
        else{
            arr[rear] = -1;
            rear--;
        }
    }

    bool isempty(){
        if (front == -1){
            return true;
        }
        return false;
    }

    bool isfull(){
        if((front == 0 && rear == size -1) || (front != 0 && rear == (front -1)%(size -1))){
            return true;
        }
        return false;
    }

    int front_element(){
        if (front == -1){
            cout<<"it is empty "<<endl;
            return -1;
        }

        return arr[front];
    }

    int back(){
        if (front == -1){
            cout<<"it is empty "<<endl;
            return -1;
        }
        return arr[rear];
    }

};

int main(){
    doubly_queue deque(5);

    if (deque.isempty()){
        cout<<"yeah it is empty"<<endl;
    }
    else{
        cout<<"nope it is not empty"<<endl;
    }

    deque.push_front(10);
    deque.push_rear(20);
    deque.push_front(30);

    cout<<"at the front "<<deque.front_element()<<endl;
    cout<< "at the end "<<deque.back()<<endl;

    deque.push_rear(40);
    deque.push_front(-10);

    cout<<"at the first "<<deque.front_element()<<endl;
    cout<<"at the end "<< deque.back()<<endl;

    deque.pop_back();
    cout<<"at the end "<< deque.back()<<endl;

    deque.pop_front();
    cout<<"at the front "<< deque.front_element()<<endl;

    deque.push_front(100);
    deque.push_front(1000);

    if (deque.isfull()){
        cout<<"yes  it is full now"<<endl;
    }
    else{
        cout<<"no it is not full right now"<<endl;
    }

}