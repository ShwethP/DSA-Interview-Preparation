#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max

class Solution {
public:
    int maxProfitBruteForce(std::vector<int>& prices) {
        int max_profit = 0;
        int n = prices.size();

        // Outer loop selects the buying day
        for (int i = 0; i < n; i++) {
            // Inner loop selects the selling day (must be after the buying day)
            for (int j = i + 1; j < n; j++) {
                // Calculate profit if we buy at day 'i' and sell at day 'j'
                int current_profit = prices[j] - prices[i];
                
                // Update max_profit if this combination is better
                max_profit = std::max(max_profit, current_profit);
            }
        }

        return max_profit;
    }
};

int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    std::cout << "Max Profit (Brute Force): " 
              // Output: 5 (Buy at 1, Sell at 6)
              << solution.maxProfitBruteForce(prices) << std::endl; 
              
    return 0;
}
