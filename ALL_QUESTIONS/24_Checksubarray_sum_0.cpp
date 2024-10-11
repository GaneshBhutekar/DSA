#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


bool subArrayExists(int arr[],int n){
    unordered_map<int,int> mp;
    int pre_sum = 0;
    for(int i = 0;i<n;i++){
        if (arr[i] == 0){
            return true;
        }
        pre_sum+=arr[i];
        if (pre_sum == 0){
            return true;
        }
        if (mp[pre_sum]){
            return true;
        }
        mp[pre_sum] =1;
    }
    return false;
}
int main(){
    int n = 5;
    int arr[n] = {3,4,2,-4,1,4,5};
    if (subArrayExists(arr,n)){
        cout<<"yes it has subarray of sum 0"<<endl;
    }
    else{
        cout<<"no it don't have any subarray which have sum 0"<<endl;
    }
}