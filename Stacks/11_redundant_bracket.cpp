#include<iostream>
#include<stack>
using namespace std;

bool isredundant(string s){
    stack<char> st;
    for(int i =0;i<s.length();i++){
        char character=s[i];
        if (character == '(' || character == '+' || character == '-' || character == '*' || character =='/'){
            st.push(character);
        }
        else{
            // check here that it is attribute ir closing bracker we donn't need attribute.
            if (character == ')'){
                bool status = true;
                while(st.top() != '('){
                char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/'){
                        status=false;

                    }
                    st.pop();
                }
                if (status == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string expression = "(a+(a+b))";
    string expression_2 = "((a+b))";
    string expression_3 = "()(a+b)";
    if (isredundant(expression_3)){
        cout<<"it is redundant expression uneccessary brackets"<<endl;
    }
    else{
        cout<<" no it is not redundant "<<endl;
    }
}