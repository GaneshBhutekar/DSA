#include<iostream>
using namespace std;
// another approach to implement queue.

class queue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    queue(int size){
        this->size = size;
        arr = new int[this->size];
        front = 0;
        rear = 0;
    }

    // push the element through last.
    void push(int element){
        // check that it is full or not.
        if (rear == size){
            cout<<"it is already full"<<endl;
            return;
        }
        arr[rear] = element;
        rear++;
    }

    void pop(){
        // check that queue is empty or not.
        if (rear == front){
            cout<<"queue is empty "<<endl;
            return;
        }
        else{
            arr[front] = -1;
            front++;
            if (front == rear){
                front = 0;
                rear = 0;
            }
        }
    }

    bool isempty(){
        if (rear == front){
            return true;
        }
        return false;
    }

    int front_element(){
        if(front == rear){
            cout<<"it is empty "<<endl;
        }

        return arr[front];
    }

};
int main(){
    queue q(5);

    if(q.isempty()){
        cout<<"yes it is empty "<<endl;
    }
    else{
        cout<<"no it it not empty "<<endl;
    }
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout<<"front element is "<<q.front_element()<<endl;
    q.push(60); // already full;

    q.pop();
    cout<<"front element is "<<q.front_element()<<endl;
    q.push(10); // this is because it is not cyclic;
    q.pop();
    q.pop();
    q.pop();
    cout<<"front element is "<<q.front_element()<<endl;
    q.push(10);
    q.pop();
    cout<<"after the last element are poped then again front and rear are at the 0 "<<endl;
    q.push(10);
    q.push(20);
    cout<<"now the front is "<< q.front_element()<<endl;

}
