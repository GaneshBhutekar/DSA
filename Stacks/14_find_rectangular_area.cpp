#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void reverseit(vector<int> &histo , int n){
    int start =0;
    int end = n-1;
    while(start <= end){
        swap(histo[start],histo[end]);
        start++;
        end--;
    }
}

vector<int> nextsmaller(vector<int> histo , int n){
    stack<int> st;
    vector<int> next;
    st.push(-1);
    for(int i = n-1;i>= 0;i--){
        int element = histo[i];
        while(st.top() != -1 && histo[st.top()]>=element){
            st.pop();

        }
        next.push_back(st.top());
        st.push(i);
    }

    // reverse it .
    reverseit(next,n);
    return next;
}

vector<int> prevsmaller(vector<int> histo, int n){
    // first reverse it .
    // reverseit(histo,n);
    stack<int> st;      
    vector<int> prev;
    st.push(-1);
    for(int i= 0;i<n;i++){
        int element = histo[i];
        while(st.top() != -1 && histo[st.top()] >= element){
            st.pop();
        }
        prev.push_back(st.top());
        st.push(i);

    }
    return prev;
}

int find_the_area(vector<int> histo){
    int n  = histo.size();
    vector<int> next = nextsmaller(histo,n);
    vector<int> prev = prevsmaller(histo,n);

    int area=INT_MIN;
    for(int i =0;i<n;i++){
        int length = histo[i];
        if (next[i]==-1){
            next[i] = n;
        }
        int breadth = next[i] - prev[i] -1;

        int new_area = length*breadth;
        if (new_area > area){
            area = new_area;
        }
    }
    return area;
}
int main(){
    vector<int> arr = {2,4,3,3,3,2,1};
    vector<int> ansnext = nextsmaller(arr,7);
    vector<int> ans = prevsmaller(arr,7);

    for(int j : ansnext ){
        cout<<j<<" ";
    }
    cout<<endl;
    for (int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;


    int area = find_the_area(arr);
    cout<<"maximum area in histo gram is "<<area<<endl;

}