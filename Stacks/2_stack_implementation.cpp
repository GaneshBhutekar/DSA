#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int size){
        this -> size = size;
        arr=new int[size];
        top = -1;
    }

    void push(int element){
        if (top < size-1){
            top ++;
            arr[top] = element;
        }
        else{
            cout<<"stack is overflow"<<endl;
        }
    }
    void pop(){
        // here check that stact is underflow or not.
        if (top >=0){
            top--;
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    int peek(){
        if (top >= 0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }

    bool isempty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }
};
int main(){
    stack var(10);

    var.push(10);
    var.push(20);
    var.push(30);
    var.push(40);

    cout<<"top element "<<var.peek()<<endl;

    var.pop();
    cout<<"top element "<<var.peek()<<endl;
    var.push(40);
    var.push(50);
    var.push(60);
    var.push(70);
    var.push(80);
    var.push(90);
    var.push(100);
    cout<<"top element "<<var.peek()<<endl;
    var.push(110); // here element in the stack is overflow

    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    var.pop();
    if (var.isempty()){
        cout<<"it is empty"<<endl;
    }
    else{
        cout<<"it is not empty"<<endl;
    }

    cout<<"size of the stack "<<var.size<<endl;

}