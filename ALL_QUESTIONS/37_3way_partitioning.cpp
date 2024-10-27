#include<iostream>
#include<vector>
using namespace std;

void threeWayPartition(vector<int> &array,int a,int b){
    // we will use three pointer 
    // where first pointer use to swap the value with smaller value and other pointer will swap the value with larger value
    // just like we do with 012 here also do like that but here just.
    int n = array.size();
    int min = 0;
    int mid = 0;
    int max = n-1;

    while(mid<=max){
        // if mid found small swap with the min
        if (array[mid] < a){
            swap(array[mid],array[min]);
            min++;
            mid++;
            // why not mid also because may be any other value also appeared which is not middle
        }

        else if (array[mid] > b){
            swap(array[mid], array[max]);
            max--;
            // mid++;
        }
        else{
            mid++;
        }
        // 3 3 3 1 4 2 5 5 7 10 6 8 7 8 10 
    }
}
int main(){
    vector<int> array = {4,9,2,5,8,10,6,2,3,10,9,9,6};
    int a = 7;
    int b =  8;
    threeWayPartition(array,a,b);
    for(int i : array){
        cout<<i<<" ";
    }
    cout<<endl;

}