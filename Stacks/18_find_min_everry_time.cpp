#include<iostream>
#include<vector>
using namespace std;


// APPROACH 1

class Stack {
    public:
    int size;
    int *arr;
    int index = -1;
    int min = INT_MAX;
    vector<int> min_values ; // you can use stack rather than array and vector for this.


    Stack(int size){
        this ->size = size;
        arr = new int[this->size];
    }

    void push(int element){
        if (index >= size-1){
            cout<<"stack is overflow "<<endl;
            return;
        }
        if (min > element){
            min = element;
        }
        min_values.push_back(min);
        index ++;
        arr[index] = element;
        
    }

    void pop(){
        if (index == -1){
            cout<<"stack is under flow "<<endl;
            return;
        }
        
        min_values.pop_back();
        index--;


    }

    int peek(){
        return arr[index];
    }

    bool isempty(){
        if (index == -1){
            return true;
        }
        return false;
    }

    int min_value(){
        if (index == -1){
            cout<<"stack is underflow"<<endl;
            return -1;
        }

        return min_values[index];
    }




};



class Stack2{
    public:
    int size;
    int top;
    int *arr;
    int min=INT_MAX;
    Stack2(int size){
        this ->size = size;
        arr = new int[this->size];
        top = -1;
    }

    void push(int element){
        if (top >= size -1 ){
            cout<<"stack is overflow"<<endl;
            return;
        }
        if (top == -1){
            top++;
            arr[top] = element;
            min = arr[top];
        }
        else {
            if (min < element){
                top++;
                arr[top] = element;
            }
            else{
                int value = 2*element - min ;// encrypted value to store in stack
                top++;
                arr[top] = value;
                min = element;
            }
        }

    }

    void pop(){
        if (top == -1){
            cout<<"stack is empty "<<endl;
            return;
        }

        if (arr[top] > min){
            top-- ;
        }
        else{
            int value = 2*min - (arr[top]); // decrypt the value to get previous value.
            min = value;
            top--;
        }
    }

    int attop(){
        if (top == -1){
            cout<<"stack is under flow"<<endl;
            return -1;
        }
        if(arr[top] > min){
            return arr[top];
        }
        else{
            return min;
        }
    }

    bool isempty(){
        if(top == -1 ){
            return true;
        }
        return false;
    }

    int min_value(){
        if (top == -1){
            cout<<"stack is empty "<<endl;
            return -1;
        }
        return min;
    }
};

int main(){

    // FOR Approach one.

    // Stack stack(5);
    // stack.push(5);
    // stack.push(3);
    // stack.push(2);
    // stack.push(6);

    // if (stack.isempty()){
    //     cout<<"stack is empty"<<endl;
    // }
    // else{

    //     cout<<"stack is not empty"<<endl;
    // }

    // stack.push(1);
    // cout<<"minimum value at this point is "<< stack.min_value()<<endl;
    // stack.pop();
    // cout<<"minimum value at this point is "<<stack.min_value()<<endl;

    Stack2 stack1(6);

    // is empty working
    if(stack1.isempty()){
        cout<<"yes it is empty "<<endl;
    }
    else{
        cout<<"no it is not empty"<<endl;
    }

    stack1.push(5);
    stack1.push(8);
    stack1.push(4);
    stack1.push(6);
    stack1.push(1);
    stack1.push(7);

    cout<<"min value right now is "<<stack1.min_value()<<endl;

    stack1.pop();
    stack1.pop();
    cout<<"min value right now is "<<stack1.min_value()<<endl;

    cout<<"at the top of the stack is "<<stack1.attop()<<endl;





}   