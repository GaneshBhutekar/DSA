#include<iostream>
#include<stack>

using namespace std;

int valid_string(string braces){
    int brace_length=braces.length();
    if(brace_length&1){
        return -1;
    }
    stack<int> st;
    int count=0;
    for(int i=0;i<brace_length;i++){
        char br=braces[i];
        if (br == '{'){
            st.push(br);
        }
        else{
            if (!st.empty()){
                st.pop();
            }
            else{
                count++;
            }
        }
    }
    // conditions
    int stack_size=st.size();

    int open=0;
    int close=0;
    if (stack_size&1 && count&1){
        open = stack_size/2;
        close = count/2;
        return open + close + 2;
    }
    else{
        return (count/2) + (stack_size/2);
    }
}
int main(){
    string braces = "{}}{";
    string braces1 = "}}{}}}";
    string braces2 = "{}{}";
    string braces3 = "";
    string braces4="}}}}}{";
    int ans = valid_string(braces4);
    cout<<"total rotations or fixing required is "<<ans<<endl;

}
