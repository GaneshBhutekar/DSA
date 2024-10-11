#include<iostream>
#include<stack>
using namespace std;


void put_at_right(stack<int> &var,int value){

    // this function is use to put the value at right position, means put above the smaller value than him.
    if (var.empty() || var.top()<=value){
        var.push(value);
        return;
    }

    int value1=var.top();
    var.pop();
    put_at_right(var,value);
    var.push(value1);
}

void sort_stack(stack<int> &var){
    if (var.empty()){
        return;
    }

    int value = var.top();
    var.pop();
    sort_stack(var);
    put_at_right(var,value);
    
}
int main(){
    stack<int> var;
    var.push(5);
    var.push(-2);
    var.push(9);
    var.push(-7);
    var.push(3);


    sort_stack(var);

    while(!var.empty()){
        cout<<var.top()<<" ";
        var.pop();
    }
    cout<<endl;
}