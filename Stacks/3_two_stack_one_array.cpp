#include<iostream>
using namespace std;
// implement two stack in one array .
class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    stack(int size){
        this->size=size;
        arr= new int[size];
        top1=-1;
        top2=size; 
    }
    void push1(int element){
        if(top1+1 != top2 && top1<size-1){
            top1++;
            arr[top1]=element;
        }
        else{
            cout<<"stack 1 is overloaded"<<endl;
        }
    }

    void push2(int element){
        if(top2-1 != top1 && top2 > 0){
            top2--;
            arr[top2]=element;
        }
        else{
            cout<<"stack 2 is overloaded "<<endl;
        }
    }

    void pop1(){
        if (top1 >=0){
            top1--;
        }
        else{
            cout<<"stack 1 is empty "<<endl;
        }
    }
    void pop2(){
        if (top2 <=size-1){
            top2++;
        }
        else{
            cout<<"stack 2 is empty "<<endl;
        }
    }
    int peek1(){
        if (top1 >=0){
            return arr[top1];
        }
        else{
            cout<<"stack 1 is empty "<<endl;
            return -1;
        }
    }

    int peek2(){
        if (top2< size){
            return arr[top2];
        }
        else{
            cout<<"stack 2 is empty "<<endl;
            return -1;
        }
    }

    bool isempty1(){
        if (top1==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isempty2(){
        if (top2 == size){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    stack var(5);
    var.push1(10);
    var.push1(20);
    var.push2(30);
    var.push2(40);
    var.push1(50);
    cout<<"peak of stack1"<<endl;
    cout<<var.peek1()<<endl;

    cout<<"peak os stack2"<<endl;
    cout<<var.peek2()<<endl;



    var.push2(60); // this will not inserted because arrau is full no space is there

    var.pop1();
    var.push2(80);
    cout<<"Now poeak of the stack 2 is "<<endl;
    cout<<var.peek2()<<endl;

    var.pop1();
    var.pop1();

    var.pop1(); // not possible stack 1 is empty no

    var.pop2();
    var.pop2();
    var.pop2();
    var.pop2();  // not possible because.... stack2 is empty.

}