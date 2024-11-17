#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/*we can do by k way mwrgin technique but it takes N^3 how??

    1. merging the rows 1N+2N+3N+....+(N-1)N = N^2.
    2. and then evry time copying it O(N)
    so, total will be N^2 * N = N^3
    so, optimized somplexityy is only O(Nlog * N^2)
*/

class Element{
    public:
    int value;
    int row;
    int col;
    Element(int value,int row,int col){
        this -> value = value;
        this->row = row;
        this->col = col;
    }
    bool operator>(const Element &other) const {
        return value > other.value;
    }
};


vector<vector<int>> sortedMatrix(int N,vector<vector<int>> Mat){
    priority_queue<Element,vector<Element>,greater<Element>> pq;
    // now this will have in new data type and we will use it

    // int row = Mat.size();
    // int col = Mat[0].size();

    // add first col in it
    for(int i =0;i<N;i++){
        // create new object
        pq.push(Element(Mat[i][0],i,0)); 
    }

    vector<vector<int>> ans(N,vector<int> (N));
    int ans_R = 0;
    int ans_C=0;
    while(!pq.empty()){
        // now get the element and insert the value and insert next element of it 
        Element obj = pq.top();
        // cout<<obj.row << " " << obj.col<<endl;
        // cout<<obj.value<<endl;
        pq.pop();
        // insert this into the 2D vector
        ans[ans_R][ans_C] = obj.value;
        ans_C++;
        if (ans_C >= N){
            ans_C = 0;
            ans_R++;
        }

        // ad next element.
        if (obj.col+1 < N){
            // cout<<" "<<"iss time tha yaha"<<endl;
            pq.push(Element(Mat[obj.row][obj.col+1],obj.row,obj.col+1));
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> Mat = {
        {10,20,30,40},
        {15,25,35,45},
        {27,29,37,48},
        {32,33,39,50}
    };
    int N = Mat.size();

    vector<vector<int>> ans = sortedMatrix(N,Mat);
    for(auto i: ans){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }


}