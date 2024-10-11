#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int> &nums){
    // first check the first smallest from back.
    // then find the larger element then pivot one
    // then swap them and sort that portion

    int n = nums.size();
    if (n==1){
        return;
    }
    int i = n-1;
    while(i>0 && nums[i-1] >= nums[i] ){
        i--;
    }
    if (i > 0){
        i--;
    }
    int pivot = nums[i];
    int nextlarger = i;
    while(nextlarger < n-1 && nums[nextlarger+1] > pivot ){
        nextlarger++;
    }

    if (nextlarger != i){
        swap(nums[i],nums[nextlarger]);
        i++;
    }
    // now rever the array from i to n-1
    int start =i;
    int end = n-1;
    while(start < end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    } // we can use reverse() here.
}
int main(){
    vector<int> nums = {1,2};
    nextPermutation(nums);

    for(int i : nums){
        cout<<i<<" ";

    }
    cout<<endl;

}
