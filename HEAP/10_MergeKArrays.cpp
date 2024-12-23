#include<iostream>
#include<vector>
#include<queue>



/*
    DESCRIPTION:
    Given k sorted arrays arranged in the form of a matrix of size k * k.
    The task is to merge them into one sorted array.
    Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java,
    and list in python).
    if there are k differennt vector then just check by arr[i].size() in the while loop.
*/
class value{
    public:
    int data;
    int row;
    int col;
    value(int data,int row,int col){
        this ->row = row;
        this -> data = data;
        this ->col = col;
    }
    // bool operator>(const value& other) const {
    //     return this->data > other.data; // return true if this is correct 
    // }
    /*
    why we can't using this operator comparater 
    Because the class is normal pointer but we are comparing dynamic node aloocaetd in heap so wee can't create 
    method here we have to create separate class or standalone funcition
    */
};

class CompareNode{
    public:

    bool operator()(ListNode* a, ListNode* b) const {
        return a->data > b->data;
    }
};

std::vector<int> mergeKArrays(std::vector<std::vector<int>> arr,int K){
    std::priority_queue<value,std::vector<value>,CompareNode> pq;
    std::vector<int> result;
    // now we will push the first element of avery array into queue and in vector we wil push 0
    for(int i = 0;i<k;i++){ 
        pq.push(value(arr[i][0],i,0));
    }
    // now pq has sorted first element
    while(!pq.empty()){
        // pop the first element
        value element = pq.top();
        pq.pop();
        // now store this into the result
        result.push_back(element.data);
        //now insert new element in the queue
        // check whether the next index should not be out of bound
        if (element.col+1 < k){
            pq.push(value(arr[element.row][element.col+1],element.row,element.col+1));
        }

    }
    return result;
}

void print_array(std::vector<int> &arr){
    for(int i: arr){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    std::vector<std::vector<int>> arr = {
        {1,2,3,4},
        {2,2,3,4},
        {5,5,6,6},
        {7,8,9,9}
    };
    int k = arr.size();

    std::vector<int> ans = mergeKArrays(arr,k);
    print_array(ans);
    

}