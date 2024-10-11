#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &var,int count,int stack_size){
    if(count==stack_size/2){
        cout<<"deleting the value "<<var.top()<<endl;
        var.pop();
        return; 
    }

    int value = var.top();
    var.pop();
    solve(var,count+1,stack_size);
    var.push(value);
}

void middle_delete(stack<int> &var){
    int stack_size=var.size();
    int count=0;
    cout<<"here size is "<<var.size()<<endl;
    solve(var,count,stack_size);
    cout<<"now size is "<<var.size()<<endl;

}
int main(){
    stack<int> var;
    var.push(10);
    var.push(20);
    var.push(30);
    var.push(40);
    var.push(50);
    // var.push(60);

    middle_delete(var);

    // here remove  the middle element which is 3.

    
}