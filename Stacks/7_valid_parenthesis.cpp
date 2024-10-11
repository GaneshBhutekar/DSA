
// check that it is valid parenthesis.
#include<iostream>
#include<stack>
using namespace std;

bool correct_or_wrong(string paren){
    // make stack here.
    stack<char> var;
    for(int i =0;i<paren.length();i++){
        if (paren[i]== '{' || paren[i]=='(' || paren[i] == '['){
            var.push(paren[i]);

        }
        else{
            // clasion bracket.
            if (!var.empty()){
                if( (paren[i]==']' && var.top()=='[') || (paren[i]=='}' && var.top()=='{') || (paren[i]==')' && var.top()=='(')){
                    var.pop();
                }
                else{
                    return false;
                }
            }
            else{
                // beacause if here top is empty and closin bracket is comming then it is incomplete parenthesis.
                return false;
            }
        }
    }
    if (var.empty()){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    string paren1="{(])}";
    string paren2="({[{}]})";
    // check that abive one is incomplete or complete parenthesis.
    if(correct_or_wrong(paren2)){
        cout<<"it is COMPLETE parenthesis"<<endl;
    }
    else{
        cout<< "It is NOT COMPLETE parenthesis"<<endl;
    }
    
}