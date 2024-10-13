#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int countOccurence1(int arr[],int n,int k){
    unordered_map<int,int> mp;
    // store all the elements count
    for(int i = 0;i<n;i++){
        mp[arr[i]]++;
    }
    // wen have count now check the thersold
    int thersold = n/k;

    int count = 0;
    // traverse and check hpw many are more than thersold
    for(auto i : mp){
        if (i.second > thersold){
            count++;
        }
    }
    return count;
}

int check(unordered_map<int,int> cnd){
    for(auto i:cnd){
        if (i.second == 0)    {
            return i.first;
        }
    }
    return -1;
}

void decrease(unordered_map<int,int> &cnd){
    for(auto i : cnd){
        cnd[i.first]--;
    }
}

void makezero(unordered_map<int,int> &cnd){
    for(auto i:cnd){
        cnd[i.first] = 0;
    }
}
void count(unordered_map<int,int> &cnd,int arr[],int n){
    for(int i = 0;i<n;i++){
        if (cnd.find(arr[i]) != cnd.end()){
            cnd[arr[i]] ++;
        }
    }
}
int countOccurence(int arr[],int n,int k){
    int thersold = n/k;
    unordered_map<int,int> cnd; // this will store the candidate with their frequency.
    // start to find the candidate
    int cndSize = 0;
    for(int i =0;i<n;i++){
        int num = arr[i];
        // check element is present or not
        int zero = check(cnd);
        if (cnd.find(num) != cnd.end()){
            // present!!
            cnd[num]++;
        }

        // if not then check is there any cnd seat left or not
        else if (cndSize < k-1){ // if we want k majority so seat will be k-1 for that
            cnd[num] = 1;
            cndSize++;
        }
        // if not check any candidate is 0 or not
        else if (zero != -1){
            cnd.erase(zero);
            cnd[num] = 1;
        }
        // if not then decrease all of them
        else{
            // decrease all of them
            decrease(cnd);
        }
    }

    // we have the candidate here
    // make it zero
    makezero(cnd);
    // count each of them 
    count(cnd,arr,n);

    // now check which is more than k here.
    int cnt=0;
    for(auto i : cnd){
        if (i.second > thersold){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n = 11;
    int arr[n] = {6,2,4,1,0,1,1,6,6,4,0};
    cout<<"enter the majority "<<endl;
    int k;
    cin>>k;
    int ans = countOccurence(arr,n,k);
    cout<<"total numbers which is more than thersold are "<<ans<<endl;

}