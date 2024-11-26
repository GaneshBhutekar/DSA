#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Element{
    public:
    int value;
    int row;
    int col;
    Element(int value,int row,int col){
        this ->value = value;
        this->row = row;
        this -> col = col;
    }
    // comparator function
    bool operator>(const Element &other) const{
        // this is for mean heap it means that the input value is smaller than the called objct than it is true

        return other.value < value;
    }
};



int KthSmallest(int mat[4][4],int n,int k){
    priority_queue<Element,vector<Element>,greater<Element>> pq;
    // first add the starting element and then run for the k round
    for(int i = 0;i<n;i++){
        // add every row 1st element
        pq.push(Element(mat[i][0],i,0));
    }
    // now go for to find the element
    int i =0;
    int value = mat[0][0];
    while(i<k){
        i++;
        Element demo = pq.top();
        pq.pop();
        value = demo.value;
        // now just add next element of that row in the queue
        if (demo.col < n-1){
            pq.push(Element(mat[demo.row][demo.col+1],demo.row,demo.col+1));
        }
    }
    return value;
}
int main(){
    int n = 4;
    int arr[4][4] = {
        {16,28,60,64},
        {22,41,63,91},
        {27, 50, 87, 93},
        {36, 78, 87, 9}

    };
    cout<<"enter the order element you want"<<endl;
    int k;
    cin>>k;
    int ans = KthSmallest(arr,n,k);
    cout<<"answer is "<<ans<<endl;

    
}