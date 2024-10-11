#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,2,0,0,1,1,2,0};
    // dutch flag algorithm 
    int start= 0;
    int mid = 0;
    int end = arr.size() -1;
    while(mid <= end){
        if (arr[mid] == 0){
            swap(arr[mid],arr[start]);
            mid=mid+1;
            start=start+1;
        }
        else if (arr[mid]==2){
            swap( arr[mid], arr[end]);
            end=end-1;
        }
        else{
            mid=mid+1;
        }

    }

    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}