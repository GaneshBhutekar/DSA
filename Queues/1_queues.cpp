#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> que;
    que.push(12);
    que.push(13);
    que.push(14);

    cout<<"size of the queue is "<<que.size()<<endl;

    cout<<"back of the queue is "<<que.back()<<endl;
    cout<<"front of the queue is "<<que.front()<<endl;
    
    int value = que.pop();
    que.pop();
    que.pop();
    if (que.empty()){
        cout<<"yes it is empty"<<endl;
    }
    else{
        cout<<"it is not empty "<< endl;
    }

}