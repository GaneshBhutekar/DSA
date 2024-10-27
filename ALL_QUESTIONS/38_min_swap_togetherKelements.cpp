#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minSwap(int arr[],int n,int k){
    // first check how many are same or below to the k
    int total_k =0;
    for(int i = 0;i<n;i++){
        if (arr[i] <= k){
            total_k++;
        }
    }

    if (!total_k){
        return 0;
    }

    // now makke a sliding window and find the region where we need less swaps
    // check initially how many are bigger than k in initial window
    int bad = 0;
    for(int i=0;i<total_k;i++){
        if (arr[i]> k){
            bad++;
        }
    }

    // now traverse and check each and every window and find minimum here in initially bad are the min 
    int left = 0;
    int right = total_k-1;
    int min_swapes = bad;
    // int swapes = bad;
    while(right < n){
        min_swapes = min(bad,min_swapes);
        if (arr[left] > k){
            bad--;
        }
        left++;
        if ( right <n && arr[right+1] > k){
            bad++;
        }
        right++;
    }

    return min_swapes;
}

int main(){
    int n = 5;
    int arr[n] = {2, 1, 5, 6, 3};
    int k = 3;
    int ans = minSwap(arr,n,k);
    cout<<ans <<endl;

}