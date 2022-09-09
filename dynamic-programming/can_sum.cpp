#include<iostream>
#include<vector>


/**
Write a function that takes in a targetSum and an array of integers and returns a boolean indicating whether it is possible to generate the targetSum from some combination of integers in the array. Note: Repeat numbers are allowed.
*/

using namespace std;

// O(n^m)
bool can_sum(int target, vector<int> nums) {
    if (target < 0) return false;
    if (target == 0) return true;

    for (int i=0; i < nums.size(); i++) {
        int remainder = target - nums[i];
        int possible = can_sum(remainder, nums);
        if (possible) return true;
    }

    return false;
}

int main() {
    vector<int> nums = {8, 5};
    cout << can_sum(9, nums) << endl;
}