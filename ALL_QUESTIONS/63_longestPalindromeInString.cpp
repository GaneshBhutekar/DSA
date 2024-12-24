#include<vector>
#include<iostream>
#include<algorithm>

/*
    DESCRIPTION:
    Given a string s, your task is to find the longest palindromic substring within s.
     A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

    A palindrome is a string that reads the same forward and backwards.
     More formally, s is a palindrome if reverse(s) == s.

    Note: If there are multiple palindromes with the same length,
     return the first occurrence of the longest palindromic substring from left to right.
*/
std::string longestPalindrome(std::string &s){
    // create the 2d vector
    int n = s.size();
    // every block initialized woth 0.
    int max_length = 1;
    int start = 0;
    std::vector<std::vector<int>> check(n,std::vector<int> (n,0));
    // initialized diagonal as 1 
    for(int i= 0;i<n;i++){
        check[i][i] = 1;
    }
    // now i have to traverse the string every time until it 
    for(int i=1;i<n;i++){
        int left = 0;
        int right = i;
        // first check the row and the col if it is same then check that inner set is 
        // palindrome or not
        while(right < n){
            // check the outer elment

            if ((s[left]==s[right]) && (left+1 == right || check[left+1][right-1]==1)){
                // if it is correct then mark it as one also
                check[left][right] =1;
                // check is it bigger length then the rdcorded one
                if (right-left+1 > max_length){
                    max_length = right-left+1;
                    start = left;

                }
            }
            right++;
            left++;
        }
    }

    // at the end we have a length of the palindrome and its starting point
    std::string result;
    for(int i = start;i<start+max_length;i++){
        result.push_back(s[i]);
    }
    return result;
}
int main(){
    std::string s = "abcd";
    std::string result = longestPalindrome(s);
    std::cout<<"longest palindrome founded is : "<<result<<std::endl;
} 