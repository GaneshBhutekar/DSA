#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<char> demo;
    string name = "Ganesh";
    for(int i =0;i<name.length();i++){
        demo.push(name[i]);
    }
    string reversed_name="";
    // now the last element will be the first.
    while(!demo.empty()){
        char ch= demo.top();
        reversed_name.push_back(ch);
        demo.pop();
    }
    cout<<reversed_name<<endl;

}
