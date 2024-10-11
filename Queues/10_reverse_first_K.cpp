#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reversefirst(queue<int> &Q,int k){
    stack<int> st;
    // add in stack and pop from queue.
    for(int i=0;i<k;i++){
        st.push(Q.front());
        Q.pop();
    }

    // add again in queue
    while(!st.empty()){
        Q.push(st.top());
        st.pop();
    }

    // shift remaining element of queue to last again.....
    // no. of iteration.
    int iteration = Q.size() - k;
    while(iteration){
        int value = Q.front();
        Q.pop();
        Q.push(value);
        iteration--;
    }


}
int main(){
    queue<int> Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    int k;
    cout<<"enter the value of k"<<endl;
    cin>>k;

    reversefirst(Q,k);

    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
    cout<<endl;

}
