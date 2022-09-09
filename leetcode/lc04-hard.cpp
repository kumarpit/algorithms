#include<iostream>
#include<limits>
#include<vector>

using namespace std;

// O(m+n)
double findMedian(vector<int> &nums1, vector<int> &nums2) {
    int curr1, curr2;
    curr1 = curr2 = 0;
    vector<int> merged;

    while(curr1 < nums1.size() || curr2 < nums2.size()) {
        if (curr1 >= nums1.size()) {
            merged.push_back(nums2[curr2]);
            curr2++;
        } else if (curr2 >= nums2.size()) {
            merged.push_back(nums1[curr1]);
            curr1++;
        } else if (nums1[curr1] < nums2[curr2]) {
            merged.push_back(nums1[curr1]);
            curr1++;
        } else {
            merged.push_back(nums2[curr2]);
            curr2++;
        }
    }

    int s = nums1.size() + nums2.size();

    if (s % 2 == 0) {
        return (((double)merged[s/2 - 1] + merged[s/2]) / 2);
    } else {
        return merged[(s-1)/2];
    }
}

int getLeft(vector<int> nums, int part) {
    if (part == 0) {
        return -numeric_limits<int>::max();
    } else {
        return nums[part - 1];
    }
}

int getRight(vector<int> nums, int part) {
    if (part == nums.size()) {
        return numeric_limits<int>::max();
    } else {
        return nums[part];
    }
}

// still O(m+n)
double findMedianFaster(vector<int> &nums1, vector<int> &nums2) {
    int lo, hi, combinedLength;
    lo = 0;
    hi = nums1.size();
    combinedLength = nums1.size() + nums2.size();

    while (lo <= hi) {
        int partX = (lo + hi) / 2;
        int partY = ((combinedLength + 1) / 2) - partX;

        int leftX = getLeft(nums1, partX);
        int leftY = getLeft(nums2, partY);
        int rightX = getRight(nums1, partX);
        int rightY = getRight(nums2, partY);

        if (leftX < rightY && leftY < rightX) {
            if (combinedLength % 2 == 0) {
                return (max(leftY, leftX) + min(rightY, rightX)) / 2.0;
            }
            return max(leftY, leftX);
        }

        if (leftX > rightY) {
            hi--;
        } else {
            lo++;
        }
    }

    return -1;

}

int main() {
    vector<int> nums1, nums2;

    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);

    double res = findMedianFaster(nums1, nums2);

    cout << res << endl;
}