#include<iostream>
#include<vector>
using namespace std;
int maxSubarraySum(vector<int> arr){
    int n = arr.size();
    int max_sum=INT_MIN;
    int sum = 0;
    for(int i=0;i<n;i++){
        if (sum < 0 ){
            sum = arr[i];

        }

        else{
            sum+=arr[i];

        }
        if (sum > max_sum){
            
            max_sum = sum;
            cout<<max_sum<<endl;
        }
    }
    return max_sum;
}
int main(){
    vector<int> arr = {-6 ,-5 ,-70 ,-4 ,-1};
    int ans = maxSubarraySum(arr);
    cout<<"maximum sum will be "<<  ans <<endl;
}