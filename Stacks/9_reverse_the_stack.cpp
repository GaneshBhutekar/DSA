#include<iostream>
#include<stack>
using namespace std;

void addToBottom(stack<int> &var,int value){
    if(var.empty()){
        var.push(value);
        return;
    }

    int value1=var.top();
    var.pop();
    addToBottom(var,value);

    var.push(value1);
}

void ReverseTheStack(stack<int> &var){
    if(var.empty()){
        return;
    }

    int value = var.top();
    var.pop();
    ReverseTheStack(var);
    addToBottom(var,value);
    

}


int main(){
    stack<int> var;
    var.push(50);
    var.push(40);
    var.push(20);
    var.push(30);
    var.push(10);
    ReverseTheStack(var);

    while(!var.empty()){
        cout<<var.top()<<" ";
        var.pop();
    }
    cout<<endl;
}