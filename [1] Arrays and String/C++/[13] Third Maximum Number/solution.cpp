#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int thirdMax(vector<int>& nums) {
    // Use long long to handle the case where INT_MIN is in the input
    long long first = -2200000000LL; 
    long long second = -2200000000LL;
    long long third = -2200000000LL;

    for (int n : nums) {
        // Skip if we've already recorded this distinct number
        if (n == first || n == second || n == third) continue;

        if (n > first) {
            third = second;
            second = first;
            first = n;
        } else if (n > second) {
            third = second;
            second = n;
        } else if (n > third) {
            third = n;
        }
    }

    // If third was never updated, return the first max per rules
    return (third == -2200000000LL) ? (int)first : (int)third;
}

int main() {
    vector<int> nums = {2, 2, 3, 1};
    cout << "Output: " << thirdMax(nums) << endl; // Expected: 1
    return 0;
}
