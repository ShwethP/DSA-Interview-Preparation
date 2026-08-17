#include <iostream>
#include <vector>

using namespace std;

int findMin(const vector<int>& a) {
    int l = 0;
    int r = a.size() - 1;
    
    // If the array is not rotated at all, return the first element
    if (a[l] <= a[r]) {
        return a[l];
    }
    
    while (l < r) {
        int mid = l + (r - l) / 2;
        
        // If mid element is greater than the rightmost element,
        // the minimum must be in the right unsorted part.
        if (a[mid] > a[r]) {
            l = mid + 1;
        } 
        // Otherwise, the right part is sorted, so the minimum 
        // is either at mid or to the left of mid.
        else {
            r = mid; 
        }
    }
    
    // 'l' and 'r' will converge to the minimum element index
    return a[l];
}

int main() {
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    cout << "The minimum element is: " << findMin(a) << endl; // Output: 0
    return 0;
}
