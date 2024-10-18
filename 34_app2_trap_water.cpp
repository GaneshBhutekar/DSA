#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;



void print_array(vector<int> arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
vector<int>  find_suffix(vector<int> arr,int n){
    // now suffix is start friom last and find every node recebnt biggest
    int curr =INT_MIN;
    vector<int> suffix(n,0);
    // suffix does  store the maximum value til that poiunt
    for(int i = n-1;i>=0;i--){
        if (arr[i] > curr){
            curr = arr[i];
        }
        suffix[i] = curr;
    }
    return suffix;
}

vector<int> find_prefix(vector<int> arr,int n){
    int curr = INT_MIN;
    vector<int> prefix;
    for(int i =0;i<n;i++){
        if (arr[i] > curr){
            curr = arr[i];
        }
        prefix.push_back(curr);
    }

    return prefix;

}



// this function requires bith prefix and suffix.
int trap1(vector<int> &height){
    // find prefix and suffuix
    int n = height.size();
    int output = 0;
    vector<int> suffix = find_suffix(height,n); /// it has element
    vector<int> prefix = find_prefix(height,n);

    // we have every height left and right biggest building
    for(int i =0;i<n;i++){
        if (prefix[i] > height[i] && height[i] < suffix[i]){
            // find min among them 
            int minValue = min(prefix[i],suffix[i]);
            output += minValue-height[i];
        }
    }   

    return output;

}

int trap2(vector<int> &height){
    // no need to find prefix before becuse we will find it here
    int n = height.size();
    if (n <= 1){
        return 0;
    }
    int max_pre =  INT_MIN;
    vector<int> suffix = find_suffix(height,n);
    int output =0;

    //start to calculate.
    for(int i=0;i<n;i++){
        // find prefix
        max_pre = max(max_pre,height[i]);

        // now find the ampount of water for each and evrry building above
        if (height[i] < max_pre && height[i] < suffix[i]){
            // find min 
            int minValue = min(max_pre,suffix[i]);
            output += minValue - height[i];
        }
    }
    return output;

}

int trap(vector<int> &height){
    // dynamic way
    int n = height.size();
    int left = 0;
    int leftmax = 0;
    int right = n-1;
    int rightmax=0;
    int output = 0;

    // now approach is that check both side which is smaller the smaller 
    //one will check is it greater than his side geatest right now if yes
    //  then it will move furthur without dooiing anything but if it is smaller than either than find the trap water and add it
    while(left < right){

        if (height[left] < height[right]){
            // it means left is smaller then check that it is smaller than his left gratest or not
            if (height[left] > leftmax){
                leftmax = height[left];
            }
            else{
                // find the wter trap because bith side are greater than this height
                output+=leftmax - height[left];
            }
            left++;
        }
        else{
            // it means right one is smaller
            if (height[right] > rightmax){
                rightmax= height[right];
            }
            else{
                // it is smaller than both so ,
                output += rightmax-height[right];
            }
            right--;
        }
    }

    // and we have answer
    return output;

}

int main(){

    vector<int> height = {7,4,2,8,2,7,4,2,5};
    int ans = trap(height);
    cout<<"total ampunt of water trap will be "<<ans<<endl;

}