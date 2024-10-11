#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={3,2,7,4,4,4,9,1,10};
    for(int i =1; i< arr.size();i++){
        int j=i-1;
        int value = arr[i];
        while(arr[j]>value){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=value;

    }

    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}