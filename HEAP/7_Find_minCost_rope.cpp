#include<iostream>
#include<vector>
#include<queue>

/*
        DESCRIPTION:
        Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. 
        The cost to connect two ropes is the sum of their lengths. 

*/
int minCost(std::vector<int> &arr){
    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
    // push everything to the minHeap from the array
    int n =0;
    for(int i : arr){
        minHeap.push(i);
        n++;
    }

    int cost =0;
    int num1 = -1;
    int num2 = -1;
    // first pop the first .
    num1 = minHeap.top();
    minHeap.pop();
    while(!minHeap.empty()){
        // it means there is another one in the heap
        num2 = minHeap.top();
        minHeap.pop();
        cost+=(num1+num2);
        minHeap.push(num1+num2);
        num1 = minHeap.top();
        minHeap.pop();
    }
    return cost;

}
int main(){
    // behave like you are software engineer
    std::vector<int> arr = {4, 2, 7, 6, 9};
    std::cout<<minCost(arr)<<std::endl;

}