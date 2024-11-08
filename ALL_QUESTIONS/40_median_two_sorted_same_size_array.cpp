#include<iostream>
#include<vector>
using namespace std;

float median(vector<int> arr1,vector<int> arr2){ // ok approach 
    // find one of the size
    int n = 2 * arr1.size();
    float mid ;
    int midposition = n/2;
    int i = 0;
    int a1 = 0;
    int a2 = 0;

    while(a1+a2 < n){
        if (arr1[a1] <= arr2[a2] && a1 < n/2){
            i++;

            // now check whether new one is mid or not
            if (i == midposition){
                mid = arr1[a1];
                cout<<mid<<endl;
            }
            else if (i==midposition+1){
                mid += arr1[a1];
                cout<<mid<<endl;
                break;
            }
            a1++;

        }

        else{
            i++;
            // check for thr mid 
            if (i == midposition){
                mid = arr2[a2];
                cout<<mid<<endl;
            }
            else if(i==midposition+1){
                mid +=arr2[a2];
                cout<<mid<<endl;
                break;
            }
            a2++;
        }
    }

    // now return mid value
    return mid/2.0;
}


float Median(vector<int> arr1,vector<int> arr2){ // better approach 
    int midposition = arr1.size();
    int a2=0;
    int a1=0;
    int current,previous;
    for(int i = 0;i<=midposition;i++){
        previous = current;
        // check who is smallest
        if (a1< midposition && (a2 >= midposition || arr1[a1] <= arr2[a2]) ){
            current = arr1[a1];
            a1++;
        }
        else{
            current = arr2[a2];
            a2++;
        }
    }

    // now return the median 

    float mid = (current+previous)/2.0;
    return mid;

}
int main(){
    vector<int> arr1 = {2};
    vector<int> arr2 = {3};
    float ans = Median(arr1,arr2);
    cout<<"median of this array is "<<ans<<endl;

}