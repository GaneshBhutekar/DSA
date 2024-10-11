#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> container;
    // push the element
    container.push(10);
    container.push(20);
    //pop the last added element
    container.pop();
    //see top element right now.
    cout<<"top element right now"<<endl;
    cout<<container.top()<<endl;

    // check stack is empty right now
    if (container.empty()){
        cout<<"stack is empty "<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    container.push(20);
    cout<<container.size()<<endl;
}