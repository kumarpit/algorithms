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

// why is this problem greedy?
// first key observation, sum(gas) >= sum(cost)

class Solution {
//     time limit exceeded
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i=0; i < gas.size(); i++) {
            
            int currGas = 0;
            int currStation = i;
            
            for (int j=0;  j < gas.size(); j++) {
                currGas += gas[currStation];
                
                if (currGas < cost[currStation]) break;
                currGas -= cost[currStation];
                
                currStation = getNext(gas.size(), currStation);
                if (currStation == i) return i;        
            }
        }
        
        return -1;
    }
    
private:
    int getNext(int size, int current) {
        return ++current % size;
    }
};

class SolutionGreedy {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n (gas.size()), sum (0), total (0), start (0);
        
        for (int i=0; i < n; i++) {
            sum += gas[i] - cost[i]; //diff
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
            total += gas[i] - cost[i]; //verifies if solution possible
        }
        
        return total >= 0 ? start : -1;
    }
};

int main() {
    Solution sol;
    vector<int> gas = {3,30,34,5,9};
    vector<int> cost = {100, 100, 100, 100, 100};
    cout << sol.canCompleteCircuit(gas, cost) << endl;
}