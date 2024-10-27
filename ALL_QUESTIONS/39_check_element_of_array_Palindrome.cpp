#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool PalinArray(vector<int> &arr){
    // first every time move in the array and check everry element, that is it palindrome or not if not then return false.
    for(int i :arr){
        // check that is this number is palindrome or not
        int reverse = 0;
        int num= i;
        while(num!=0){
            int digit = num%10;
            reverse = (10*reverse) + digit;
            num = num/10; 11111
        }
        // now check that revrse and num is equal or not
        if (i-reverse != 0){
            return false;
        }
    }

    return true;
}
int main(){
    vector<int> arr = {111, 222222122, 333, 444, 555};
    if (PalinArray(arr)){
        cout<<"yes all are palindrome"<<endl;

    }
    else{
        cout<<"no there is some which is not palindrome"<<endl;
    }

}