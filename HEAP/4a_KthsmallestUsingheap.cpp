#include<iostream>
#include<vector>
using namespace std;

void maxheap(vector<int> &arr,int index,int n){
    // remember it is start from 0
    while(index < n-1){

        int left = index*2+1;
        int right = index*2 +2;
        int largest = index;
        if (left< n && arr[left] > arr[largest]){
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if (largest == index){

            return;
        }
        swap(arr[index],arr[largest]);
        index = largest;
    }
}


void printit(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;
}


int KthSamllest(int k,vector<int> arr){
    // turn it into the heap structure 
    // maxheap
    int n = arr.size();
    for(int i =n/2 -1;i>=0;i--){
        maxheap(arr,i,n);
    }
    // now it is in max heap form 
    // now sort it 
    int i = n-1;
    while(i>0){
        swap(arr[0],arr[i]);
        // now the biggest element is at the last and at the top we need to heapify it/
        maxheap(arr,0,i);
        i--;
    }
    printit(arr);
    // now  get the kth value
    
    // now return thhe kth element
    int first = arr[0];
    i = 0;
    k--;
    while(i<n && k!=0){
        if (arr[i] != first){
            k--;
            first = arr[i];
        }
        i++;
    }
    return first;
}
int main(){
    vector<int>  arr = {3,1,2};
    int k = 2;
    int ans = KthSamllest(k,arr);
    cout<<"answer is "<<ans<<endl;

}