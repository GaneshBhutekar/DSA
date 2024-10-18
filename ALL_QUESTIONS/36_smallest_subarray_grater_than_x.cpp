#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int smallestSubWithSum(int x,vector<int> &arr){
    int n = arr.size();
    if (n==1){
        if (arr[0] > x){
            return 1;
        }
        else {
            return 0;
        }
    }
    int left = 0;
    int ans = INT_MAX;
    int sum =0;

    for(int i =0;i<n;i++){
        sum = sum+arr[i];
        if (sum > x){
            // decrease the sum 
            while( sum > x && left <= i){
                ans = min(ans,i-left+1);
                sum = sum - arr[left];
                left++;
            }


        }

    }
    if (ans > n){
        return 0;
    }
    return ans;
}
int main(){
    vector<int> arr = {5,0};
    int x = 4;
    int ans = smallestSubWithSum(x,arr);
    cout<<"minimum distance will be. "<<ans<<endl;

}