#include <bits/stdc++.h>
using namespace std;

int maxProfiting(vector<int>& price){
    int buy = 0, sell = 1, n = price.size();
    int maxProfit = 0, profit = 0;

    while(sell<n){

        if(price[buy]<price[sell]){

            // calculate profit
            // update maxProfit
            profit = price[sell] - price[buy];
            maxProfit = max(maxProfit, profit);
        }
        else{
             // today's price is cheaper
            // move buy to sell
            buy = sell;
        }
        sell++;
    }
    return maxProfit;
}

int main(){
    //7,6,4,3,1
    vector<int> prices = {1,2,3,4,5};
    cout<< maxProfiting(prices)<<endl;
    return 0;
}