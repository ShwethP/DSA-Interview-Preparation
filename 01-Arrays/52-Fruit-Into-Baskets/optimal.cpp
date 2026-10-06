#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits, int k) {

    int left = 0;
    int maxLength = 0;

    unordered_map<int, int> window;

    for (int right = 0; right < fruits.size(); right++) {

        // add fruit[right]
        window[fruits[right]]++;

        // Shrink while the number of UNIQUE fruit types exceeds k
        while (window.size() > k) {
            // Remove fruit from the left
            window[fruits[left]]--;
            
            // If a fruit's count hits 0, completely remove it from the map
            if (window[fruits[left]] == 0) {
                window.erase(fruits[left]);
            }
            // Move left pointer forward
            left++;
        }

        // update maxLength
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main(){
    vector<int> fruits = {1, 2, 1,2,3,4,5};
    int k = 2;
    int result = totalFruit(fruits, k);
    cout<< result <<endl; //4
    return 0;
}