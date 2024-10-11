#include<iostream>
using namespace std;

// cyclist queue
class queue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    queue(int size){
        this->size = size;
        arr= new int[this->size];
        front =-1;
        rear=-1;
    }

    // push the element in queue.
    void push(int element){
        // if queue is full
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size -1))){
            cout<<"queue is full enough "<<endl;
            return;
        }
        // if this is a first element
        else if (front==-1){
            front=0;
            rear=0;
            arr[rear]= element;
        }

        else if (front != 0 && rear == size -1){
            rear =0;
            arr[rear] = element;
        }

        else{
            rear++;
            arr[rear] = element;
        }
    }

    // pop the element here.
    void pop(){
        if (front == -1){
            cout<<"queue is empty "<<endl;
            return;
        }

        // if there is only one element
        else if (front == rear){
            arr[front] = -1;
            front=-1;
            rear=-1;
        }

        // if the front is at last block of the array 
        else if(front == size -1){
            arr[front]= -1;
            front=0;
        }

        // normal case
        else{
            arr[front] = -1;
            front++;
        }
    }

    // check for empty
    bool isempty(){
        if (front == -1){
            return true;
        }
        return false;
    }

    // return front.
    int front_element(){
        if(front == -1){
            cout<<"queue is empty "<<endl;
            return -1;
        }
        return arr[front];
    }

};
int main(){
    queue q(5);
    if (q.isempty()){
        cout<<"yes it is empty"<<endl;
    }
    else {
        cout<<"no it is not empty"<<endl;
    }
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"top of the element is "<<q.front_element()<<endl;
    q.push(40);
    q.push(50);
    q.push(60); // queue is full enough here.

    q.pop();
    cout<<"now the first element is "<<q.front_element()<<endl;
    q.pop();
    q.pop();
    q.pop();
    cout<<"now the first element is "<<q.front_element()<<endl;

}