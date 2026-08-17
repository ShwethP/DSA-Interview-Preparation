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
    
    while (l <= r) {
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
    
    // 'l' and 'r' will converge to the minimum element index is nothing but roation number
    return l;
}

int main() {
    // is a rotated sorted array, how many times was it rotated? 4 times so index of minimum is the naswer
    vector<int> a = { 5, 6, 7, 0, 1, 2};
    cout << "The given array is rotated: " << findMin(a) <<" times"<< endl; // Output: 0
    return 0;
}
