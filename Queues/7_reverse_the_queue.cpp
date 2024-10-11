#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// optimized approach ................
void reverse(queue<int> &Q){
    // size of the queue.
    int mysize = Q.size();
    stack<int> st;
    while(!Q.empty()){
        st.push(Q.front());
        Q.pop();
    }



    // now again store them in queue.

    while(!st.empty()){
        Q.push(st.top());
        st.pop();
    }

    cout<<"reversing done "<<endl;

}


// recurssive approach.........
void recurrsive_way(queue<int> &Q){
    if(Q.empty()){
        return;
    }

    int value = Q.front();
    Q.pop();
    recurrsive_way(Q);
    Q.push(value);


}



int main(){
    // using the STL .........
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);

    reverse(Q);
    recurrsive_way(Q);
    while(!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();

    }

    cout<<endl;



    
}