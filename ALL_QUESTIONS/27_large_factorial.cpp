#include<iostream>
#include<vector>
using namespace std;


void multiply(vector<int> &ans,int value){
    int carry = 0;
    for(int i =0;i<ans.size();i++){
        int solve = ans[i]*value + carry;
        ans[i] = solve%10;
        carry = solve/10;
    }

    // add the remaining carru
    while(carry){
        ans.push_back(carry%10);
        carry /=10;
    }
}

void reverseArray(vector<int> &arr){
    int start =0;
    int end = arr.size()-1;

    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

vector<int> factorial(int N){
    // returning ans
    vector<int> ans(1,1);

    for(int i=2;i<=N;i++){
        multiply(ans,i);
    }

    reverseArray(ans);
    return ans;
}
int main(){
    int N = 10;
    vector<int> ans = factorial(N);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;

}