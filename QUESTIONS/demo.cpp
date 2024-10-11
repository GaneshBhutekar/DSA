#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int who_is_celeb(vector<vector<int>> arr){
    int mysize = arr.size();
    int celeb_index=-1;
    for(int i = 0;i<mysize;i++){

        // for rows...
        // check any one have no 1 in the row that is celebrity.

        int is_this_celeb_row = true;
        for(int j = 0;j<mysize;j++){
            if (i == j){
                continue;
            }
            if (arr[i][j] == 1){
                is_this_celeb_row = false;
            }
        }
        
        // for col
        // if there is celebrity then column shows the 1 only diagonal ignored
        int onetime = 0;
        bool is_this_celeb_col = true;
        for(int k=0;k<mysize;k++){
            if (i==k){
                continue;
                
            }
            if (arr[k][i] == 0){
                is_this_celeb_col = false;
            }

        }

        // if both are true then it is confirmed celebrity
        if (is_this_celeb_col && is_this_celeb_row){
            return i;
        }
    }


    cout<<"no any celeb here "<<endl;
    return -1;

}

int who_is_celeb_2(vector<vector<int>> arr){
    // put all the element to stack.
    stack<int> st;
    int mysize = arr.size();
    for(int i =0;i<mysize;i++){
        st.push(i);
    }
    int stack_size = st.size();
    while(st.size() > 1){
        // pop two element .....
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();

        if (arr[A][B] == 1){
            // it means that A knows B so 
            st.push(B);
        }
        else if (arr[B][A] == 1){
            // te means that B knows A so
            st.push(A);
        }
        
    }
    // for row
    int celeb = st.top();
    int rowstatus = true;
    for(int i =0;i<mysize;i++){
        if (arr[celeb][i]== 1){
            rowstatus = false;
        }
    }

    // for col.
    int cnt_one=0;
    for(int j = 0;j<mysize;j++){
        if (arr[j][celeb] == 1){
            cnt_one += 1;
        }
    }
    

    if (rowstatus == true && cnt_one == mysize-1){
        return celeb;
    }
    else{
        return -1;
    }
}



int main(){
    vector<vector<int>> arr={
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    vector<vector<int>> arr2 = {
        {0,1},
        {1,0}
    };
    int index = who_is_celeb_2(arr2);
    cout<<"celebrity location is at "<<index<<endl;

    index who_is_cele


}
