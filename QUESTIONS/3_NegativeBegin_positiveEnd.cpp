#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr = {-12,11,1,-3,-6};
    int Size=arr.size();
    int start= 0;
    int mover = Size-1;
    while(start<=mover){
            cout<<"entered here start "<<arr[start]<<endl;
            cout<<"entered here mover "<<arr[mover]<<endl;


        if (arr[start]>0 && arr[mover]<=0 ){
            cout<<"Condition 1"<<endl;
            swap(arr[start],arr[mover]);
            start++;
            mover--;
        }
        else if(arr[start]<=0){
            cout<<"condition 2"<<endl;
            start++;
        }
        else if (arr[mover]>0){
            cout<<"condition 3"<<endl;
            mover--;
        }
        
    }
    cout<<"helo"<<endl;
    
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}