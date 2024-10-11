#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> intersection(vector<vector<int>> &nums){
    map<int,int> myMap;
    for(auto &i: nums){
        for(auto j:i){
            myMap[j]++;
        }
    }

    int mySize=nums.size(); 
    vector<int> common;
    for(auto &i : myMap){
        if (i.second == mySize){
            common.push_back(i.first);
        }
    }
    return common;

}

int main(){
    vector<vector<int>> nums={
        {3,1,2,4,5},
        {1,2,3,4},
        {3,4,5,6}
    };
    intersection(nums);

}