#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class SolutionCorrect {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        for (auto n : nums) {
            tmp.push_back(to_string(n));
        }
        
        sort(tmp.begin(), tmp.end(), [](string &s, string &t) -> bool { 
                return (s+t) > (t+s);
            });
        
        if (tmp[0] == "0") return "0";
        
        string res;
        
        for (auto s : tmp) {
            res += s;
        }
        
        return res;
    }
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int curr_most_sig = 0;
        string res = "";
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (!is_better_most_sig(nums[curr_most_sig], nums[i])) {
                res = to_string(nums[i]) + res;
                curr_most_sig = i;
            
            } else res = res + to_string(nums[i]);
        }
        
        return res;
    }

    // true if num1 is the better option
    // false if num2 is the better option
    bool is_better_most_sig(int num1, int num2) {
        if (num1 == num2) return true;

        int copy1, copy2;
        
        while (true) {
            copy1 = num1;
            copy2 = num2;
            
            if (copy1 == copy2) return true;
            
            while (copy1 >= 10) {
                copy1 = copy1 / 10;
            }

            while (copy2 >= 10) {
                copy2 = copy2 / 10;
            }

            if (copy1 == copy2) {
                num1 = removeFirst(num1);
                num2 = removeFirst(num2);
                continue;
            }
            
            
            return copy1 > copy2;
        }
    }
    
private:         
    int removeFirst(int n) {
        if (n < 10) {
            return n;
        }

        int tmp = 0;
        
        for (int i = 0;; ++i) {
            int m = n % 10;
            n /= 10;
            if (n != 0) {
                tmp += pow(10, i) * m;
            } else break;
        }
        
        return tmp;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,30,34,5,9};
    cout << sol.is_better_most_sig(3,30) << endl;
}