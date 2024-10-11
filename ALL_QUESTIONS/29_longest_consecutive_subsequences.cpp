#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int findLongestConseqSubseq(int arr[],int N){
    // find the min and all existence
    unordered_map<int,int> mp;
    int min_no = INT_MAX;
    int max_no = INT_MIN;
    for(int i =0;i<N;i++){
        min_no = min(arr[i],min_no);
        max_no = max(arr[i],max_no);
        mp[arr[i]]++;
    }

    // we have min and all existence 
    // traverse till the largest number
    int i = min_no;
    int max_cnt = 0;
    int cnt = 0;
    while(i<=max_no){
        if (mp[i]){
            cnt++;
            max_cnt = max(cnt,max_cnt);
        }
        else{
            cnt=0;
        }
        i++;

    }

    return max_cnt;
}
int main(){
    int n = 7;
    int arr[n] = {100};
    int ans = findLongestConseqSubseq(arr,n);
    cout<<ans<<endl;

    
}