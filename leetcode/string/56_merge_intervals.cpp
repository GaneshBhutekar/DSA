#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printing(vector<vector<int>> arr){
    for(auto i : arr){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void sorting(vector<vector<int>> &arr){
    int n = arr.size();
    for(int i = 1;i<n; i++){
        int value1 = arr[i][0];
        int value2 = arr[i][1];
        int j = i-1;
        while(j >= 0 && arr[j][0] > value1){
            arr[j+1][0] = arr[j][0];
            arr[j+1][1] = arr[j][1];
            j--;
        }
        arr[j+1][0] = value1;
        arr[j+1][1] = value2;       

    }
}
vector<vector<int>> merge(vector<vector<int>> intervals){

    int n = intervals.size();
    // sort ->see ranges and push it 

    // sorting(intervals);
    sort(intervals.begin(),intervals.end());
    printing(intervals);
    // now it is sorted.
    vector<vector<int>> ans;
    // pahla value
    int value1 = intervals[0][0];
    int value2 = intervals[0][1];
    int index=1;
    while(index < n){
        if (intervals[index][0] <= value2){
            if(value2 < intervals[index][1]){
                value2 = intervals[index][1];
            }
        }
        else{
            ans.push_back({value1,value2});
            value1 = intervals[index][0];
            value2 = intervals[index][1];
        }
        index++;

    }
    ans.push_back({value1,value2});
    return ans;

}
int main(){
    vector<vector<int>> arr = {
        {1,3},
        {15,18},
        {8,10},
        {2,6}
    };

    vector<vector<int>> arr1 = {
        {1,4},
        {4,5}
    };

    vector<vector<int>> arr2 = {
        {1,2}
    } ;

    printing(arr);
    vector<vector<int>> ans = merge(arr);
    cout<<"merge array"<<endl;
    printing(ans);
    // sort 

}