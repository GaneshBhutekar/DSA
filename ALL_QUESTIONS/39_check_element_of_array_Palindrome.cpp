    #include<iostream>
    #include<vector>
    using namespace std;





    void leftShift(string &s,int &moves,int pos,int dest){
        char element = s[pos];
        while(pos!=dest){
            s[pos] = s[pos-1];
            pos--;
            moves++;
        }
        // add the element there 
        s[pos] = element;
    }

    void rightShift(string &s,int &moves,int pos,int dest){
        char element = s[pos];
        while(pos!=dest){
            s[pos] = s[pos+1];
            pos++;
            moves++;
        }
        s[pos] = element;
    }
    int minMovesToMakePalindrome(string &s){
        int moves = 0;
        int n = s.size();
        int left = 0;
        int right = n-1;
        // check if boith are same then move closer , if not then find the element 
        while(left <= right){
            // check if both are same or not
            if (s[left] != s[right]){
                // cout<<s[left]<<" and "<<s[right]<<endl;
                // find the correct element 
                // left one should be equal to right
                // right should be equal to left
                int L = left+1;
                int R = right-1;
                while(true){
                    if (s[L] == s[right]){
                        // cout<<s[L]<<" and " << L<<" and " << left<<endl;

                        // we got similer in left side first
                        // create the finction who shift the element to the LEFT where it belongs
                        leftShift(s,moves,L,left);
                        break;
                    }
                    else if (s[R] == s[left]){
                        // we got similar in right side first.
                        // create the function who shift the element to the RIGHT where it belongs
                        rightShift(s,moves,R,right);
                        break;
                    }
                    R--;
                    L++;
                }
            }
            left++;
            right--;
        }
        return moves;
    }
    int main(){
        string s = "eqvvhtcsaaqtqesvvqch";

        int ans = minMovesToMakePalindrome(s);
        cout<<"string "<<s<<endl;
        cout<<ans<<endl;

    }