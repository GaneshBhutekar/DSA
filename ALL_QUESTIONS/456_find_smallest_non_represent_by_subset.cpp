#include<iostream>
#include<vector>
using namespace std;

long long findSmallest(vector<int> &arr){
    long long ans = 1;
    int n = arr.size();
    for(int i =0;i<n;i++){
        if (arr[i] > ans){
            return ans;
        }
        else{
            ans+=arr[i];
        }
    }
    return ans;
}
int main(){
    vector<int>arr = {1,2,4,13};
    vector<int> arr1 = {1,1,4,13};
    long long ANS = findSmallest(arr1);
    cout<<ANS <<endl;
}