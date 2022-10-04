#include<iostream>
#include<vector>
#include<map>

using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    map<int, int> m{{0,0}};
    
    for (int i = 0; i < difficulty.size(); i++) // create the difficulty-maximum-profit BST
        m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
    
    int mx = 0, res = 0;
    
    for (auto &p : m) // update the BST to reflect the maximum profit for a job
        mx = p.second = max(p.second, mx);

    for (int w : worker) // look up the BST to find the maximum profit for each worker
        res += prev(m.upper_bound(w))->second;

    return res;
}

// TLE
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int> pd;
        
        for (int i=0; i < profit.size(); i++) {
            if (pd.count(profit[i]) > 0) {
                pd[profit[i]] = min(difficulty[i], pd[profit[i]]);
            } else {
                pd[profit[i]] = difficulty[i];
            }
        };
        
        int sum = 0;
        
        for (int i=0; i < worker.size(); i++) {
            map<int, int>::reverse_iterator it = pd.rbegin();
            
            while (it != pd.rend()) {
                
                if (it->second <= worker[i]) {
                    sum += it->first;  
                    break;
                }
                
                it++;
            }
        }
        
        return sum;
    }
};

int main() {
    Solution sol;   
}