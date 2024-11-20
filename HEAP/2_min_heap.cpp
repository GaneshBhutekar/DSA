#include<iostream>
#include<vector>
using namespace std;
/*
    BUILD MIN-HEAP
    array is given just make an function which convert it into the min heap 
*/


void heapify(vector<int> &arr,int index,int size){
    // find the childrens
    int current = index;
    int left = index*2+1;
    int right = index*2+2

    // now chck who is more smaller
    if(left <size && arr[left] < arr[index]){
        index = left;
    }
    if(right< size && arr[right] < arr[index]){
        index = right;
    }

    // check there if there is change or not
    if (current != index){
        swap(arr[current],arr[index]);
        heapify(arr,index,size);
    }

}

void min_heap(vector<int> &arr){
    // size
    int n = arr.size();
    // start the loop 
    for(int i = n/2 -1;i>=0;i--){
        // we have to heapify here
        cout<<i<<endl;
        heapify(arr,i,n);
    }


}

void printit(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;
}
int main(){
    vector<int> arr = {38,82,12,39,40,61,10};
    min_heap(arr);
    printit(arr);


}