#include<iostream>
#include<vector>

using namespace std;

// maximum sub-array
// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int left  = 0;
        int right = 0;
        int curr_sum = 0;
        int m = INT_MIN;
        
        for (int i=0; i < nums.size(); i++) {
            curr_sum += nums[right];
            right++;
            
            m = max(curr_sum, m);
            
            if (curr_sum < 0) {
                left = right;
                curr_sum = 0;
            }
        }
        
        return m;
    }
};

int main() {
    vector<int> nums = {-2, -2, -4, -4, -9, -1};
    Solution sol;
    cout << sol.maxSubArray(nums);
}