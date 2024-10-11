#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size();
    int max = prices[0];
    int min = prices[0];
    int profit = 0;
    if (n == 1){
        return 0;
    }

    for(int i =1;i<n;i++){
        if (prices[i] < min){
            max = -1;
            min = prices[i];
        }
        else{
            max = prices[i];
            if (profit < max-min){
                profit = max-min;
            }
        }
    }

    return profit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    int ans = maxProfit(prices);
    cout<<"answer is "<<ans <<endl;
}