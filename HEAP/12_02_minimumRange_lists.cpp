#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

/*
description:
You have k lists of sorted integers in non-decreasing order.
 Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

WE CAN USE PAIR INSTEAD OF CLASS 

*/
class value{
    public:
    int data;
    int row;
    int col;
    value(int data,int row,int col){
        this->data = data;
        this->row = row;
        this ->col = col;
    }

    // comparator for imin heap
    bool operator>(const value &object) const {
        return this->data > object.data;
    }
};

std::vector<int> smallestRange(std::vector<std::vector<int>> &nums){
    // need min heap and max heap both
    std::priority_queue<value,std::vector<value>,std::greater<value>> min_heap;
    std::vector<int> row_sizes ;
    // after creating it now i want sizes of all rows in the container so that don't need to always use .size()
    // and also stores the first number of every row
    int R = nums.size();
    int minimum = INT_MIN;
    int maximum = INT_MIN;
    for(int i = 0;i<R;i++){
        // store int min heap and max heap
        maximum = std::max(nums[i][0],maximum);
        min_heap.push(value(nums[i][0],i,0));
        // store the size also
        row_sizes.push_back(nums[i].size());
    }
    int large = maximum;

    while(!min_heap.empty()){
        // get the smallest value
        int small = min_heap.top().data;
        
        // now check is it smaller than the prebious one
        if (minimum == INT_MIN || maximum-minimum > large-small){
            minimum = small;
            maximum = large;
        }

        // deal with smaller value
        value x = min_heap.top();
        if (x.col+1 >= row_sizes[x.row]){
            break;
        }
        min_heap.pop();
        // check that the new maximum here
        large = std::max(nums[x.row][x.col+1],large);
        min_heap.push(value(nums[x.row][x.col+1],x.row,x.col+1));
    }
    return {minimum,maximum};

}
int main(){
    std::vector<std::vector<int>> nums = {
        {4,10,15,24,26},{0,9,12,20}, {5,18,22,30}
};
    std::vector<std::vector<int>> nums1 = {
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };

    std::vector<int> ans = smallestRange(nums1);
    std::cout<<"minimum : "<<ans[0]<<std::endl;
    std::cout<<"maximum : "<<ans[1]<<std::endl;
    
}