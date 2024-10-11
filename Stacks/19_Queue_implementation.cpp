#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int Size;
    int cnt =0;
    int front = 0;
    int rear = 0;
    Queue(int Size){
        this-> Size = Size;
        arr = new int[this->Size];
    }

    // push in the queues called enqueue
    void push(int element){
        // check it is full or not.
        if (cnt == Size){
            cout<<"queue is full "<<endl;
            return;
        }
        arr[rear%Size] = element;
        rear++;
        cnt++;
    }

    // pop the element from the front.
    void pop(){
        if (cnt == 0){
            cout<<"it is empty"<<endl;
            return;
        }
        arr[front%Size] = -1;  // value replaced by dummy value.
        front++;
        cnt--;
    }

    int top(){
        if(cnt==0){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];

    }

    bool isempty(){
        if (cnt == 0){
            return true;
        }
        return false;
    }

    void overview(){
        cout<<"element in the queue are "<<endl;
        for(int i = front ; i<=rear;i++){
            cout<<arr[i%Size]<<" ";

        }
        cout<<endl;

        cout<<"front is "<<arr[front]<<endl;
    }

};
int main(){
    Queue obj(5);
    if (obj.isempty()){
        cout<<"yes at this time it is empty "<<endl;
    }
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    cout<<"at the front element is "<< obj.top()<<endl;

    obj.push(50);
    obj.push(60); // here queue will be full.

    obj.pop();
    obj.pop();
    obj.pop();

    cout<<"at the front element is "<<obj.top()<<endl;
    obj.push(100);
    obj.push(200);
    obj.push(300);

    obj.overview();

}