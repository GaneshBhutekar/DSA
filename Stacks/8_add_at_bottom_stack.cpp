// add element in the bottom of the stack.

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &var,int count,int element){
    // base condition.
    if (var.empty()){
        var.push(element);
        return;
    }

    int value=var.top();
    var.pop();
    solve(var,count-1,element);
    var.push(value);

}
void add_to_first(stack<int> &var,int element){
    int count=var.size();

    solve(var,count,element);

}
int main(){
    stack<int> var;
    var.push(10);
    var.push(20);
    var.push(30);
    var.push(40);
    var.push(50);

    // adding 5 at the bottom of the stack
    cout<<"size before adding 5  ="<<var.size()<<endl;
    add_to_first(var,5);
    cout<<"size after adding 5  ="<<var.size()<<endl;
    

    // check that 5 is added or not
    while(!var.empty()){
        cout<<var.top()<<" ";
        var.pop();
    }
    cout<<endl;
}