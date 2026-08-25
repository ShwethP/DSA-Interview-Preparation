#include <bits/stdc++.h>
using namespace std;

bool canAllocate(
    const vector<int>& pages,
    int students,
    int maxPages
) {

    int studentsUsed = 1;
    int current = pages[0];

    for (int i = 1; i < pages.size(); i++) {

        if (current + pages[i] <= maxPages) {

            current = current + pages[i];
        }
        else{
            studentsUsed++;
            current = pages[i];
        }
    }
    // cout<< studentsUsed << ' '<<students<<endl;

    return studentsUsed <= students;
}

int minMaxPages(const vector<int>& pages, int students){

    if (students > pages.size()) {
    return -1;
}

    int l = *max_element(pages.begin(), pages.end());
    
    int r = accumulate(pages.begin(), pages.end(), 0);

     while (l <= r) {

        int mid = l + (r - l) / 2;

        if (canAllocate(pages, students , mid)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {

    vector<int> pages = {10,20, 30, 40};
    int students = 2;

    cout << minMaxPages(pages,students) << endl;

    return 0;
}