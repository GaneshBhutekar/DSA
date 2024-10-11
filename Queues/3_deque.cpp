#include<iostream>
using namespace std;
#include<queue>
// Doubly ended queue.
int main(){
    deque<int> d;
    d.push_front(14);
    d.push_back(12);
    cout<<"print front "<<d.front()<<endl;
    cout<<"print back "<<d.back()<<endl;

    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();
    if(d.empty()){
        cout<<"it is empty "<<endl;

    }
    else{
        cout<<"it is not empty "<<endl;
    }
    
}