#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


void print(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }cout<<endl;
}
void reverseit(vector<int> & arr,int n){
    int start = 0;
    int end = n-1;
    while(start< end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}


void nearest_small(vector<int> &array,vector<int> row,int n,bool check){
    // this vector contains -1 and index
    stack<int> st;
    st.push(-1);
    /*
        traverse every node and check top element is smaller or bigger
        if : if it is smaller then this will be the the nearest small push it and store curr element index in stack also
        ele: if it is larger then pop till you get any smaller

    */
   for(int i =0;i<n;i++){
    if (st.top() == -1){
        array[i] = -1;
        st.push(i);

    }
    else{
        while(row[st.top()] >= row[i]){
            st.pop();
        }

        // now at the top there will be the smaller element so push his address in the ans vector
        if (check){
        array[i] = st.top();
        }
        else{
            if(st.top() == -1){
                array[i] = -1;
            }else{
                array[i] = n-1 - st.top();
            }
        }
        // and now push the current element in the stack
        st.push(i);
    }
   }


}


int maxArea(vector<vector<int>> &mat){
    int row = mat.size();
    int col = mat[0].size();
    int max_ans = 0;
    vector<int> poll(col,0);
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            if (mat[i][j] == 0){
                poll[j]=0;
            }else{
                poll[j]+=mat[i][j];
            }
        }
        vector<int> left(col,0);
        vector<int> right(col,0);
        // for the left
        nearest_small(left,poll,col,true);
        // for the right
        reverseit(poll,col);
        nearest_small(right,poll,col,false);
        reverseit(poll,col);
        reverseit(right,col);
        // now i have correct address now find the length and breadth 

        for(int j =0;j<col;j++){
            int length = poll[j];
            int lower = left[j];
            int higher = right[j];
            int breadth=1;
            if (lower == -1 && higher == -1){
                breadth = col;
            }
            else{
                if (lower == -1){
                    // lower = 1;
                    breadth = higher - 1;
                }
                else if (higher == -1){
                    breadth = col-1 - lower;
                }
                else{
                    
                    breadth = higher - lower -1;
                }
            }
            // cout<<"breadth "<<breadth<<endl;
            int area = length*breadth;
            
            max_ans = max(max_ans,area);
        }

    }
    return max_ans;
}
int main(){

    vector<vector<int>> mat = {
    // Test Case 2: Singe row with alternating 1s and 0s
        {}

    };
    int ans = maxArea(mat);
    cout<<ans<<endl;
}