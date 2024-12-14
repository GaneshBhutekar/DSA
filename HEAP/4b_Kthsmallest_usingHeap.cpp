#include<iostream>
#include<vector>
using namespace std;

// we can use std library instead buildig the class

class p_queue{
    public:
    vector<int> arr;
    int size = -1;

    // heapify up
    private:
    void h_up(int index){

        while(index > 0){
            // parent index (0 based situation)
            int parent = (index-1)/2;
            // check child is greater or not
            if (arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;

            }
            else{
                return;
            }
        }
    }
    void h_down(int index){
        int left = index*2+1;
        int right = index*2+2;
        int largest = index;
        if (left < size && arr[left] > arr[largest]){
            largest = left;
        }
        if (right< size && arr[right] > arr[largest]){
            largest = right;
        }
        if (largest != index){
            swap(arr[index],arr[largest]);
            index = largest;
            h_down(index);
        }


    }
    public:
    void insert(int data){
        // update the size
        size++;
        arr.push_back(data);
        // now heapify it
        h_up(size);
    }

    // for the delete
    void deletion(int data){
        // find the data first
        if(size == -1){
            cout<<"empty !!! already"<<endl;
            return;
        }
        
        int i = 0;
        while(arr[i] != data){
            i++;
        }
        // now we have the data just replace it
        arr[i] = arr[size];
        size--;
        arr.pop_back();
        h_down(i);
    }
    int top(){
        return arr[0];
    }
    void pop(){
        deletion(arr[0]);
    }
    void printit(){
        for(int i : arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
};





int Kthsmallest(vector<int> arr,int n,int k){
    p_queue pq;
    // priority queue is craeted
    // insert first k element
    for(int i = 0;i<k;i++){
        pq.insert(arr[i]);
    }
    // now check the new
    for(int i = k;i<n;i++){
        if (arr[i] < pq.top()){
            // if it is so add this and delete the biggest element
            pq.pop();
            pq.insert(arr[i]);
        }
    }
    return pq.top();

}
int main(){
    vector<int> arr = {7,10,4,3,20,5};
    cout<<"enter kth smallest position "<<endl;
    int k;
    cin>>k;
    // now heapify it 
    int size = arr.size();
    int ans = Kthsmallest(arr,size,k);
    cout<<"answer is "<<ans<<endl;



}