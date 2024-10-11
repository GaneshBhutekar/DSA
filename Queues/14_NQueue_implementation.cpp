#include<iostream>
#include<vector>
using namespace std;


void print_array(int* arr,int size){
    for(int i =0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
class Nqueue{
    public:
    int size;
    int *arr;
    int *rear;
    int *front;
    int *next;
    int index;
    int free;
    Nqueue(int size,int k){
        this ->size = size;
        // size of aray
        arr= new int[size];
        next = new int[size];
        // number of queues are k
        rear = new int[k];
        front = new int[k];
        index = 0;
        free = 0;

        // now fill the next free  element in next array.
        for(int i =0;i<size;i++){
            next[i] = i+1;
        }
        next[size -1 ] = -1;

        // also put every rear and front to -1.
        for(int i=0;i<k;i++){
            rear[i] = -1;
            front[i] = -1;
        }

        
    }

    // now push the element.
    void push(int element,int q){

        // check that arr is overloaded or not
        if (free == -1){
            cout<<"queue is overloaded "<<endl;
            return;
        }
        index = free;
        free = next[index];

        // check it is first element or not.
        if (front[q] == -1){
            front[q] = index;

        }
        else{
            // here it is not the first element to push
            next[rear[q]] = index; // here previous rear will point this new element.
        }

        // change the rear 
        rear[q] = index;
        next[index] = -1; // so that it is not free and not pointing to anyone.
        arr[index] = element; // insert the data here.
    }

    void pop(int q){
        if(front[q] == -1){
            cout<<"queue is empty "<<endl;
            return;
        }
        
        // point the index to the front.
        index = front[q];

        front[q] = next[index];
        // point the next[index] to free so that it is free.
        next[index] = free;
        // now the poped blocked is free one.
        free = index;
    }

    bool isempty(int q){
        // check that that queue is empty or not
        if(front[q] == -1){
            return true;
        }
        return false;
    }

    int first(int q){
        if(front[q] == -1){
            cout<<"it is empty "<<endl;
            return -1;
        }
        else{
            return arr[front[q]];
        }
    }

    int back(int q){
        if(front[q] == -1){
            cout<<"it is empty "<<endl;
            return -1;
        }
        else{
            return arr[rear[q]];
        }
    }

    void status(){
        print_array(arr,this->size);
    }

};

int main(){
    // NQueues
    Nqueue q(6,3);
    q.push(10,0);
    q.push(100,1);
    cout<<"front element for queue 0 is "<<q.first(0)<<endl;
    cout<<"front element for queue 1 is "<<q.first(1)<<endl;
    q.push(20,0);
    cout<<"back of the queue 0 " <<q.back(0)<<endl;
    if(q.isempty(2)){
        cout<<"yes it is empty "<<endl;

    }
    else{
        cout<<"no it is not empty " <<endl;
    }

    q.pop(0);
    cout<<"front element right now for 0 is "<<q.first(0)<<endl;
    q.first(2);
    q.push(1000,2);
    cout<<"status of the array"<<endl;
    q.status();

}