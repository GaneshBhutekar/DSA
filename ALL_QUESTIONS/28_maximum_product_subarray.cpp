#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



long long maxProduct(vector<int> &arr){
    // code here

    long long  ans = INT_MIN;
    long long prefix  = 1;
    long long  suffix = 1;
    int n = arr.size();
    for(int i =0;i<n;i++){
        if (prefix == 0){
            prefix = 1;
        }
        if (suffix == 0){
            suffix = 1;
        }
        suffix = arr[n-1-i]*suffix;
        prefix = arr[i] * prefix;
        ans = max(ans,max(prefix,suffix));

    }
    return ans;
}


int main(){
    vector<int> arr = {3,4,-2,0,2,-1,0,-8};
    long long ans = maxProduct(arr);
    cout<<"max value is:-  "<<ans<<endl;
}