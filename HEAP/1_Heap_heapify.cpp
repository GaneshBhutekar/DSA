#include<iostream>
#include<vector>
using namespace std;

// don't let your brain rot!!!!@!!!


// This is 0 based heap 
class heap{
    public:
    int arr[100];
    int size;
    heap(){
        this->size = -1; // so that increase and insert           
    }

    void insert(int data){
        // increase the size
        size++;
        // check is it more than 100 
        if (size >= 100){
            cout<<"heap is full"<<endl;
            return;
        }

        // you cam insert
        arr[size] = data;
    }

    void deleteit(int target){
        // check if it is empty 
        if (size == -1){
            cout<<"Heap is Empty"<<endl;
            return;
        }

        // find the target
        int index = 0;
        while(index <= size && arr[index] != target){
            index++;
        }

        // we reach the destinaton
        arr[index] = arr[size];
        size--;

        // heapify it
        heapify(index);
    }

    void heapify(int index){
        // now we have to heapify the current element to their right position
        // check their children
        int current = index;
        int left = index*2 +1;
        int right = index*2 + 2;
        // pahle dekh ki index wala element left wale se bada nahi 
        // hai kya hain to chnge agar right wala usase bhi bada hain toh firse change
        if (left <= size && arr[left] > arr[index]){
            // it is 
            index = left;
        }
        if (right <= size && arr[right]> arr[index]){
            index = right;
        }

        // now index have the index of biggest number bwteen parent and child
        // if it is one of child
        if (current != index){
            swap(arr[current],arr[index]);
            heapify(index);
        }

    }

    void printit(){
        for(int i =0;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
};


int main(){

    heap h;
    // first insert every thing
    int data;
    cout<<"enter in data"<<endl;
    cin>>data;
    int n =0;
    while(data != -1){
        n++;
        h.insert(data);
        cout<<"enter the data"<<endl;
        cin>>data;
    }
    cout<<"size is"<<n<<endl;
    h.printit();
    cout<<"heapify it"<<endl;
    // we don not need to heapify the last leaf node just parnt one
    for(int i = n/2 -1;i>=0;i--){
        // start from  middle or start does not care
        cout<<"for "<<i<<endl;
        h.heapify(i);
    }
    h.printit();
    // 60 61 48 50 59 49 -1
    // delete
    h.deleteit(60);
    h.printit();


}