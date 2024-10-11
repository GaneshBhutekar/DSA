#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// find the next smaller 

vector<int> next_smaller(vector<int> arr){
    vector<int> nextsmall;
    stack<int> bucket;
    bucket.push(-1);
    int mysize = arr.size();
    for(int i = mysize-1; i>=0;i--){
        while(bucket.top()>=arr[i]){
            bucket.pop();
        }
        nextsmall.push_back(bucket.top());
        bucket.push(arr[i]);


    }
    
    // reesre the next small

    int start=0;
    int end = mysize-1;
    while(start <= end){
        swap(nextsmall[start],nextsmall[end]);
        start++;
        end--;
    }
    return nextsmall;

}

int main(){
    vector<int> arr={2,1,4,3};
    vector<int> arr1={2,5,3,2,1,5,3};
    vector<int> nextsmall=next_smaller(arr1);
    for(int i : nextsmall){
        cout<<i<<" ";

    }
    cout<<endl;
}