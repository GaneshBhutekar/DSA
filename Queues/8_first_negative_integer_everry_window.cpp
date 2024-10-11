#include<iostream>
#include<queue>
#include<vector>
using namespace std;



int first_negative(queue<int> Q,int k){
    int i=0;
    int element = 0;
    while(i<k){
        if(Q.front() < 0){
            element = Q.front();
            break;
        }
        Q.pop();
        i++;

    }
    return element;
}

vector<int> windows(queue<int> Q, int k){
    vector<int> negatives;
    if (Q.size()<k){
        return negatives;
    }
    while(!Q.empty() && Q.size() >=k){
        int ans = first_negative(Q,k);
        negatives.push_back(ans);
        Q.pop();
    }

    return negatives;
}


// if the values is given is in array..... // bet approach ........
vector<int> windows_function (vector<int> arr , int size,int k){
    deque<int> dq;
    vector<int> answer;
    
    //  put first window ...
    for(int i=0;i<k;i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    // check that first one is negative or not is not then add 0.
    if (dq.empty()){
        answer.push_back(0);
    }
    else{
        answer.push_back(arr[dq.front()]);
    }

    // now add next negative remove previouse one

    int i= k;
    while(i!=size){

        // check that the inside front element is removable
        if (!dq.empty() && i-k == dq.front()){
            dq.pop_front();
        }

        // chck it is negative or not
        if (arr[i] < 0){
            dq.push_back(i);
        }

        // if it not empty then add it tp the answer.
        if (!dq.empty()){
            answer.push_back(arr[dq.front()]);
        }
        // if it is empty then add 0.   
        else{
            answer.push_back(0);
        }
        i++;


    }

    return answer;
}

int main(){
    queue<int> Q;
    Q.push(-8);
    Q.push(2);
    Q.push(3);
    Q.push(-6);
    Q.push(10);
    int k;
    cout<<"enter the k value "<<endl;
    cin>>k;

    vector<int> ans = windows(Q,k);

    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;


    vector<int> arr = {-8,2,3,-6,10};
    int mysize = arr.size();

    cout<<"next approach "<<endl;

    vector<int> answer = windows_function(arr,mysize,k);
    for(int i:answer){
        cout<<i<<" ";
    }
    cout<<endl;
}
