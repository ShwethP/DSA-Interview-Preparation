#include <iostream>
#include <vector>
#include <unordered_map>

int subarraysWithXorK(const std::vector<int>& arr, int k) {
    // Stores the frequency of prefix XOR values
    std::unordered_map<int, int> xorMap;
    
    // Base case: An empty prefix has an XOR sum of 0
    xorMap[0] = 1;
    
    int currentXor = 0;
    int count = 0;
    
    for (int num : arr) {
        // Update prefix XOR for current position
        currentXor ^= num;
        
        // Target prefix XOR we need to find
        int target = currentXor ^ k;
        
        // If the target prefix XOR exists, add its frequency to the total count
        if (xorMap.find(target) != xorMap.end()) {
            count += xorMap[target];
        }
        
        // Update the frequency of the current prefix XOR in the map
        xorMap[currentXor]++;
    }
    
    return count;
}

int main() {
    std::vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    
    std::cout << "Total subarrays: " << subarraysWithXorK(arr, k) << std::endl;
    // Output: 4
    
    return 0;
}
