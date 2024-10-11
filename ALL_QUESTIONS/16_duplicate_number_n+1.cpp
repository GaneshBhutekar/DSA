#include<iostream>
#include<vector>
using namespace std;

int duplicate_one(vector<int> arr){
    int slow=arr[0];
    int fast = arr[arr[0]];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    // ruko khel khatam nahi hua hain.

    slow = 0;
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}
int main(){
    // test cases
    vector<int> arr = {1,2,3,4,4};
    vector<int> arr1 = {3,3,3,3,3};
    vector<int> arr2 = {1,4,4,2,4};
    vector<int> arr3 = {1,1};
    vector<int> arr4 = {1,2,3,4,5,6,7,7};
    vector<int> arr5 = {1,3,4,2,2};
    vector<int> arr6 = {2,5,9,6,9,3,8,9,7,1};

    int ans = duplicate_one(arr6);
    cout<<"duplicate value is "<<ans<<endl;


}