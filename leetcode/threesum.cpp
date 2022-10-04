#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for (int i=0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left  = i+1;
            int right = nums.size() - 1;
            
            while (left < right) {
                
                int sum = nums[i] + nums[right] + nums[left];
                
                if (sum < 0) left++;
                if (sum > 0) right--;
                
                if (sum == 0) {    
                    vector<int> found = {nums[i], nums[left], nums[right]};
                    res.push_back(found);                
                    left++;
                    while (nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }
                
            }
        }
        
        return res;
    }
};