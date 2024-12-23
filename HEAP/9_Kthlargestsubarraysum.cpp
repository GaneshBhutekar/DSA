#include<iostream>
#include<vector>
#include<queue>


/*
    DESCRIPTION
    - difficulty - EASY-MEDIUM
    - problem is to find the Kth largest sum in array where sum is of subarray where element 
    - is continious.
    - Brute force one is to find all the subarray sum and then sort it and then find the Kth largest
    - but this will take O(n^2logn) time complexity
    - This handle both space and time complexity efficiently.
*/
int KthLargest(std::vector<int> &arr,int k){
    std::priority_queue<int,std::vector<int>,std::greater<int>> q;
    int q_size=1;
    // now put all the sum in it
    int n = arr.size();
    for(int i =0;i<n;i++){s
        int total = 0;
        for(int j=i;j<n;j++){
            total+=arr[j];
            // push this too the min heap just check whether the queue is full or not 
            // if it is then check whther the top one is smaller than this element or not
            if(q_size<=k){
                q.push(total);
                q_size++;
            }
            else if(q.top() < total){
                q.pop();
                q.push(total);
                q_size++;
            }
        }
    }
    // now at the top our target element is 
    return q.top();
}
int main(){
    std::vector<int> arr = {4,-1,6,8,2};
    int ans = KthLargest(arr,6);
    std::cout<<"answer is "<<ans<<std::endl;
}