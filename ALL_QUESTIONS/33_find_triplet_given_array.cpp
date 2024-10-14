#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool find3Numbers1(int arr[],int n,int x){
    // put all frequency into the map


    // THIS Approach is ok ... more to optimized it 
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        if (mp[arr[i]]){
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]]=1;
        }
    }

    // now we have frequencies let find all the combination 
    for(int i = 0;i<n-1;i++){
        mp[arr[i]]--;
        // because we already using this 
        for(int j=i+1;j<n;j++){
            mp[arr[j]]--;
            // now get sum of this 2 and find how much need if the needed value is there so return true
            // cout<<mp[arr[i]]<< " "<< mp[arr[j]]<<endl;
            int sum = arr[i]+arr[j];
            if (mp[x-sum]){
                // cout<<arr[i]<<" "<<arr[j]<<endl;
                // cout<<x-sum<<endl;
                return true;
            }

            mp[arr[j]]++;
        }
        mp[arr[i]]++;
    }

    return false;
}


bool find3Numbers(int arr[],int n,int x){
    // sort it so that we can find the best pair to get the sum(eliminate the uneccessory pairs)
    sort(arr,arr+n);

    // now it is sorted u have to find the case where sum is equal
    for(int i =0;i<n-2;i++){
        int value = arr[i];
        int start = i+1;
        int last = n-1;
        while(start < last){
            // if it is same then return true.
            int total = value+arr[start]+arr[last];
            if (total == x){
                return true;
            }
            // if  this combinaton makes less nummber than target we have to increase it 
            // so we will increase last
            else if (total < x){
                start++;
            }

            // or may be comination makes more value than x we will have to decrease it 
            else{
                last--;
            }
        }

        // if with 1 it is not happens need big value increase the i 
    }

    // no any triplet made there 
    return false;
    

}
int main(){
    int n = 6;
    int arr[n] = {40,20,10,3,6,7};
    int x = 20;
    if (find3Numbers(arr,n,x)){
        cout<<"yes it has triplet of "<<x<<endl;
    }
    else {
        cout<<"no array don't have triplet for "<<x<<endl;
    }


}