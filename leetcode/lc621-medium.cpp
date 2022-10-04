#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
    public:
        int least_interval(vector<char>& tasks,  int n) {
            if (n == 0) return tasks.size();
            
            int size = tasks.size();

            // map with char counts
            unordered_map<char, int> map;   
            for (int i=0; i < size; i++) {
                if (map.count(tasks[i])) map[tasks[i]]++;
                else map[tasks[i]] = 1;
            }

            // make a vector from this map to be used as a max heap
            vector<int> counts;
            for (auto m : map) {
                counts.push_back(m.second);
            }

            make_heap(counts.begin(), counts.end());
            queue<pair<int, int>> idle;

            int time = 0;
            while (counts.size() != 0 || idle.size() != 0) {
                
                if (counts.size() > 0) {
                    pop_heap(counts.begin(), counts.end());
                    int current = *(counts.end() - 1);
                    counts.pop_back();

                    current--;
                    if (current) idle.push({current, time + n});
                }
                
                if (idle.size() > 0 && idle.front().second == time) {
                    counts.push_back(idle.front().first);
                    push_heap(counts.begin(), counts.end());
                    idle.pop();
                }

                time++;
            }

            return time;
        }
};

// We have to assign each tasks such a way so that each task has cool down time period between them. 
// The finish time of all tasks will always depend on the task with max frequency when cool down period n > 0.
// If the max frequency of all task is maxFreq and their count is maxFreqCount then we can find the 
// finish time using the arithmetic interval formula easily. Let, we start from the time 1 assigning maxFreq
// task first. So, the last time of the maxFreq task will be => 1 + (maxFreq-1) * (n+1). Now if there is more than
// 1 maxFreq task then we can assign (maxFreqCount-1) tasks after each first maxFreq task and thus the finish
// time will be

// => 1 + (maxFreq-1) * (n+1) + (maxFreqCount-1)
// => (maxFreq-1) * (n+1) + maxFreqCount

// Now this formula can give us the finish time for tasks which has size less or equal the formula output,
// otherwise the tasks size will be the final finish time.
class SolutionFaster {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if(n==0)return tasks.size();
        
        int freq[26] = {0};
        int maxFreq = INT_MIN;
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
            maxFreq = max(maxFreq,freq[tasks[i]-'A']);
        }
        
        int maxFreqCount  = 0;
        for(int i=0;i<26;i++)if(freq[i]==maxFreq)maxFreqCount++;
        
        return max((int)tasks.size(),(maxFreq-1)*(n+1)+maxFreqCount);
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << sol.least_interval(tasks, 2);
}