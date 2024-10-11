#include<iostream>
#include<vector>
using namespace std;



void experiment(){
    int data= 5;
    while(data != -1){
        cout<<"we are inside the loop"<<endl;
        cin>>data;
    }
    cout<<"we are outside the loop"<<endl;
}
int main(){
    experiment();
}