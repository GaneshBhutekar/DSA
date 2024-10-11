#include<vector>
#include<iostream>
using namespace std;


vector<int> findMajority(vector<int> nums){
    // create two candidate and there votes
    vector<int> ans;
    int cnd1=INT_MIN;
    int vote1=0;

    int cnd2=INT_MIN;
    int vote2=0;

    int n = nums.size();
    for(int i =0;i<n;i++){

        if (vote1 == 0 && nums[i] != cnd2){
            cnd1= nums[i];
            vote1++;
        }
        else if(vote2==0 && nums[i] != cnd1){
            cnd2 = nums[i];
            vote2++;   
        }

        // check may be it could be same 
        else if (nums[i] == cnd1){
            vote1++;
        }
        else if (nums[i] == cnd2){
            vote2++;
        }

        // it means it is not equal to any one 

        else{
            vote1--;
            vote2--;
        }
    }


    // now we have two potential candidate check they hav more than 1/3 vote or not
    vote1=0;vote2=0;

    for(int i : nums){
        if (i == cnd1){
            vote1++;
        }
        else if (i == cnd2){
            vote2++;
        }
    }

    // check the votes 
    if (vote1 > n/3){
        ans.push_back(cnd1);
    }
    if (vote2 > n/3){
        ans.push_back(cnd2);
    }

    if (ans.size() == 0){
        return {-1};
    }
    return ans;

}
int main(){

    vector<int> nums = {2, 2,3,4,5,6,7,8,9,0,11,12,13,14,15,16,17,18,19,20,21,22, 6, 6, 6, 6};
    vector<int> ans = findMajority(nums);
    for(int i :ans){
        cout<<i<<" ";
    }
    cout<<endl;

}