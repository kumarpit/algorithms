#include<iostream>
#include<vector>
#include<unordered_map>


/**
Write a function that takes in a targetSum and an array of integers and returns a boolean indicating whether it is possible to generate the targetSum from some combination of integers in the array. Note: Repeat numbers are allowed.
*/

using namespace std;

// O()
bool can_sum(int target, vector<int> nums, unordered_map<int, bool> &memo) {
    if (memo.count(target) > 0) return memo[target];
    if (target < 0) return false;
    if (target == 0) return true;

    for (int i=0; i < nums.size(); i++) {
        int remainder = target - nums[i];
        int possible = can_sum(remainder, nums, memo);
        if (possible) return true;
        else memo[remainder] = false;
    }

    memo[target] = false;
    return false;
}

int main() {
    vector<int> nums = {7, 14};
    unordered_map<int, bool> memo;
    cout << can_sum(300, nums, memo) << endl;
}