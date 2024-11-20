#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;
}
void heapify(vector<int> &arr,int size,int index){
    int left = 2*index;
    int right = 2*index +1;
    int curr = index;

    if (left < size && arr[left] > arr[index]){
        index = left;
    }
    if (right < size && arr[right] > arr[index]){
        index = right;
    }

    if (curr != index){
        swap(arr[curr],arr[index]);
        heapify(arr,size,index);
    }

}

void heap_sort(vector<int> &arr){
    int n = arr.size();
    int i = n-1;
    while(i > 1){
        swap(arr[i],arr[1]);
        heapify(arr,i,1);
        i--;
    }
}


int main(){
    // array should be in max- heap
    vector<int> arr = {-1,100,50,110,70,150,25,40,60};
    cout<<"STARTING ARRAY "<<endl;
    print(arr);
    int n = arr.size();
    for(int i = n/2 -1;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"IN HEAP"<<endl;
    print(arr);
    heap_sort(arr);
    cout<<"FINAL SORTED ARRAY"<<endl;
    print(arr);
}