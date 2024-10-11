#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {3,1,1,0,4,4,2,8,1,4,1,1,1,1,8,1,0,0,9,8,0,0,1};
    // how to check is there any majority vote of someone or not if yes then whome.

    int cnt = 1;
    int element=nums[0];
    int n = nums.size();
    for(int i =1;i<n;i++){
        if (nums[i] == element){
            cnt++;
        }
        else{
            cnt--;
        }

        if (cnt == 0){
            element = nums[i];
            cnt=1;
        }
    }

    // taken element is majority or not 
    cnt=0;
    for(int i: nums){
        if (i==element){
            cnt++;
        }
    }

    if (cnt > n/2){
        cout<<"the majority element is "<<element<<endl;
    }
    else{
        cout<<"no one is majority here"<<endl;
    }

}