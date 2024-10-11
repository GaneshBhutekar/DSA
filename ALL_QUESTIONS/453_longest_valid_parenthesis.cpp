#include<iostream>
#include<vector>
#include<stack>

using namespace std;


bool check_the_substring(string substring,int n){
    // push it into the stack and check that it is valid or not
    if (n&1){
        return false;
    }
    stack<int> st;
    for(int i = 0; i<n;i++){
        if (substring[i] == '('){
            st.push(0);
        }
        else{
            if (st.empty()){
                return false;
            }
            else{
                st.pop();
            }
        }

        
    }
    if (st.empty()){
            return true;
        }
    else{
            return false;
    }

}

int longest_valid_1(string str){
    int n = str.size();
    string demo = "";
    int max=0;
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            demo+=str[j];
            int k = j-i+1;
            if (check_the_substring(demo,k)){
                if (k>max){
                    max = k;
                }
                
            }

        }
        demo ="";
    }
    return max;
}

int max_length(string str){
    // we have to store the index in queue instead of string .
    stack<int> st;
    int max= 0;
    st.push(-1); // if the close bracket arrive initially.

    int n = str.size();
    for(int i = 0;i<n;i++){
        if (str[i] == '('){
            // just push it.
            st.push(i);
        }
        else{
            st.pop();

            if (!st.empty()){
                if (max < i-st.top()){
                    max = i-st.top();
                }
            }

            else{
                st.push(i);
            }

        }
    }
    return max;
}

int main(){
    string str = "(()()))(((())))";
    string str1 = "(((((";
    int ans = max_length(str1);
    cout<<ans<<endl;
}
