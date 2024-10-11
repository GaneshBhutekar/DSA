#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void reversing_each(vector<int> &arr , int size,int i,int end){
    // deque use to reverse it
    deque<int> dq;
    for(int k=i;k<end;k++){
        dq.push_back(arr[k]);
    }

    // again pudh this in array at same position.
    int k=i;
    while(!dq.empty()){
        arr[k] = dq.back();
        cout<<dq.back()<<" ";
        dq.pop_back();
        k++;
    }
    cout<<endl;


}
// reverse the array from every k.
void reverse_k(vector<int> &arr,int size,int k){
    int end=k;
    int i=0;
    while(end<=size){
        reversing_each(arr,size,i,end);
        i=end;
        end+=k;
    }

    if(end>size){
    reversing_each(arr,size,i,size);
    }


}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int mysize = arr.size();
    int k ;
    cout<<"enter the k"<<endl;
    cin>>k;

    reverse_k(arr,mysize,k);

    cout<<"reversed by k array is "<<endl;
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;


}

  