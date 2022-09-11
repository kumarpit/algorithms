#include<iostream>
#include<vector>
#include<unordered_map>

/**
Jump Game II

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/

using namespace std;

// works, but time complexity????
int jump(vector<int> nums, int curr, unordered_map<int, int> &memo) {
    if (memo.count(curr) > 0) return memo[curr];
    if (curr >= nums.size() - 1) return 0;
    
    int least = -1;
    
    for (int i=nums[curr]; i >= 1; i--) {
        int num_jumps = jump(nums, curr + i, memo);
        
        if (num_jumps >= 0) {
            if (least == -1) least = 1 + num_jumps;
            else least = min(least, 1 + num_jumps);
        };
    }
    
    memo[curr] = least;
    return least;
}

int main() {
    unordered_map<int, int> map;
    vector<int> ints = {3,2,1,0,4};
    cout << jump(ints, 0, map) << endl;
}