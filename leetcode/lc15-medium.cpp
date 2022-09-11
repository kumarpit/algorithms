#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>

// 3sum

using namespace std;

// I kept using j instead of nums[j]
// O(n^2) -- too slow
vector<vector<int>> threesome(vector<int> nums) {
    vector<vector<int>> res;
    set<set<int>> unique;
    unordered_set<int> seen;

    for (int i=0; i < nums.size() - 1; i++) {
        int target = nums[i];

        for (int j=i+1; j < nums.size(); j++) {
            int remainder = -target - nums[j];

            if (seen.count(remainder) > 0) {
                
                if (unique.insert({target, nums[j], remainder}).second) {
                    res.push_back({target, nums[j], remainder});
                }
            } else seen.insert(nums[j]);
        }

        seen.clear();
    }

    return res;
}

vector<vector<int>> faster_threesome() {
    // TODO AFTER ALL TWOSUM QUESTIONS
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    cout << threesome(nums).size() << endl;
}