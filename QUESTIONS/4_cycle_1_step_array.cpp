#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,2,3,4,5,6};
    int Size= arr.size();
    int last=arr[Size-1];
    int i = Size-2;
    while(i>=0){
        arr[i+1]=arr[i];
        i--;
    }
    arr[0]=last;

    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
}