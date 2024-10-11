#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void reverseit(vector<int> &arr,int n){
    int start = 0;
    int end = n-1;
    while(start < end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
vector<int> nextsmall(vector<int> arr ,int n){
    stack<int> st;
    st.push(-1);
    vector<int> small;
    // in this case put this value by reverse
    for(int i = n-1;i>=0;i--){
        int element = arr[i];
        while(st.top() != -1 && arr[st.top()]>=element){
            st.pop();
        }
        small.push_back(st.top());
        st.push(i);
    }

    // reverse this 
    reverseit(small,n);
    return small;
}

vector<int>  prevsmall(vector<int> arr , int n){
    stack<int> st;
    st.push(-1);
    vector<int> small;
    for(int i = 0;i<n;i++){
        int element = arr[i];
        while(st.top() != -1 && arr[st.top()]>=element){
            st.pop();
        }
        small.push_back(st.top());
        st.push(i);

    }
    return small;
}


int max_area_rectangle(vector<int> arr , int n){
    vector<int> prev = prevsmall(arr,n);
    vector<int> next = nextsmall(arr,n);

    int area=INT_MIN;
    for(int i = 0 ; i<n;i++){
        int length = arr[i];
        while(next[i] == -1){
            next[i]=n;
        }
        int breadth = next[i] - prev[i] -1;

        int curr_area = length*breadth;

        if (curr_area > area){
            area = curr_area;
        }
    }
    return area;
}


int find_max_area_matrix(vector<vector<int>> arr,int n, int m){
        // first send first row and then in loop sen others after.
       // m is sizwe of row 
       // n is size of column 
        int area = max_area_rectangle(arr[0],m);

        for(int i =1;i<n;i++){ // for every row;
            for(int j=0;j<m;j++){ // for column

                if (arr[i][j] != 0){
                    arr[i][j] = arr[i][j] + arr[i-1][j];
                }
                else{
                    arr[i][j]=0;
                }


            }
            int curr_area=max_area_rectangle(arr[i],m);
            if (curr_area > area){
                area = curr_area;
            }

        }
        return area;
}
int main(){
    vector<vector<int>> arr = {
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,1,1}
    };
    int m=4;
    int n=4;
    int area = find_max_area_matrix(arr,n,m);
    cout<<"maximum area  in matrix is  "<<area<<endl;

}