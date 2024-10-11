#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

/// do this only whene stack is allowed in question of not then you can evem use the queue.
void printqueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }    
    cout<<endl;

}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void interleaveVector(queue<int> &Q,int size){
    // process it thatstring element should be at stack start from 11 
    // and half of the element should be in queue then only we can do interleave.
    //dequeue half of the element in stack 
    stack<int> st;
    int half = size / 2;
    cout<<"half is "<<half <<endl;
    for(int i =0;i<half;i++){
        st.push(Q.front());
        Q.pop();
    }
    cout<<"queue "<<endl;
    printqueue(Q);
    cout<<"stack "<<endl;
    printStack(st);
    // now in stack = 15T 14 13 12 11 
    // in  Queue = 16 17 18 19 20
    // push it again to queue
    while(!st.empty()){
        Q.push(st.top());
        st.pop();
    }
    cout<<"only queue "<<endl;
    printqueue(Q);
    // now queue is = 16 17 18 19 20 15 14 13 12 11.
    // now shift first half again to the last 
    int remaining_size = size - half;
    for(int i =0;i<remaining_size;i++){
        Q.push(Q.front());
        Q.pop();
    }
    cout<<"after shifting queue is "<<endl;
    printqueue(Q);
    // now queue is = 15 14 13 12 11 16 17 18 19 20
    // now push half to stack
    for(int i=0;i<half;i++){
        st.push(Q.front());
        Q.pop();
    }
    cout<<"now at last queue is "<<endl;
    printqueue(Q);
    cout<< " now stack at last is "<<endl;
    printStack(st);
    // now stack is 11T 12 13 14 15
    // in queue 16 17 18 19 20 
    // interleave it.
    while(!st.empty()){
        Q.push(st.top());
        st.pop();
        Q.push(Q.front());
        Q.pop();
    }
    if (size&1){
        // it is odd
        Q.push(Q.front());
        Q.pop();
    }
    // now it is ready 
}
int main(){
    vector<int> arr = {100,200,300,400,500,600,700,800,900,1000};
    queue<int> Q;
    int mysize = arr.size();
    for(int i =0; i<mysize;i++){
        Q.push(arr[i]);
    }
    // interleave them ....

    interleaveVector(Q,mysize);

    cout<<"interleaved queue is "<<endl;
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
}